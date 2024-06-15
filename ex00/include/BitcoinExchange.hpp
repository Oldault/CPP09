/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:22:28 by oldault           #+#    #+#             */
/*   Updated: 2024/06/15 17:56:10 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include "Colors.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <stdexcept>

class BitcoinExchange
{
  private:
    std::map<std::string, double> _btcPrices;
  
  public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();

    BitcoinExchange& operator=(const BitcoinExchange& other);

    void loadPricesFromCSV(const std::string& filename);
    void displayPrices() const;
};

#endif // __BITCOINEXCHANGE_HPP__