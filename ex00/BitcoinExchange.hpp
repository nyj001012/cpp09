/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:09:16 by yena              #+#    #+#             */
/*   Updated: 2023/10/15 15:01:24 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by 나예진 on 2023/10/15.
//

#ifndef EX00__BITCOINEXCHANGE_HPP_
#define EX00__BITCOINEXCHANGE_HPP_

#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include "font.hpp"

class BitcoinExchange {
 public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);
  ~BitcoinExchange();
  void setBitcoinData(std::string key, float value);
  std::multimap<std::string, float> getBitcoinData();
  void readBitcoinData(std::string file_name);
  void printPrice(std::map<std::string, float> data);

 private:
  std::multimap<std::string, float> _bitcoin_data;
};

#endif //EX00__BITCOINEXCHANGE_HPP_
