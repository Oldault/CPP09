/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:50:04 by oldault           #+#    #+#             */
/*   Updated: 2024/06/16 18:14:06 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "utils.hpp"

std::ostream& operator<<(std::ostream& os, const Date& date)
{
  os << date.year << '-' 
    << std::setw(2) << std::setfill('0') << date.month << '-'
    << std::setw(2) << std::setfill('0') << date.day;
  return os;
}

/**
 * @brief Loads Bitcoin prices from a CSV file into the map.
 * 
 * This function opens a CSV file, reads it line by line, and extracts the date
 * and exchange rate. It skips the header line. Each valid line should be in the
 * format "date,price". The function converts the price to a double and stores
 * the date and price in the `_btcPrices` map.
 * 
 * @param filename The name of the CSV file to read from.
 * @note The function assumes the CSV file has a header line that will be skipped.
 * @warning If the file cannot be opened the function will `throw an exception`.
 *          If a line is incorrectly formatted, an error message is printed to `stderr`.
 */
void BitcoinExchange::loadPricesFromCSV(const std::string& filename)
{
  std::ifstream infile(filename.c_str());
  if (!infile)
    throw std::runtime_error("Could not open BTC data file");

  std::string header;
  std::getline(infile, header);

  std::string line;
  while (std::getline(infile, line)) {
    std::istringstream ss(line);
    std::string dateStr, priceStr;
    if (std::getline(ss, dateStr, ',') && std::getline(ss, priceStr)) {
      Date date;
      std::sscanf(dateStr.c_str(), "%d-%d-%d", &date.year, &date.month, &date.day);
      char* end;
      double price = strtod(priceStr.c_str(), &end);
      if (*end != '\0') {
        std::cerr << BRED("Error: Invalid price format in line: ") << FRED(BOLD(line)) << std::endl;
        continue;
      }
      _btcPrices[date] = price;
    } else {
      std::cerr << BRED("Error: Incorrect format in line: ") << FRED(BOLD(line)) << std::endl;
    }
  }
  infile.close();
}

/**
 * @brief Prints out `_btcPrices` to the terminal
 */
void BitcoinExchange::displayPrices() const
{
  std::cout << BGRN(" Date ") << "\t" << BBLU(" Price ") << std::endl;
  for (std::map<Date, double>::const_iterator it = _btcPrices.begin(); it != _btcPrices.end(); ++it) {
    std::cout << it->first.year << "-" << it->first.month << "-" << it->first.day << "\t" << it->second << std::endl;
  }
}

void BitcoinExchange::processInputFile(const std::string& filename)
{
  std::ifstream infile(filename.c_str());
  if (!infile)
    throw std::runtime_error("Could not open the input file");

  std::string header;
  std::getline(infile, header);
  if (header != "date | value")
    std::cerr << BRED(" input file header not standard ") << std::endl;

  std::string line;
  while (std::getline(infile, line)) {
    try {
      BitcoinExchange::handleLine(line);
    } catch (const std::exception &e) {}
  }
}

static double getValue(const std::string& valueStr)
{
  char* end;
  double value = strtod(valueStr.c_str(), &end);
  if (*end != '\0') {
    std::cerr << BRED("Error: Invalid price format") << std::endl;
    return -1;
  }
  return value;
}

void BitcoinExchange::handleLine(const std::string& line)
{
  std::istringstream ss(line);
  std::string dateStr, valueStr;
  if (std::getline(ss, dateStr, '|') && std::getline(ss, valueStr)) {
    Date date;
    if (std::sscanf(dateStr.c_str(), "%d-%d-%d", &date.year, &date.month, &date.day) != 3) {
      std::cerr << BRED(" ERROR: ") << "\t" << FRED("Invalid date -> ");
      throw std::runtime_error(dateStr.c_str());
    }
    double value = getValue(valueStr);
    if (value < 0.0) {
      std::cerr << BRED(" ERROR: ") << "\t";
      throw std::runtime_error("not a positive number");
    } else if (value > 1000.0) {
      std::cerr << BRED(" ERROR: ") << "\t";
      throw std::runtime_error("number too large");
    }
    std::cout << date << " => " << FYEL(value) << " =\t" << BMAG(BE::getBitcoinValueOnDate(date, value)) << std::endl;
  } else {
    std::cerr << BRED(" ERROR: ") << "\t" << FRED("Bad input -> ");
    throw std::runtime_error(line.c_str());
  }
}

double BitcoinExchange::getClosestPrice(const Date& queryDate) const
{
  std::map<Date, double>::const_iterator it = _btcPrices.lower_bound(queryDate);
  if (it == _btcPrices.begin()) {
    return -1.0;
  }
  --it;
  if (it->first != queryDate) {
    --it;
  }
  if (it == _btcPrices.begin()) {
    return it->second;
  }
  return it->second; 
}

double BitcoinExchange::getBitcoinValueOnDate(const Date& date, double value) const
{
  double result;
  std::map<Date, double>::const_iterator match = _btcPrices.find(date);
  if (match != _btcPrices.end()) {
    result = match->second;
  } else {
    result = getClosestPrice(date);
  }

  // std::cout << result << " * " << value << " = " << (result * value) << "\t";
  return (result * value);
}



