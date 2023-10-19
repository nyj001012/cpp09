/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_insert_vector.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:42:48 by yena              #+#    #+#             */
/*   Updated: 2023/10/19 20:03:21 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yejin Na on 10/19/23.
//

#ifndef CPP09_MERGE_INSERT_VECTOR_HPP
#define CPP09_MERGE_INSERT_VECTOR_HPP

#include "PmergeMe.hpp"

std::vector<std::pair<int, int> > make_pairs_vector(std::vector<int> vector);
void insertion_sort_vector(std::vector<int> *vector, int element);
void binary_search_vector(std::vector<int> *vector, int element);
void recursive_sort_vector(std::vector<std::pair<int, int> > *vector,
                           int index);
td::vector<int> sort_pair_vector(std::vector<int> vector,
                                 std::vector<std::pair<int, int> > pair_vector);
void printVector(std::vector<int> vector);
double sortVector(std::vector<int> vector);

#endif //CPP09_MERGE_INSERT_VECTOR_HPP
