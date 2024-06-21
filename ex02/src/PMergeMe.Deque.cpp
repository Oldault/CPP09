/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.Deque.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:29:28 by oldault           #+#    #+#             */
/*   Updated: 2024/06/21 15:01:16 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

int PMergeMe::getDequeVal(std::deque<int> deque, int i)
{
  std::deque<int> temp;

  temp.assign(deque.begin(), deque.end());
  std::deque<int>::iterator it = temp.begin();
  while (i--) ++it;
  return *it;
}

void PMergeMe::setDequeVal(int i, int val)
{
  std::deque<int>::iterator it = _dequeNums.begin();
  while (i--) ++it;
  *it = val;
}

void PMergeMe::dequeSort()
{
  clock_t start = clock();
  dequeMergeInsertSort(0, _dequeNums.size() - 1, 2);
  clock_t end = clock();
  _dequeTime = end - start;
}

void PMergeMe::dequeInsertSort(int left, int right)
{
  int key, j;
  for (int i = left + 1; i <= right; i++) {
    key = getDequeVal(_dequeNums, i);
    j = i - 1;
    while (j >= left && getDequeVal(_dequeNums, j) > key) {
      _dequeNums[j + 1] = _dequeNums[j];
      setDequeVal(j + 1, getDequeVal(_dequeNums, j));
      j--;
    }
    setDequeVal(j + 1, key);
  }
}

void PMergeMe::dequeMerge(int l, int m, int r)
{
  int n1 = m - l + 1;
  int n2 = r - m;

  std::deque<int> left, right;
  
  for (int i = 0; i < n1; i++) left.push_back(getDequeVal(_dequeNums, l + i));
  for (int j = 0; j < n2; j++) right.push_back(getDequeVal(_dequeNums, m + 1 + j));

  int i, j, k;
  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (getDequeVal(left, i) <= getDequeVal(right, j)) {
      setDequeVal(k++, getDequeVal(left, i++));
    } else {
      setDequeVal(k++, getDequeVal(right, j++));
    }
  }
  while (i < n1) {
    setDequeVal(k++, getDequeVal(left, i++));
  }
  while (j < n2) {
    setDequeVal(k++, getDequeVal(right, j++));
  }
}

void PMergeMe::dequeMergeInsertSort(int left, int right, int k)
{
  if (right - left + 1 <= k) {
    dequeInsertSort(left, right);
  } else if (left < right) {
    int m = left + (right - left) / 2;
    dequeMergeInsertSort(left, m, k);
    dequeMergeInsertSort(m + 1, right, k);
    dequeMerge(left, m, right);
  }
}
