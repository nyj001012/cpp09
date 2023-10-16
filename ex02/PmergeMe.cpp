/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:02:21 by yena              #+#    #+#             */
/*   Updated: 2023/10/16 15:13:11 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by 나예진 on 2023/10/16.
//

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> vector, std::list<int> list) {
  this->_vector = vector;
  this->_list = list;
}

PmergeMe::PmergeMe(const PmergeMe &other) {
  if (this != &other) {
    this->_vector = other._vector;
    this->_list = other._list;
  }
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (this != &other) {
    this->_vector = other._vector;
    this->_list = other._list;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::getVector() const {
  return this->_vector;
}

std::list<int> PmergeMe::getList() const {
  return this->_list;
}

int PmergeMe::getElementCount() const {
  return this->_element_count;
}

void PmergeMe::setVector(std::vector<int> vector) {
  this->_vector = vector;
}

void PmergeMe::setList(std::list<int> list) {
  this->_list = list;
}

void PmergeMe::setElementCount(int element_count) {
  this->_element_count = element_count;
}

/**
 * sort vector with Ford-Johnson algorithm
 * @param vector
 * @return
 */
double sortVector(std::vector<int> vector) {
  clock_t start, end;
  float time;

  start = clock();

  end = clock();
  time = static_cast<double>(end - start);
  return time;
}

/**
 * sort list with Ford-Johnson algorithm
 * @param list
 * @return
 */
double sortList(std::list<int> list) {
  clock_t start, end;
  double time;

  start = clock();
  list.sort();
  end = clock();
  time = static_cast<double>(end - start);
  return time;
}

void PmergeMe::sort() {
  double vector_time = sortVector(this->getVector());
  double list_time = sortList(this->getList());
  this->printResult("std::vector", vector_time);
  this->printResult("std::list", list_time);
}

void PmergeMe::printResult(std::string data_type, double time) const {
  std::cout << "Time to process a range of\t"
            << this->getElementCount()
            << " elements with "
            << data_type
            << "\t: "
            << time
            << " ms"
            << std::endl;
}
