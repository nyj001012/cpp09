/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:02:21 by yena              #+#    #+#             */
/*   Updated: 2023/10/23 18:38:42 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by 나예진 on 2023/10/16.
//

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> vector, std::deque<int> deque,
                   int element_count) {
  this->_vector = vector;
  this->_deque = deque;
  this->_element_count = element_count;
}

PmergeMe::PmergeMe(const PmergeMe &other) {
  if (this != &other) {
    this->_vector = other._vector;
    this->_deque = other._deque;
  }
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (this != &other) {
    this->_vector = other._vector;
    this->_deque = other._deque;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::getVector() const { return this->_vector; }

std::deque<int> PmergeMe::getDeque() const { return this->_deque; }

int PmergeMe::getElementCount() const { return this->_element_count; }

void PmergeMe::setVector(std::vector<int> vector) { this->_vector = vector; }

void PmergeMe::setDeque(std::deque<int> deque) { this->_deque = deque; }

void PmergeMe::setElementCount(int element_count) {
  this->_element_count = element_count;
}

void PmergeMe::sort() {
  double vector_time = sortVector(this->getVector());
  double deque_time = sortDeque(this->getDeque());
  this->printResult("std::vector", vector_time);
  this->printResult("std::deque", deque_time);
}

void PmergeMe::printResult(std::string data_type, double time) const {
  std::cout << "Time to process a range of\t" << this->getElementCount()
            << " elements with " << data_type << "\t: " << time << " ms"
            << std::endl;
}
