/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:09:16 by yena              #+#    #+#             */
/*   Updated: 2023/12/06 16:10:31 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by 나예진 on 2023/10/15.
//

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
  if (this != &other)
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other) {
  }
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

/**
 * 날짜가 유효한지 검사한다.
 * @param year 년도
 * @param month 월
 * @param day 일
 * @return true or false
 */
bool isValidDate(std::string year, std::string month, std::string day) {
  int i_year = std::atoi(year.c_str());
  int i_month = std::atoi(month.c_str());
  int i_day = std::atoi(day.c_str());
  int days_per_month[12] = {31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31};

  if (i_year < 2009)
    return false;
  if (i_month < 1 || i_month > 12)
    return false;
  if ((i_year % 4 == 0 && i_year % 100 != 0) || i_year % 400 == 0)
    days_per_month[1] = 29;
  if (i_day < 1 || i_day > days_per_month[i_month - 1])
    return false;
  return true;
}

/**
 * 날짜의 형식이 올바른지 검사한다.
 * @param date 날짜
 * @return true or false
 */
bool isValidDateFormat(std::string date) {
  std::string year = date.substr(0, 4);
  std::string month = date.substr(5, 2);
  std::string day = date.substr(8, 2);

  if (date.length() != 10)
    return false;
  if (date[4] != '-' || date[7] != '-')
    return false;
  if (!std::strtol(year.c_str(), NULL, 10) ||
      !std::strtol(month.c_str(), NULL, 10) ||
      !std::strtol(day.c_str(), NULL, 10))
    return false;
  if (!isValidDate(year, month, day))
    return false;
  return true;
}

/**
 * 비트코인 구입 날짜와 구입 개수를 입력받아 가격을 출력한다.
 * @param file_name 비트코인 구입 날짜와 구입 개수가 저장된 파일 이름
 */
void BitcoinExchange::calculateBitcoinData(std::string file_name, std::map<std::string, float> data) {
  std::ifstream ifs(file_name);
  std::string line;

  if (!ifs.is_open())
    throw std::runtime_error("Error: file not found");
  std::getline(ifs, line);
  while (std::getline(ifs, line)) {
    std::string key = line.substr(0, line.find(" | "));
    std::string value = line.substr(line.find(" | ") + 3);
    if (key.empty() || value.empty()) {
      ifs.close();
      throw std::runtime_error("Error: invalid file format");
    }
    float f_value = static_cast<float>(std::strtod(value.c_str(), NULL));
    this->printPrice(key, f_value, data);
  }
  ifs.close();
}

/**
 * 비트코인의 시세에 따른 가격을 계산한다. 만약 시세표에 없는 날짜라면 가장 가까운 이전 날짜의 가격을 사용한다.
 * @param date 비트코인 구입 날짜
 * @param count 비트코인 구입 개수
 * @param data 비트코인 시세표
 * @return 비트코인 가격
 */
float calculatePrice(std::string date, float count, std::map<std::string, float> data) {
  float price = 0;

  if (data.find(date) != data.end()) {
    price = data[date] * count;
  } else {
    std::map<std::string, float>::iterator it = data.lower_bound(date);
    if (it == data.end())
      throw std::runtime_error("Error: no data");
    it--;
    price = it->second * count;
  }
  if (price < 0)
    throw std::runtime_error("Error: not a positive number");
  if (price > 1000)
    throw std::runtime_error("Error: too large a number");
  return price;
}

/**
 * "input.txt의 date => input.txt의 count = price"의 형식으로 출력한다.
 * @param data 비트코인 시세표
 */
void BitcoinExchange::printPrice(std::string date, float count, std::map<std::string, float> data) {
  try {
    if (!isValidDateFormat(date))
      throw std::runtime_error("Error: bad input => " + date);
    float price = calculatePrice(date, count, data);
    std::cout << date << " => " << count << " = " << price << std::endl;
  } catch (std::exception &e) {
    std::cout << F_RED << e.what() << FB_DEFAULT << std::endl;
  }
}
