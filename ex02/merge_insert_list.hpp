/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_insert_list.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:20:32 by yena              #+#    #+#             */
/*   Updated: 2023/12/06 15:35:20 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by 나예진 on 2023/12/06.
//

#ifndef CPP09_EX02_MERGE_INSERT_LIST_HPP_
#define CPP09_EX02_MERGE_INSERT_LIST_HPP_

#include "PmergeMe.hpp"

std::list<std::pair<int, int> > makePairsList(std::list<int> list);
void insertionSortList(std::list<int> &list, int element);
void binarySearchList(std::list<int> &list, int element, int left, int right);
void mergeList(std::list<std::pair<int, int> > &list,
               std::list<std::pair<int, int> > &left_list,
               std::list<std::pair<int, int> > &right_list);
void recursiveMergeSortList(std::list<std::pair<int, int> > &list,
                            unsigned long left, unsigned long right);
std::list<int> sortPairList(std::list<int> list,
                            std::list<std::pair<int, int> > pair_list);
void printList(std::list<int> list);
double sortList(std::list<int> list);

#endif //CPP09_EX02_MERGE_INSERT_LIST_HPP_
