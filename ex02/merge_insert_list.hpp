/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_insert_list.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:04:36 by yena              #+#    #+#             */
/*   Updated: 2023/10/23 14:30:31 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yejin Na on 10/19/23.
//

#ifndef CPP09_MERGE_INSERT_LIST_HPP
#define CPP09_MERGE_INSERT_LIST_HPP

#include "PmergeMe.hpp"

std::list<std::pair<int, int> > makePairsList(std::list<int> list);
void insertionSortList(std::list<int> &list, int element);
void binarySearchList(std::list<int> &list, int element);
void recursiveSortList(std::list<std::pair<int, int> > &list, unsigned long index);
std::list<int> sortPairList(std::list<int> list,
                            std::list<std::pair<int, int> > pair_list);
void printList(std::list<int> list);
double sortList(std::list<int> list);

#endif //CPP09_MERGE_INSERT_LIST_HPP
