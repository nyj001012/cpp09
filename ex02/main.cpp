/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:56:27 by yena              #+#    #+#             */
/*   Updated: 2023/12/06 15:26:00 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "utils.hpp"

void printInfo(int argc, char *argv[]) {
  std::vector<int> argv_vector;

  std::cout << "Before:\t";
  for (int i = 1; i < argc; i++) {
    std::cout << argv[i] << " ";
    argv_vector.push_back(std::atoi(argv[i]));
  }
  std::cout << std::endl;
  std::cout << "After:\t";
  std::sort(argv_vector.begin(), argv_vector.end());
  for (unsigned long i = 0; i < argv_vector.size(); i++) {
    std::cout << argv_vector[i] << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    std::cout << F_RED
              << "Error: Wrong number of arguments"
              << FB_DEFAULT << std::endl;
  } else {
    try {
      std::vector<int> argv_vector;
      std::deque<int> argv_deque;
      std::list<int> argv_list;
      for (int i = 1; i < argc; i++) {
        if (isInt(argv[i]) == false)
          throw std::invalid_argument("Put integer only");
        argv_vector.push_back(std::atoi(argv[i]));
        argv_deque.push_back(std::atoi(argv[i]));
        argv_list.push_back(std::atoi(argv[i]));
      }
      printInfo(argc, argv);
      PmergeMe pmergeMe(argv_vector, argv_deque, argv_list, argc - 1);
      pmergeMe.sort();
    } catch (std::exception &e) {
      std::cout << F_RED
                << "Error: " << e.what()
                << FB_DEFAULT << std::endl;
    }
    return 0;
  }
}
