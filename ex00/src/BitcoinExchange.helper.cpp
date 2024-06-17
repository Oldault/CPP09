/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.helper.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:34:50 by oldault           #+#    #+#             */
/*   Updated: 2024/06/17 10:37:45 by oldault          ###   ########.fr       */
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

std::ifstream BitcoinExchange::openFile(const std::string& filename) {
  std::ifstream infile(filename.c_str());
  if (!infile) {
    std::string err = FRED("Could not open ") + FRED(UNDL(filename));
    throw std::runtime_error(err);
  }
    
  return infile;
}

bool BitcoinExchange::parseCSVLine(const std::string& line, Date& date, double& price)
{
  std::istringstream ss(line);
  std::string dateStr, priceStr;
  
  if (std::getline(ss, dateStr, ',') && std::getline(ss, priceStr))
  {
    if (std::sscanf(dateStr.c_str(), "%d-%d-%d", &date.year, &date.month, &date.day) != 3)
      return false;
    
    char* end;
    price = std::strtod(priceStr.c_str(), &end);
    if (*end != '\0')
      return false;
    return true;
  }
  return false;
}
