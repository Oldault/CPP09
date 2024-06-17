/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:17:57 by oldault           #+#    #+#             */
/*   Updated: 2024/06/17 21:25:54 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN_H__
#define __RPN_H__

#include "Colors.hpp"
#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <iterator>

class RPN
{
  private:
    std::stack<int> _stack;
    int getOperatorCode(const std::string& token);
    int popTop();

  public:
    RPN();
    ~RPN();

    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
  
    void processToken(const std::string& token);
    int getResult();
};

#endif // __RPN_H__