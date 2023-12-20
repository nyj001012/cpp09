/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:10:42 by yena              #+#    #+#             */
/*   Updated: 2023/10/15 15:16:02 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by 나예진 on 2023/10/15.
//

#include "Database.hpp"

Database::Database() {}

Database::Database(const Database &copy) {
  if (this != &copy)
    *this = copy;
}

Database &Database::operator=(const Database &copy) {
  if (this != &copy) {
  }
  return *this;
}

Database::~Database() {}

/**
 * 비트코인 시세표를 읽어온다.
 * @return std::map<std::string, float>
 */
std::map<std::string, float> Database::readDatabase() {
  std::ifstream ifs("data.csv");
  std::map<std::string, float> data;
  std::string line;

  if (!ifs.is_open())
    throw std::runtime_error("Error: could not open file.");
  std::getline(ifs, line);
  while (std::getline(ifs, line)) {
    std::string key = line.substr(0, line.find(","));
    std::string value = line.substr(line.find(",") + 1, line.length());
    if (key.empty() || value.empty()) {
      ifs.close();
      throw std::runtime_error("Error: invalid file format.");
    }
    float f_value = static_cast<float>(std::strtod(value.c_str(), NULL));
    data.insert(std::pair<std::string, float>(key, f_value));
  }
  ifs.close();
  return data;
}
