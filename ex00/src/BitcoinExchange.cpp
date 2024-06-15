/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:50:04 by oldault           #+#    #+#             */
/*   Updated: 2024/06/15 18:04:55 by oldault          ###   ########.fr       */
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
  std::ifstream infile(filename.c_str());
  if (!infile)
    throw std::runtime_error("Could not open BTC data file");

  std::string header;
  std::getline(infile, header);
  std::cout << "Header: " << header << std::endl;

  std::string line;
  while (std::getline(infile, line)) {
    std::istringstream ss(line);
    std::string date, priceStr;
    if (std::getline(ss, date, ',') && std::getline(ss, priceStr)) {
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

void BitcoinExchange::displayPrices() const
{
  std::cout << BGRN(" Date ") << "\t" << BBLU(" Price ") << std::endl;
  for (std::map<std::string, double>::const_iterator it = _btcPrices.begin(); it != _btcPrices.end(); ++it) {
    std::cout << FGRN(it->first) << " :\t" << FBLU(it->second) << std::endl;
  }
}
