/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:57:35 by oldault           #+#    #+#             */
/*   Updated: 2024/06/17 21:22:06 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

template <typename Out>
void split(const std::string &s, char delim, Out result)
{
  std::istringstream iss(s);
  std::string item;
  while (std::getline(iss, item, delim)) {
    *result++ = item;
  }
}

std::vector<std::string> split(const std::string &s, char delim)
{
  std::vector<std::string> elems;
  split(s, delim, std::back_inserter(elems));
  return elems;
}

void printDemo()
{
  std::cout << "\n\t"
    << BBLU(BOLD(" Please give "))
    << BBLU(ITAL("`./RPN`"))
    << BBLU(BOLD(" an argument."))
    << "\n\n\t" << UNDL(" EXAMPLES: ")
    << "\n\t" << ITAL(FMAG("./RPN \"3 4 +\""))
    << "\n\t" << ITAL(FMAG("./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\""))
    << "\n\t" << ITAL(FMAG("./RPN \"3 5 + 7 2 - *\""))
    << "\n\t" << ITAL(FMAG("./RPN \"1 2 3 4 + * +\""))
  << std::endl << std::endl;
}
