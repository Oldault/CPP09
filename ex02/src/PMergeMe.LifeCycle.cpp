/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.LifeCycle.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 08:47:56 by oldault           #+#    #+#             */
/*   Updated: 2024/06/21 14:24:53 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

PMergeMe::PMergeMe()
{}

PMergeMe::PMergeMe(const PMergeMe& ref)
{
  _vecNums = ref._vecNums;
  _dequeNums.assign(ref._vecNums.begin(), ref._vecNums.end());
}

PMergeMe::~PMergeMe()
{}

PMergeMe&	PMergeMe::operator=(const PMergeMe& ref)
{
  if (this != &ref)
  {
    _vecNums = ref._vecNums;
    _dequeNums.assign(ref._vecNums.begin(), ref._vecNums.end());
  }
  return (*this);
}
