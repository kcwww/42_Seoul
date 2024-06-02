/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:09:17 by dkham             #+#    #+#             */
/*   Updated: 2024/06/03 01:38:50 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>
#include <cmath>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const std::string& ratesFile, const std::string& inputFile);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void loadExchangeRatesFromCsv(const std::string& filename);
    void processInputFile(const std::string& filename);

private:
    std::map<std::string, double> exchangeRates;
    void calculateAndPrintValue(const std::string& date, double value);
    std::string findClosestDate(const std::string& date);
    bool isValidDate(const std::string& date);
};

#endif
