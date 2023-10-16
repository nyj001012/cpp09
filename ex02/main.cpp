/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:56:27 by yena              #+#    #+#             */
/*   Updated: 2023/10/16 14:47:47 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void printInfo(int argc, char *argv[]) {
  std::vector<int> argv_vector;

  std::cout << "Before:\t";
  for (int i = 1; i < argc; i++) {
    std::cout << argv[i] << " ";
    argv_vector.push_back(std::stoi(argv[i]));
  }
  std::cout << std::endl;
  std::cout << "After:\t";
  std::sort(argv_vector.begin(), argv_vector.end());
  for (int i = 0; i < argv_vector.size(); i++) {
    std::cout << argv_vector[i] << " ";
  }
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    std::cout << F_RED
              << "Error: Wrong number of arguments"
              << FB_DEFAULT << std::endl;
  } else {
    std::vector<int> argv_vector;
    std::list<int> argv_list;
    for (int i = 1; i < argc; i++) {
      argv_vector.push_back(std::stoi(argv[i]));
      argv_list.push_back(std::stoi(argv[i]));
    }
    PmergeMe pmergeMe(argv_vector, argv_list);
    pmergeMe.sort();
  }
  return 0;
}
