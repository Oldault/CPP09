/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:55:00 by oldault           #+#    #+#             */
/*   Updated: 2024/06/21 15:08:05 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"
#include "utils.hpp"

void PMergeMe::printBefore() const
{
  std::cout << "\n\t" << BYEL(" Before: ") << "\t";
  if (_vecNums.size() <= 6) {
    printVec(_vecNums);
    return ;
  }
  for (size_t i = 0; i < 6; i++) {
    std::cout << ITAL(_vecNums[i]) << " ";
  }
  std::cout << ITAL("[...]") << std::endl;
}

void PMergeMe::printAfter() const
{
  std::cout << "\t" << BGRN(" After: ") << "\t";
  if (_vecNums.size() <= 6) {
    printVec(_vecNums);
  } else {
    for (size_t i = 0; i < 6; i++) {
      std::cout << ITAL(_vecNums[i]) << " ";
    }
    std::cout << ITAL("[...]") << std::endl;
  }

  std::cout << "\n" << BOLD("[ 📋 ] ")
    << UNDL("Element count :") << " "
    << FBLU(ITAL(_vecNums.size()))
  << std::endl;

  std::cout << BOLD("[ ⏳ ] ")
    << UNDL("Processing Time (")
    << UNDL(FMAG("Vec")) << UNDL(", ")
    << UNDL(FRED("Deque"))
    << UNDL(") :") << " "
    << FMAG(ITAL(_vecTime)) << ", "
    << FRED(ITAL(_dequeTime)) << ITAL("ms")
  << std::endl << std::endl;
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
  
  _vecNums.push_back(num);
  _seen.insert(num);
  return true;
}

void PMergeMe::sort()
{
  _dequeNums.assign(_vecNums.begin(), _vecNums.end());
  
  printBefore();
  vecSort();
  dequeSort();
  printAfter();
}
