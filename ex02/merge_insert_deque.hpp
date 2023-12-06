/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_insert_deque.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:58:43 by yena              #+#    #+#             */
/*   Updated: 2023/12/06 15:46:44 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yejin Na on 10/19/23.
//

#ifndef CPP09_MERGE_INSERT_LIST_HPP
#define CPP09_MERGE_INSERT_LIST_HPP

#include "PmergeMe.hpp"

std::deque<std::pair<int, int> > makePairsDeque(std::deque<int> deque);
void insertionSortDeque(std::deque<int> &deque, int element);
void binarySearchDeque(std::deque<int> &deque, int element, int left, int right);
void mergeDeque(std::deque<std::pair<int, int> > &deque,
               std::deque<std::pair<int, int> > &left_deque,
               std::deque<std::pair<int, int> > &right_deque);
void recursiveMergeSortDeque(std::deque<std::pair<int, int> > &deque,
                            unsigned long left, unsigned long right);
std::deque<int> sortPairDeque(std::deque<int> deque,
                            std::deque<std::pair<int, int> > pair_deque);
void printDeque(std::deque<int> deque);
double sortDeque(std::deque<int> deque);

#endif //CPP09_MERGE_INSERT_LIST_HPP
