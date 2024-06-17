/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.helper.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:34:50 by oldault           #+#    #+#             */
/*   Updated: 2024/06/17 11:29:56 by oldault          ###   ########.fr       */
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

std::ifstream BitcoinExchange::openFile(const std::string& filename)
{
  std::ifstream infile(filename.c_str());
  if (!infile) {
    std::string err = FRED("Could not open ") + FRED(UNDL(filename));
    throw std::ios_base::failure(err);
  }
    
  return infile;
}


