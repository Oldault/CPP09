/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:55:28 by oldault           #+#    #+#             */
/*   Updated: 2024/06/21 10:08:30 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"
#include "utils.hpp"

int main(int ac, char** av)
{
  if (ac < 2) {
    printDemo();
    return - 42;
  }

  PMergeMe FJA;
  for (int i = 1; i < ac; ++i) {
    if (!FJA.addNumber(av[i])) {
      std::cerr << ITAL(" Exiting program... 🔚") << std::endl;
      return 1;
    }
  }
  FJA.sort();

  return 0;
}
