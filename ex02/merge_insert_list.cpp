/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_insert_list.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:04:36 by yena              #+#    #+#             */
/*   Updated: 2023/10/23 17:46:32 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yejin Na on 10/19/23.
//

#include "merge_insert_list.hpp"

/**
 * 리스트의 원소를 큰 것과 작은 것으로 이루어진 쌍(pair)의 리스트로 나눈다.
 * 만약 원소의 개수가 홀수라면 마지막 원소는 쌍을 이루지 않는다.
 * @param list 리스트
 * @return 짝으로 이루어진 리스트
 */
std::list<std::pair<int, int> > makePairsList(std::list<int> list) {
  std::list<std::pair<int, int> > pair_list;
  std::list<int>::iterator it;
  unsigned int size = list.size() % 2 == 1 ? list.size() - 1 : list.size();
  unsigned int i = 0;

  for (it = list.begin(); i < size; i += 2, it++) {
    std::list<int>::iterator prev_it = it;
    std::advance(it, 1);
    if (*prev_it > *it) {
      std::pair<int, int> pair = std::make_pair(*prev_it, *it);
      pair_list.push_back(pair);
    } else {
      std::pair<int, int> pair = std::make_pair(*it, *prev_it);
      pair_list.push_back(pair);
    }
  }
  return pair_list;
}

/**
 * 삽입 정렬을 실행한다.
 * @param list 정렬될 리스트
 * @param element 정렬할 원소
 */
void insertionSortList(std::list<int> &list, int element) {
  for (std::list<int>::iterator it = list.begin(); it != list.end(); it++) {
    if (*it > element) {
      list.insert(it, element);
      break;
    }
  }
}

/**
 * 이진 탐색하여 원소를 알맞은 자리에 insert한다.
 * @param list 정렬될 리스트
 * @param element 정렬할 원소
 */
void binarySearchList(std::list<int> &list, int element) {
  int left = 0;
  int right = list.size() - 1;
  int mid;
  std::list<int>::iterator it;

  while (left <= right) {
    it = list.begin();
    mid = (left + right) / 2;
    std::advance(it, mid);
    if (*it < element) {
      left = mid + 1;
    } else if (*it > element) {
      right = mid - 1;
    }
  }
  std::advance(it, left);
  list.insert(it, element);
}

/**
 * 두 리스트를 list에 병합한다. 이는 recursiveMergeSortList에서 호출된다.
 * @param list 병합 결과 리스트
 * @param left_list 왼쪽 리스트
 * @param right_list 오른쪽 리스트
 */
void mergeList(std::list<std::pair<int, int> > &list,
               std::list<std::pair<int, int> > &left_list,
               std::list<std::pair<int, int> > &right_list) {
  std::list<std::pair<int, int> >::iterator it = list.begin();
  std::list<std::pair<int, int> >::iterator left_it = left_list.begin();
  std::list<std::pair<int, int> >::iterator right_it = right_list.begin();

  while (left_it != left_list.end() && right_it != right_list.end()) {
    if (left_it->first <= right_it->first) {
      *it = *left_it;
      left_it++;
    } else {
      *it = *right_it;
      right_it++;
    }
    it++;
  }
  while (left_it != left_list.end()) {
    *it = *left_it;
    left_it++;
    it++;
  }
  while (right_it != right_list.end()) {
    *it = *right_it;
    right_it++;
    it++;
  }
}

/**
 * 만약 한 쌍의 첫 번째 원소(larger)를 기준으로 재귀를 이용하여 오름차순 정렬한다.
 * @param list 정렬될 리스트
 * @param index 리스트의 위치를 나타내는 인덱스
 */
void recursiveMergeSortList(std::list<std::pair<int, int> > &list,
                            unsigned long left, unsigned long right) {
  if (left >= right)
    return;
  unsigned long mid = left + (right - left) / 2;
  std::list<std::pair<int, int> >::iterator left_it = list.begin();
  std::list<std::pair<int, int> >::iterator mid_it = list.begin();
  std::list<std::pair<int, int> >::iterator right_it = list.begin();
  std::advance(left_it, left);
  std::advance(mid_it, mid + 1);
  std::advance(right_it, right + 1);
  std::list<std::pair<int, int> > left_list(left_it, mid_it);
  std::list<std::pair<int, int> > right_list(mid_it, right_it);

  recursiveMergeSortList(left_list, 0, left_list.size() - 1);
  recursiveMergeSortList(right_list, 0, right_list.size() - 1);
  mergeList(list, left_list, right_list);
}

/**
 * 리스트 쌍을 정렬한다.
 * @param list 정렬될 리스트
 * @param pair_list 정수로 이루어진 쌍들의 리스트
 * @return 정렬된 리스트
 */
std::list<int> sortPairList(std::list<int> list,
                            std::list<std::pair<int, int> > pair_list) {
  recursiveMergeSortList(pair_list, 0, pair_list.size() - 1);
  std::list<int> sorted_list;

  for (std::list<std::pair<int, int> >::iterator it = pair_list.begin(); it != pair_list.end(); it++) {
    sorted_list.push_back(it->first);
  }
  sorted_list.insert(sorted_list.begin(), pair_list.begin()->second);
  for (std::list<std::pair<int, int> >::iterator it = ++pair_list.begin(); it != pair_list.end(); it++) {
    insertionSortList(sorted_list, it->second);
  }
  if (list.size() % 2 == 1) {
    std::list<int>::iterator last_it = list.begin();
    std::advance(last_it, list.size() - 1);
    binarySearchList(sorted_list, *last_it);
  }
  return sorted_list;
}

/**
 * 리스트를 출력한다.
 * @param list
 */
void printList(std::list<int> list) {
  std::cout << "- std::list:\t";
  for (std::list<int>::iterator it = list.begin(); it != list.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

/**
 * merge-insert 정렬을 이용하여 리스트를 오름차순 정렬한다.
 * @param list 정렬할 리스트
 * @return 정렬하는 데 걸린 시간
 */
double sortList(std::list<int> list) {
  std::list<std::pair<int, int> > pair_list;
  std::list<int> sorted_list;
  clock_t start, end;
  float time;

  start = clock();
  pair_list = makePairsList(list);
  sorted_list = sortPairList(list, pair_list);
  end = clock();
  time = static_cast<double>(end - start);
  printList(sorted_list);
  return time;
}

