/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_insert_vector.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:42:48 by yena              #+#    #+#             */
/*   Updated: 2023/10/23 13:55:39 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yejin Na on 10/19/23.
//

#ifndef CPP09_MERGE_INSERT_VECTOR_HPP
#define CPP09_MERGE_INSERT_VECTOR_HPP

#include "PmergeMe.hpp"

std::vector<std::pair<int, int> > makePairsVector(std::vector<int> vector);
void insertionSortVector(std::vector<int> *vector, int element);
void binarySearchVector(std::vector<int> *vector, int element);
void recursiveSortVector(std::vector<std::pair<int, int> > *vector,
                         unsigned long index);
std::vector<int> sortPairVector(std::vector<int> vector,
                                std::vector<std::pair<int, int> > pair_vector);
void printVector(std::vector<int> vector);
double sortVector(std::vector<int> vector);

#endif //CPP09_MERGE_INSERT_VECTOR_HPP
