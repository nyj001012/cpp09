/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:06:29 by yena              #+#    #+#             */
/*   Updated: 2023/10/15 15:03:47 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Database.hpp"
#include "BitcoinExchange.hpp"
#include "font.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << F_RED << "Error: could not open file." << FB_DEFAULT << std::endl;
    return 1;
  }
  try {
    BitcoinExchange exchanger;
    std::map<std::string, float> data = Database::readDatabase();
    exchanger.readBitcoinData(argv[1]);
    exchanger.printPrice(data);
  } catch (std::exception &e) {
    std::cout << F_RED << e.what() << FB_DEFAULT << std::endl;
  }
  return 0;
}
