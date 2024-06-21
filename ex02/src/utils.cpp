/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:57:35 by oldault           #+#    #+#             */
/*   Updated: 2024/06/21 10:05:01 by oldault          ###   ########.fr       */
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
    << BBLU(ITAL("`./PMergeME`"))
    << BBLU(BOLD(" a list of ints."))
    << "\n\n\t" << UNDL(" EXAMPLES: ")
    << "\n\t" << ITAL(FMAG("./PMergeME 3 4 5 2 1"))
    << "\n\t" << ITAL(FMAG("./PMergeME 1 9 2 8 7 4 5 3 6"))
    << "\n\t" << ITAL(FMAG("./PMergeME 1 2 [...]"))
  << std::endl << std::endl;
}

void printVec(const std::vector<int>& vec)
{
  for (std::vector<int>::size_type i = 0; i < vec.size(); i++) {
    std::cout << ITAL(vec[i]) << " ";
  }
  std::cout << std::endl;
}

bool is_number(const std::string& s)
{
  std::string::const_iterator it = s.begin();
  while (it != s.end() && std::isdigit(*it)) ++it;
  return !s.empty() && it == s.end();
}
