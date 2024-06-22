/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:17:57 by oldault           #+#    #+#             */
/*   Updated: 2024/06/22 09:50:47 by svolodin         ###   ########.fr       */
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
#include <stdlib.h>
#include <cstdlib>

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