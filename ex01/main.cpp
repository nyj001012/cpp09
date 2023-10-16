/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:15:59 by yena              #+#    #+#             */
/*   Updated: 2023/10/16 13:54:31 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char *argv[]) {
  if (argc == 2) {
    RPN rpn;
    try {
      rpn.run(std::string(argv[1]));
    } catch (std::exception &e) {
      std::cout << F_RED << e.what() << FB_DEFAULT << std::endl;
    }
  } else {
    std::cout << F_RED
              << "Error: Wrong number of arguments."
              << FB_DEFAULT << std::endl;
  }
  return 0;
}
