/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_insert_deque.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:22:20 by yena              #+#    #+#             */
/*   Updated: 2023/10/25 15:49:39 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yejin Na on 10/19/23.
//

#include "merge_insert_deque.hpp"

/**
 * 벡터의 원소를 큰 것과 작은 것으로 이루어진 쌍(pair)의 벡터로 나눈다.
 * 만약 원소의 개수가 홀수라면 마지막 원소는 (deque[size - 1], 0)으로 채워진다.
 * @param deque 벡터
 * @return 짝으로 이루어진 벡터
 */
std::deque<std::pair<int, int> > makePairsDeque(std::deque<int> deque) {
  unsigned int size = deque.size() % 2 == 1 ? deque.size() - 1 : deque.size();
  std::deque<std::pair<int, int> > pair_deque;

  if (deque.size() % 2 == 1) deque.push_back(0);
  for (unsigned int i = 0; i < size; i += 2) {
    if (deque[i] > deque[i + 1]) {
      std::pair<int, int> pair = std::make_pair(deque[i], deque[i + 1]);
      pair_deque.push_back(pair);
    } else {
      std::pair<int, int> pair = std::make_pair(deque[i + 1], deque[i]);
      pair_deque.push_back(pair);
    }
  }
  return pair_deque;
}

/**
 * 삽입 정렬을 실행한다.
 * @param deque 정렬될 벡터
 * @param element 정렬할 원소
 */
void insertionSortDeque(std::deque<int> &deque, int element) {
  for (unsigned long i = 0; i < deque.size(); i++) {
    if (deque.at(i) > element) {
      deque.insert(deque.begin() + i, element);
      break;
    }
  }
}

/**
 * 이진 탐색하여 원소를 알맞은 자리에 insert한다.
 * @param deque 정렬될 벡터
 * @param element 정렬할 원소
 * @param left 덱의 왼쪽 끝 인덱스
 * @param right 덱의 오른쪽 끝 인덱스
 */
void binarySearchDeque(std::deque<int> &deque, int element, int left, int right) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (deque.at(mid) <= element) {
      left = mid + 1;
    } else if (deque.at(mid) > element) {
      right = mid - 1;
    }
  }
  deque.insert(deque.begin() + left, element);
}

/**
 * 두 벡터를 deque에 병합한다. 이는 recursiveMergeSortDeque에서 호출된다.
 * @param deque 병합 결과 벡터
 * @param left_deque 왼쪽 벡터
 * @param right_deque 오른쪽 벡터
 */
void mergeDeque(std::deque<std::pair<int, int> > &deque,
                 std::deque<std::pair<int, int> > &left_deque,
                 std::deque<std::pair<int, int> > &right_deque) {
  unsigned long i = 0;
  unsigned long j = 0;
  unsigned long k = 0;
  unsigned long left_size = left_deque.size();
  unsigned long right_size = right_deque.size();

  while (i < left_size && j < right_size) {
    if (left_deque[i].first <= right_deque[j].first) {
      deque[k++] = left_deque[i++];
    } else {
      deque[k++] = right_deque[j++];
    }
  }
  while (i < left_size) {
    deque[k++] = left_deque[i++];
  }
  while (j < right_size) {
    deque[k++] = right_deque[j++];
  }
}

/**
 * 만약 한 쌍의 첫 번째 원소(larger)를 기준으로 재귀로 병합 정렬을 수행하여 오름차순 정렬한다.
 * @param deque 정렬될 벡터
 * @param index 벡터의 위치를 나타내는 인덱스
 */
void recursiveMergeSortDeque(std::deque<std::pair<int, int> > &deque,
                              unsigned long left, unsigned long right) {
  if (left >= right)
    return;
  unsigned long mid = left + (right - left) / 2;
  std::deque<std::pair<int, int> > left_deque(deque.begin() + left, deque.begin() + mid + 1);
  std::deque<std::pair<int, int> > right_deque(deque.begin() + mid + 1, deque.begin() + right + 1);
  recursiveMergeSortDeque(left_deque, 0, left_deque.size() - 1);
  recursiveMergeSortDeque(right_deque, 0, right_deque.size() - 1);
  mergeDeque(deque, left_deque, right_deque);
}

/**
 * 벡터 쌍을 정렬한다.
 * @param deque 정렬될 벡터
 * @param pair_deque 정수로 이루어진 쌍들의 벡터
 * @return 정렬된 벡터
 */
std::deque<int> sortPairDeque(std::deque<int> deque,
                                std::deque<std::pair<int, int> > pair_deque) {
  recursiveMergeSortDeque(pair_deque, 0, pair_deque.size() - 1);
  std::deque<int> sorted_deque;

  for (unsigned long i = 0; i < pair_deque.size(); i++) {
    sorted_deque.push_back(pair_deque[i].first);
  }
  sorted_deque.insert(sorted_deque.begin(), pair_deque[0].second);
  for (unsigned long i = 1; i < pair_deque.size(); i++) {
    size_t right = std::find(
        sorted_deque.begin(),
        sorted_deque.end(),
        pair_deque[i].first
    ) - sorted_deque.begin();
    binarySearchDeque(sorted_deque, pair_deque[i].second, 0, static_cast<int>(right) - 1);
  }
  if (deque.size() % 2 == 1) {
    binarySearchDeque(
        sorted_deque,
        deque[deque.size() - 1],
        0,
        static_cast<int>(sorted_deque.size()) - 1
    );
  }
  return sorted_deque;
}

/**
 * 벡터를 출력한다.
 * @param deque
 */
void printDeque(std::deque<int> deque) {
  std::cout << "- std::deque:\t";
  for (unsigned long i = 0; i < deque.size(); i++) {
    std::cout << deque[i] << " ";
  }
  std::cout << std::endl;
}

/**
 * merge-insert 정렬을 이용하여 벡터를 오름차순 정렬한다.
 * @param deque 정렬할 벡터
 * @return 정렬하는 데 걸린 시간
 */
double sortDeque(std::deque<int> deque) {
  std::deque<std::pair<int, int> > pair_deque;
  std::deque<int> sorted_deque;
  clock_t start, end;
  float time;

  start = clock();
  pair_deque = makePairsDeque(deque);
  sorted_deque = sortPairDeque(deque, pair_deque);
  end = clock();
  time = static_cast<double>(end - start);
  printDeque(sorted_deque);
  return time;
}
