/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:54:45 by oldault           #+#    #+#             */
/*   Updated: 2024/06/21 10:16:06 by oldault          ###   ########.fr       */
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
    std::vector<int> _numbers;
    std::set<int> _seen;

    void printBefore() const;
    void printAfter() const;

    void vecSort();
    void vecMergeInsertSort();
    void vecInsertSort();
    void vecMerge();
    
  public:
    PMergeMe();
    ~PMergeMe();

    bool addNumber(const std::string& arg);

    void sort();
};

#endif // __PMERGEME_HPP__