/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:50:04 by oldault           #+#    #+#             */
/*   Updated: 2024/06/17 14:14:18 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "utils.hpp"

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
  std::ifstream infile = openFile(filename);

  std::string header;
  std::getline(infile, header);

  std::string line;
  while (std::getline(infile, line))
  {
    Date date;
    double price;
    if (parseCSVLine(line, date, price)) {
      _btcPrices[date] = price;
    }
  }
  infile.close();
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

/**
 * @brief Processes the input file for BitcoinExchange.
 *
 * This function reads the specified input file, and processes each
 * line using the handleLine method. It skips values that are not standard.
 *
 * @param filename The name of the input file to be processed.
 * @throw std::ios_base::failure if the file cannot be opened.
 */
void BitcoinExchange::processInputFile(const std::string& filename)
{
  std::ifstream infile = openFile(filename);

  std::string header;
  std::getline(infile, header);
  if (header != "date | value") {
    std::cerr << BRED(" input file header missing ") << std::endl;
    return ;
  }

  std::string line;
  while (std::getline(infile, line)) {
    try {
      BitcoinExchange::handleLine(line);
    } catch (const std::exception &e) {
      std::cerr << BRED(" ERROR: ") << "\t" << e.what() << std::endl;
    }
  }
}

Date BitcoinExchange::handleDate(const std::string& dateStr)
{
  Date date;
  if (std::sscanf(dateStr.c_str(), "%d-%d-%d", &date.year, &date.month, &date.day) != 3)
  {
    std::string err = FRED("Date: ") + FRED(UNDL(dateStr)) + FRED(" not in valid format");
    throw std::runtime_error(err);
  }
  
  std::map<Date, double>::iterator firstIt = _btcPrices.begin();
  std::map<Date, double>::iterator lastIt = _btcPrices.end();
  --lastIt;
  Date dateStart = firstIt->first;
  Date dateEnd = lastIt->first;
  if (date < dateStart) { 
    throwErr("No Record of such early date in database");
  } else if (dateEnd < date) {
    throwErr("Database only goes up to 2022-03-29");
  }

  if (date.month < 0 || 12 < date.month) {
    throwErr("Invalid Month value");
  } else if (date.day < 0 || 31 < date.day) {
    throwErr("Invalid Day value");
  }
  return date;
}

double BitcoinExchange::handleValue(const std::string& valueStr)
{
  char* end;
  double value = strtod(valueStr.c_str(), &end);
  if (*end != '\0') {
    throwErr("Invalid price format");
  }
  
  if (value < 0.0) {
    throwErr("Negative number detected");
  } else if (value > 1000.0) {
    throwErr("Number too large to process");
  }
  return value;
}

void BitcoinExchange::handleLine(const std::string& line)
{
  std::istringstream ss(line);
  std::string dateStr, valueStr;
  if (std::getline(ss, dateStr, '|') && std::getline(ss, valueStr)) {
    Date date = handleDate(dateStr);
    double value = handleValue(valueStr);
    std::cout << date << " => " << FYEL(value) << " =\t" << BMAG(BE::getBitcoinValueOnDate(date, value)) << std::endl;
  } else {
    if (dateStr.empty() && valueStr.empty())
      dateStr = "Empty Input";
    std::string err = FRED("Bad input => ") + FRED(UNDL(dateStr));
    throw std::runtime_error(err);
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
  result = ((match != _btcPrices.end()) ? match->second : getClosestPrice(date));

  return (result * value);
}



