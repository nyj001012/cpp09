/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:56:27 by yena              #+#    #+#             */
/*   Updated: 2023/10/23 17:52:26 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void printInfo(int argc, char *argv[]) {
  std::vector<int> argv_vector;

  std::cout << "Before:\t";
  for (int i = 1; i < argc; i++) {
    std::cout << argv[i] << " ";
    argv_vector.push_back(std::strtod(argv[i], nullptr));
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
    printInfo(argc, argv);
    std::vector<int> argv_vector;
    std::list<int> argv_list;
    for (int i = 1; i < argc; i++) {
      argv_vector.push_back(std::strtod(argv[i], nullptr));
      argv_list.push_back(std::strtod(argv[i], nullptr));
    }
    PmergeMe pmergeMe(argv_vector, argv_list, argc - 1);
    pmergeMe.sort();
  }
  return 0;
}
