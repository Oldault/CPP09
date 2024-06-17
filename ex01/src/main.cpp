/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:17:35 by oldault           #+#    #+#             */
/*   Updated: 2024/06/17 21:31:24 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "utils.hpp"

int main(int ac, char **av)
{
  if (ac != 2) {
    printDemo();
    return - 42;
  }

  RPN rpn;
  std::string input = av[1];
  std::vector<std::string> x = split(input, ' ');
  
  for (std::vector<std::string>::size_type i = 0; i < x.size(); i++) {
    rpn.processToken(x[i]);
  }
  if (rpn.getResult() == 42)
    std::cout << FMAG(BOLD("The Answer to the Ultimate Question of Life, the Universe and Everything : ")) << std::endl;
  std::cout << FGRN(rpn.getResult()) << std::endl;
  return rpn.getResult();
}
