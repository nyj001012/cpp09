/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:02:21 by yena              #+#    #+#             */
/*   Updated: 2023/10/19 17:46:03 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by 나예진 on 2023/10/16.
//

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> vector, std::list<int> list,
                   int element_count) {
  this->_vector = vector;
  this->_list = list;
  this->_element_count = element_count;
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

std::vector<int> PmergeMe::getVector() const { return this->_vector; }

std::list<int> PmergeMe::getList() const { return this->_list; }

int PmergeMe::getElementCount() const { return this->_element_count; }

void PmergeMe::setVector(std::vector<int> vector) { this->_vector = vector; }

void PmergeMe::setList(std::list<int> list) { this->_list = list; }

void PmergeMe::setElementCount(int element_count) {
  this->_element_count = element_count;
}

// TODO => 벡터와 리스트 정렬 파일 분리

/**
 * 벡터의 원소를 큰 것과 작은 것으로 이루어진 쌍(pair)의 벡터로 나눈다.
 * 만약 원소의 개수가 홀수라면 마지막 원소는 (vector[size - 1], 0)으로 채워진다.
 * @param vector 벡터
 * @param bigger
 * @param smaller
 * @return
 */
std::vector<std::pair<int, int> > divide_into_bigger_smaller(
    std::vector<int> vector) {
  int size = vector.size() % 2 == 1 ? vector.size() - 1 : vector.size();
  std::vector<std::pair<int, int> > pair_vector;

  if (vector.size() % 2 == 1) vector.push_back(0);
  for (int i = 0; i < size; i += 2) {
    if (vector[i] > vector[i + 1]) {
      std::pair<int, int> pair = std::make_pair(vector[i], vector[i + 1]);
      pair_vector.push_back(pair);
    } else {
      std::pair<int, int> pair = std::make_pair(vector[i + 1], vector[i]);
      pair_vector.push_back(pair);
    }
  }
  return pair_vector;
}

void insertion_sort_vector(std::vector<int> *vector, int element) {
  for (int i = 0; i < vector->size(); i++) {
    if (vector->at(i) > element) {
      vector->insert(vector->begin() + i, element);
      break;
    }
  }
}

void binary_search_vector(std::vector<int> *vector, int element) {
  int left = 0;
  int right = vector->size() - 1;
  int mid;

  while (left <= right) {
    mid = (left + right) / 2;
    if (vector->at(mid) < element) {
      left = mid + 1;
    } else if (vector->at(mid) > element) {
      right = mid - 1;
    }
  }
  vector->insert(vector->begin() + left, element);
}

void recursive_sort_vector(std::vector<std::pair<int, int> > *vector,
                           int index) {
  if (index == vector->size() - 1) {
    return;
  }
  if (vector->at(index) > vector->at(index + 1)) {
    std::swap(vector->at(index), vector->at(index + 1));
  }
  recursive_sort_vector(vector, index + 1);
}

std::vector<int> sort_pair(std::vector<int> vector,
                           std::vector<std::pair<int, int> > pair_vector) {
  recursive_sort_vector(&pair_vector, 0);
  std::vector<int> sorted_vector;

  for (int i = 0; i < pair_vector.size(); i++) {
    sorted_vector.push_back(pair_vector[i].first);
  }
  sorted_vector.insert(sorted_vector.begin(), pair_vector[0].second);
  for (int i = 1; i < pair_vector.size(); i++) {
    insertion_sort_vector(&sorted_vector, pair_vector[i].second);
  }
  if (vector.size() % 2 == 1) {
    binary_search_vector(&sorted_vector, vector[vector.size() - 1]);
  }
  return sorted_vector;
}

void printVector(std::vector<int> vector) {
  std::cout << "- std::vector:\t";
  for (int i = 0; i < vector.size(); i++) {
    std::cout << vector[i] << " ";
  }
  std::cout << std::endl;
}

/**
 * sort vector with Ford-Johnson algorithm
 * @param vector
 * @return
 */
double sortVector(std::vector<int> vector) {
  std::vector<std::pair<int, int> > pair_vector;
  std::vector<int> sorted_vector;
  clock_t start, end;
  float time;

  start = clock();
  pair_vector = divide_into_bigger_smaller(vector);
  sorted_vector = sort_pair(vector, pair_vector);
  end = clock();
  time = static_cast<double>(end - start);
  printVector(sorted_vector);
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
  std::cout << "Time to process a range of\t" << this->getElementCount()
            << " elements with " << data_type << "\t: " << time << " ms"
            << std::endl;
}
