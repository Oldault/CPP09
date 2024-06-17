/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:17:35 by oldault           #+#    #+#             */
/*   Updated: 2024/06/17 17:32:04 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

template <typename Out>
void split(const std::string &s, char delim, Out result)
{
  std::istringstream iss(s);
  std::string item;
  while (std::getline(iss, item, delim)) {
    *result++ = item;
  }
}

std::vector<std::string> split(const std::string &s, char delim)
{
  std::vector<std::string> elems;
  split(s, delim, std::back_inserter(elems));
  return elems;
}

bool isToken(const std::string& s)
{
  return (s == "+" || s == "-" || s == "*" || s == "/");
}

int main(int ac, char **av)
{
  (void)ac;
  (void)av;
  std::stack<int> _stack;
  
  std::string input = "8 9 * 9 - 9 - 9 - 4 - 1 +";
  std::vector<std::string> x = split(input, ' ');
  
  for (std::vector<std::string>::size_type i = 0; i < x.size(); i++)
  {
    std::string element = x.at(i);
    std::cout << i << ": " << element << " -> ";
    if (isToken(element))
    {
      std::cout << "Token" << std::endl;
      if (_stack.size() != 2)
      {
        std::cerr << "Not enough elements inside stack" << std::endl;
        return -1;
      }
      int temp1 = _stack.top();
      _stack.pop();
      int temp2 = _stack.top();
      _stack.pop();
      if (element == "+") {
        std::cout << "doing " << temp2 << element << temp1 << std::endl;
        _stack.push(temp2 + temp1);
      } else if (element == "-") {
        std::cout << "doing " << temp2 << element << temp1 << std::endl;
        _stack.push(temp2 - temp1);
      } else if (element == "*") {
        std::cout << "doing " << temp2 << element << temp1 << std::endl;
        _stack.push(temp2 * temp1);
      } else if (element == "/") {
        std::cout << "doing " << temp2 << element << temp1 << std::endl;
        _stack.push(temp2 / temp1);
      }
    }
    else
    {
      int num = std::atoi(element.c_str());
      if (num <= 0) {
        std::cout << "Invalid" << std::endl;
        return -1;
      }
      std::cout << "Number" << std::endl;
      _stack.push(num);
    }
    
  }
  std::cout << std::endl;
  
  std::cout << "End of program result = " << _stack.top() << std::endl;
  return 0;
}
