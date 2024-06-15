/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:01:21 by oldault           #+#    #+#             */
/*   Updated: 2024/06/15 18:07:35 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <fstream>

bool file_exists(const std::string& filename) {
  std::ifstream infile(filename.c_str());
  return infile.good();
}

int log_error(const std::string& err)
{
  std::cerr << "\n\t"
    << "🚨📢🔔" << BRED("  ")
    << BOLD(BRED(err))
    << BRED("  ") << "🚨📢🔔"
  << "\n\n";

  return 1;
}

int invalid_input(int ac, char **av, const std::string& filename)
{
  if (ac != 2) {
    return log_error("The program takes in one argument. Try again");
  }
  if (!file_exists(av[1])) {
    return log_error("Problem opening given file. Try again");
  }
  if (!file_exists(filename))
  {
    return log_error("Problem opening the data file");
  }

  return 0;
}