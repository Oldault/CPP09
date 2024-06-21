/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:55:00 by oldault           #+#    #+#             */
/*   Updated: 2024/06/21 10:16:28 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"
#include "utils.hpp"

void PMergeMe::printBefore() const
{
  std::cout << BYEL(" Before: ") << "\t";
  printVec(_numbers);
}

void PMergeMe::printAfter() const
{

}

bool PMergeMe::addNumber(const std::string& arg)
{
  if (!is_number(arg)) {
    std::cerr << BRED(" Invalid arg: ")
      << "\t" << FRED(arg)
    << std::endl;
    return false;
  }
  int num = std::atoi(arg.c_str());
  if (_seen.find(num) != _seen.end()) {
    std::cerr << BRED(" Duplicate number found: ")
      << "\t" << FRED(arg)
    << std::endl;
    return false;
  }
  
  _numbers.push_back(num);
  _seen.insert(num);
  return true;
}


void PMergeMe::sort()
{
  printBefore();
  vecSort();
}


void PMergeMe::vecSort()
{
  
}

void PMergeMe::vecMergeInsertSort()
{

}

void PMergeMe::vecInsertSort()
{

}


void PMergeMe::vecMerge()
{

}
