/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:29:45 by yena              #+#    #+#             */
/*   Updated: 2023/10/16 13:50:08 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by 나예진 on 2023/10/16.
//

#ifndef EX01__RPN_HPP_
#define EX01__RPN_HPP_

#include <iostream>
#include <stack>
#include "font.hpp"

class RPN {
 public:
  RPN();
  RPN(const RPN &rpn);
  RPN &operator=(const RPN &rpn);
  bool isOperator(std::string token);
  bool isDigit(std::string token);
  std::stack<int> getTokenStack() const;
  void setTokenStack(std::stack<int> token_stack);
  int calculate(std::string token);
  void run(std::string expression);
  ~RPN();

 private:
  std::stack<int> token_stack;
};

#endif //EX01__RPN_HPP_
