/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:09:38 by oldault           #+#    #+#             */
/*   Updated: 2024/06/21 16:05:21 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int RPN::popTop()
{
  int top = _stack.top();
  _stack.pop();
  return top;
}

int RPN::getOperatorCode(const std::string& token)
{
  if (token == "+") return 1;
  if (token == "-") return 2;
  if (token == "*") return 3;
  if (token == "/") return 4;
  return 0;
}

void RPN::processToken(const std::string& token)
{
  int tokenCode = RPN::getOperatorCode(token);
  if (tokenCode)
  {
    if (_stack.size() < 2) {
      std::cerr << BRED(" Not enough elements inside stack ") << std::endl;
      exit(-1);
    }
    int temp1 = popTop();
    int temp2 = popTop();
    switch(tokenCode)
    {
      case 1: _stack.push(temp2 + temp1); break;
      case 2: _stack.push(temp2 - temp1); break;
      case 3: _stack.push(temp2 * temp1); break;
      case 4: _stack.push(temp2 / temp1); break;
    }
  }
  else
  {
    int num = std::atoi(token.c_str());
    if (num <= 0) {
      std::cerr << BRED(" Invalid character detected ") << std::endl;
      exit(-1);
    }
    _stack.push(num);
  }
}

int RPN::getResult()
{
  if (_stack.empty()) {
    std::cerr << BRED(" No result available ") << std::endl;
    exit(-1);
  }
  return _stack.top();
}

