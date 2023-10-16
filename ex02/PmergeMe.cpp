/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:02:21 by yena              #+#    #+#             */
/*   Updated: 2023/10/16 14:51:28 by yena             ###   ########.fr       */
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

void PmergeMe::setVector(std::vector<int> vector) {
  this->_vector = vector;
}

void PmergeMe::setList(std::list<int> list) {
  this->_list = list;
}
