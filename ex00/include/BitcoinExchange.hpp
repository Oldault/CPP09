/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolodin <svolodin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:22:28 by oldault           #+#    #+#             */
/*   Updated: 2024/06/22 09:42:15 by svolodin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include "Colors.hpp"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <stdexcept>
#include <iomanip>

struct Date
{
  int year, month, day;

  bool operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
  }
  bool operator!=(const Date& other) const {
    return year != other.year && month != other.month && day != other.day;
  }
};

std::ostream& operator<<(std::ostream& os, const Date& date);

class BitcoinExchange
{
  private:
    std::map<Date, double> _btcPrices;

    void openFile(const std::string& filename, std::ifstream& infile);
    bool parseCSVLine(const std::string& line, Date& date, double& price);
    void handleLine(const std::string& line);
    Date handleDate(const std::string& dateStr);
    double handleValue(const std::string& valueStr);
    double getClosestPrice(const Date& date) const;
    double getBitcoinValueOnDate(const Date& date, double value) const;

  public:
    typedef BitcoinExchange BE;

    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();

    BitcoinExchange& operator=(const BitcoinExchange& other);

    void loadPricesFromCSV(const std::string& filename);
    void processInputFile(const std::string& filename);
    void displayPrices() const;
};

#endif // __BITCOINEXCHANGE_HPP__