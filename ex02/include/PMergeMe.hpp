/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:54:45 by oldault           #+#    #+#             */
/*   Updated: 2024/06/21 14:47:45 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include "Colors.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <deque>
#include <stdlib.h>
#include <vector>
#include <iterator>
#include <set>

class PMergeMe
{
  private:
    std::set<int> _seen;
    std::vector<int> _vecNums;
    std::deque<int> _dequeNums;
    clock_t _vecTime;
    clock_t _dequeTime;

    void printBefore() const;
    void printAfter() const;

    /* Vector Sort */
    void vecSort();
    void vecInsertSort(int left, int right);
    void vecMerge(int l, int m, int r);
    void vecMergeInsertSort(int left, int right, int k);

    /* Deque Sort*/
    int getDequeVal(std::deque<int> deque, int i);
    void setDequeVal(int i, int val);
    void dequeSort();
    void dequeInsertSort(int left, int right);
    void dequeMerge(int l, int m, int r);
    void dequeMergeInsertSort(int left, int right, int k);
    
  public:
    PMergeMe();
    PMergeMe(const PMergeMe& ref);
    ~PMergeMe();

    PMergeMe&	operator=(const PMergeMe& ref);

    bool addNumber(const std::string& arg);
    void sort();
};

#endif // __PMERGEME_HPP__