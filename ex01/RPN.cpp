/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:29:45 by yena              #+#    #+#             */
/*   Updated: 2023/10/16 13:54:01 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by 나예진 on 2023/10/16.
//

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &rpn) {
  if (this != &rpn)
    *this = rpn;
}

RPN &RPN::operator=(const RPN &rpn) {
  if (this != &rpn) {
    this->token_stack = rpn.token_stack;
  }
  return *this;
}

RPN::~RPN() {}

std::stack<int> RPN::getTokenStack() const {
  return this->token_stack;
}

void RPN::setTokenStack(std::stack<int> token_stack) {
  this->token_stack = token_stack;
}

bool RPN::isOperator(std::string token) {
  if (token == "+" || token == "-" || token == "*" || token == "/")
    return true;
  return false;
}

bool RPN::isDigit(std::string token) {
  if (token.length() == 1 && token[0] >= '0' && token[0] <= '9')
    return true;
  return false;
}

int RPN::calculate(std::string token) {
  std::stack<int> token_stack = this->getTokenStack();
  if (token_stack.size() < 2)
    throw std::invalid_argument("Error: Invalid expression.");
  int result = 0;
  int a = token_stack.top();
  token_stack.pop();
  int b = token_stack.top();
  token_stack.pop();

  if (token == "+")
    result = b + a;
  else if (token == "-")
    result = b - a;
  else if (token == "*")
    result = b * a;
  else if (token == "/") {
    if (a == 0)
      throw std::invalid_argument("Error: Division by zero.");
    result = b / a;
  }
  token_stack.push(result);
  this->setTokenStack(token_stack);
  return result;
}

void RPN::run(std::string expression) {
  int result = 0;

  if (expression.empty())
    throw std::invalid_argument("Error: The expression is empty.");
  for (size_t i = 0; i < expression.length(); i += 2) {
    std::string token = expression.substr(i, 1);
    if (isOperator(token))
      result = calculate(token);
    else if (isDigit(token))
      token_stack.push(std::stoi(token));
    else
      throw std::invalid_argument("Error: Invalid token: " + token);
  }
  std::cout << F_GREEN << result << FB_DEFAULT << std::endl;
}
