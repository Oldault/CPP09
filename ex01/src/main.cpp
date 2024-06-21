/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:17:35 by oldault           #+#    #+#             */
/*   Updated: 2024/06/21 16:07:13 by oldault          ###   ########.fr       */
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
  std::istringstream iss(input);
  std::string token;

  while (iss >> token) {
    rpn.processToken(token);
  }
  int result = rpn.getResult();
  if (result == 42)
    std::cout << FMAG(BOLD("The Answer to the Ultimate Question of Life, the Universe and Everything : ")) << std::endl;
  std::cout << BOLD(FGRN(" ↪ ")) << FGRN(result) << std::endl;
  return 0;
}
