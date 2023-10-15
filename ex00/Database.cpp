/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:10:42 by yena              #+#    #+#             */
/*   Updated: 2023/10/15 15:03:57 by yena             ###   ########.fr       */
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
  return *this;
}

Database::~Database() {}

std::map<std::string, float> Database::readDatabase() {
  std::ifstream ifs("data.csv");
  std::map<std::string, float> data;
  std::string line;
  std::string key;
  std::string value;

  if (!ifs.is_open())
    throw std::runtime_error("Error: could not open file.");
  std::getline(ifs, line);
  while (std::getline(ifs, line)) {
    key = line.substr(0, line.find(","));
    value = line.substr(line.find(",") + 1, line.length());
    if (key.empty() || value.empty()) {
      ifs.close();
      throw std::runtime_error("Error: invalid file format.");
    }
    data.insert(std::pair<std::string, float>(key, std::stod(value)));
  }
  ifs.close();
  return data;
}
