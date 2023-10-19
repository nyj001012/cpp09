/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_insert_vector.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:42:48 by yena              #+#    #+#             */
/*   Updated: 2023/10/19 21:42:43 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yejin Na on 10/19/23.
//

#include "merge_insert_vector.hpp"

/**
 * 벡터의 원소를 큰 것과 작은 것으로 이루어진 쌍(pair)의 벡터로 나눈다.
 * 만약 원소의 개수가 홀수라면 마지막 원소는 (vector[size - 1], 0)으로 채워진다.
 * @param vector 벡터
 * @return 짝으로 이루어진 벡터
 */
std::vector<std::pair<int, int> > makePairsVector(std::vector<int> vector) {
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

/**
 * 삽입 정렬을 실행한다.
 * @param vector 정렬될 벡터
 * @param element 정렬할 원소
 */
void insertionSortVector(std::vector<int> *vector, int element) {
    for (unsigned long i = 0; i < vector->size(); i++) {
        if (vector->at(i) > element) {
            vector->insert(vector->begin() + i, element);
            break;
        }
    }
}

/**
 * 이진 탐색하여 원소를 알맞은 자리에 insert한다.
 * @param vector 정렬될 벡터
 * @param element 정렬할 원소
 */
void binarySearchVector(std::vector<int> *vector, int element) {
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

/**
 * 만약 한 쌍의 첫 번째 원소(larger)를 기준으로 재귀를 이용하여 오름차순 정렬한다.
 * @param vector 정렬될 벡터
 * @param index 벡터의 위치를 나타내는 인덱스
 */
void recursiveSortVector(std::vector<std::pair<int, int> > *vector,
                           unsigned long index) {
    if (index == vector->size() - 1) {
        return;
    }
    if (vector->at(index) > vector->at(index + 1)) {
        std::swap(vector->at(index), vector->at(index + 1));
    }
    recursiveSortVector(vector, index + 1);
}

/**
 * 벡터 쌍을 정렬한다.
 * @param vector 정렬될 벡터
 * @param pair_vector 정수로 이루어진 쌍들의 벡터
 * @return 정렬된 벡터
 */
std::vector<int> sortPairVector(std::vector<int> vector,
                                  std::vector<std::pair<int, int> > pair_vector) {
    recursiveSortVector(&pair_vector, 0);
    std::vector<int> sorted_vector;

    for (unsigned long i = 0; i < pair_vector.size(); i++) {
        sorted_vector.push_back(pair_vector[i].first);
    }
    sorted_vector.insert(sorted_vector.begin(), pair_vector[0].second);
    for (unsigned long i = 1; i < pair_vector.size(); i++) {
        insertionSortVector(&sorted_vector, pair_vector[i].second);
    }
    if (vector.size() % 2 == 1) {
        binarySearchVector(&sorted_vector, vector[vector.size() - 1]);
    }
    return sorted_vector;
}

/**
 * 벡터를 출력한다.
 * @param vector
 */
void printVector(std::vector<int> vector) {
    std::cout << "- std::vector:\t";
    for (unsigned long i = 0; i < vector.size(); i++) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * merge-insert 정렬을 이용하여 벡터를 오름차순 정렬한다.
 * @param vector 정렬할 벡터
 * @return 정렬하는 데 걸린 시간
 */
double sortVector(std::vector<int> vector) {
    std::vector<std::pair<int, int> > pair_vector;
    std::vector<int> sorted_vector;
    clock_t start, end;
    float time;

    start = clock();
    pair_vector = makePairsVector(vector);
    sorted_vector = sortPairVector(vector, pair_vector);
    end = clock();
    time = static_cast<double>(end - start);
    printVector(sorted_vector);
    return time;
}