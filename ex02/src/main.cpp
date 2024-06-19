/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:55:28 by oldault           #+#    #+#             */
/*   Updated: 2024/06/19 13:07:48 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"
#include "utils.hpp"

int main(int ac, char** av)
{
  if (ac != 2) {
    printDemo();
    return - 42;
  }

  PMergeMe alg;
  std::string input = av[1];
  std::vector<std::string> x = split(input, ' ');

  std::cout << BYEL(" Before ") << ":\t";
  printVec(x);

  return 0;
}