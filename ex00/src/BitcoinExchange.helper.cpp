/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.helper.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:34:50 by oldault           #+#    #+#             */
/*   Updated: 2024/06/22 09:43:31 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::ostream& operator<<(std::ostream& os, const Date& date)
{
  os << date.year << '-' 
    << std::setw(2) << std::setfill('0') << date.month << '-'
    << std::setw(2) << std::setfill('0') << date.day;
  return os;
}

void BitcoinExchange::openFile(const std::string& filename, std::ifstream& infile)
{
  infile.open(filename.c_str());
  if (!infile) {
    throw std::runtime_error("Could not open file");
  }
}


