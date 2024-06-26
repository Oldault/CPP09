/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:21:46 by oldault           #+#    #+#             */
/*   Updated: 2024/06/17 11:16:28 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "utils.hpp"

int main(int ac, char **av)
{
  std::string filename = "data/data.csv";
  if (invalid_input(ac, av, filename))
    return -42;

  BitcoinExchange BTC;
  try {
    BTC.loadPricesFromCSV(filename);
  } catch (const std::exception &e) {}

  // BTC.displayPrices();
  BTC.processInputFile(av[1]);


  return 0;
}
