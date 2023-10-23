/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:02:21 by yena              #+#    #+#             */
/*   Updated: 2023/10/19 21:45:13 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by 나예진 on 2023/10/16.
//

#ifndef EX02__PMERGEME_HPP_
#define EX02__PMERGEME_HPP_

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include "font.hpp"
#include "merge_insert_vector.hpp"
#include "merge_insert_deque.hpp"

class PmergeMe {
 public:
  PmergeMe();
  PmergeMe(std::vector<int> vector, std::deque<int> deque, int element_count);
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();
  std::vector<int> getVector() const;
  std::deque<int> getDeque() const;
  int getElementCount() const;
  void setVector(std::vector<int> v);
  void setDeque(std::deque<int> l);
  void setElementCount(int element_count);
  void sort();
  void printResult(std::string data_type, double time) const;

 private:
  std::vector<int> _vector;
  std::deque<int> _deque;
  int _element_count;
};

#endif //EX02__PMERGEME_HPP_
