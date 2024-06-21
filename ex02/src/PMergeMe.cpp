/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:55:00 by oldault           #+#    #+#             */
/*   Updated: 2024/06/21 14:09:22 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"
#include "utils.hpp"

void PMergeMe::printBefore() const
{
  std::cout << BYEL(" Before: ") << "\t";
  if (_numbers.size() <= 6) {
    printVec(_numbers);
    return ;
  }
  for (size_t i = 0; i < 6; i++) {
    std::cout << ITAL(_numbers[i]) << " ";
  }
  std::cout << ITAL("[...]") << std::endl;
}

void PMergeMe::printAfter() const
{
  std::cout << BGRN(" After: ") << "\t";
  if (_numbers.size() <= 6) {
    printVec(_numbers);
    return ;
  }
  for (size_t i = 0; i < 6; i++) {
    std::cout << ITAL(_numbers[i]) << " ";
  }
  std::cout << ITAL("[...]") << std::endl;
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
  clock_t start = clock();
  vecMergeInsertSort(0, _numbers.size() - 1, 2);
  clock_t end = clock();
  printAfter();
  std::cout << BOLD("[ 📋 ] ")
    << UNDL("Element count :") << " "
    << FBLU(ITAL(_numbers.size()))
  << std::endl;
  std::cout << BOLD("[ ⏳ ] ")
    << UNDL("Processing Time (")
    << UNDL(FMAG("Vec"))
    << UNDL(") :") << " "
    << FMAG(ITAL(end - start)) << FMAG(ITAL("ms"))
  << std::endl;
}

void PMergeMe::vecInsertSort(int left, int right)
{
  int key, j;
  for (int i = left + 1; i <= right; i++) {
    key = _numbers[i];
    j = i - 1;
    while (j >= left && _numbers[j] > key) {
      _numbers[j + 1] = _numbers[j];
      j--;
    }
    _numbers[j + 1] = key;
  }
}

void PMergeMe::vecMerge(int l, int m, int r)
{
  int n1 = m - l + 1;
  int n2 = r - m;

  std::vector<int> left(n1), right(n2);
  
  for (int i = 0; i < n1; i++) left[i] = _numbers[l + i];
  for (int j = 0; j < n2; j++) right[j] = _numbers[m + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (left[i] <= right[j]) {
      _numbers[k++] = left[i++];
    } else {
      _numbers[k++] = right[j++];
    }
  }
  while (i < n1) {
    _numbers[k++] = left[i++];
  }
  while (j < n2) {
    _numbers[k++] = right[j++];
  }
}

void PMergeMe::vecMergeInsertSort(int left, int right, int k)
{
  if (right - left + 1 <= k) {
    vecInsertSort(left, right);
  } else if (left < right) {
    int m = left + (right - left) / 2;
    vecMergeInsertSort(left, m, k);
    vecMergeInsertSort(m + 1, right, k);
    vecMerge(left, m, right);
  }
}
