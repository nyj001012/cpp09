/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:29:45 by yena              #+#    #+#             */
/*   Updated: 2023/10/24 14:25:30 by yena             ###   ########.fr       */
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
  bool isValidDigit(std::string token);
  std::stack<double> getTokenStack() const;
  void setTokenStack(std::stack<double> token_stack);
  double calculate(std::string token);
  void removeWhiteSpace(std::string &expression);
  void run(std::string expression);
  ~RPN();

 private:
  std::stack<double> _token_stack;
};

#endif  // EX01__RPN_HPP_
