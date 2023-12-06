/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:09:16 by yena              #+#    #+#             */
/*   Updated: 2023/12/06 15:59:44 by yena             ###   ########.fr       */
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
  void calculateBitcoinData(std::string file_name, std::map<std::string, float> data);
  void printPrice(std::string date, float count, std::map<std::string, float> data);
};

#endif //EX00__BITCOINEXCHANGE_HPP_
