/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:02:21 by yena              #+#    #+#             */
/*   Updated: 2023/10/16 16:58:40 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by 나예진 on 2023/10/16.
//

#ifndef EX02__PMERGEME_HPP_
#define EX02__PMERGEME_HPP_

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "font.hpp"

class PmergeMe {
 public:
  PmergeMe();
  PmergeMe(std::vector<int> vector, std::list<int> list, int element_count);
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();
  std::vector<int> getVector() const;
  std::list<int> getList() const;
  int getElementCount() const;
  void setVector(std::vector<int> v);
  void setList(std::list<int> l);
  void setElementCount(int element_count);
  void sort();
  void printResult(std::string data_type, double time) const;

 private:
  std::vector<int> _vector;
  std::list<int> _list;
  int _element_count;
};

#endif //EX02__PMERGEME_HPP_
