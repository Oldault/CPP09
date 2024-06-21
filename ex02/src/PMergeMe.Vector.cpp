/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.Vector.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:24:24 by oldault           #+#    #+#             */
/*   Updated: 2024/06/21 14:24:37 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

void PMergeMe::vecSort()
{
  clock_t start = clock();
  vecMergeInsertSort(0, _vecNums.size() - 1, 2);
  clock_t end = clock();
  printAfter();
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
    key = _vecNums[i];
    j = i - 1;
    while (j >= left && _vecNums[j] > key) {
      _vecNums[j + 1] = _vecNums[j];
      j--;
    }
    _vecNums[j + 1] = key;
  }
}

void PMergeMe::vecMerge(int l, int m, int r)
{
  int n1 = m - l + 1;
  int n2 = r - m;

  std::vector<int> left(n1), right(n2);
  
  for (int i = 0; i < n1; i++) left[i] = _vecNums[l + i];
  for (int j = 0; j < n2; j++) right[j] = _vecNums[m + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (left[i] <= right[j]) {
      _vecNums[k++] = left[i++];
    } else {
      _vecNums[k++] = right[j++];
    }
  }
  while (i < n1) {
    _vecNums[k++] = left[i++];
  }
  while (j < n2) {
    _vecNums[k++] = right[j++];
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
