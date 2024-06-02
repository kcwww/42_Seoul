/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 01:38:47 by chanwookim        #+#    #+#             */
/*   Updated: 2024/06/03 01:38:47 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& ratesFile, const std::string& inputFile) {
    loadExchangeRatesFromCsv(ratesFile);
    processInputFile(inputFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        
        exchangeRates = other.exchangeRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}


void BitcoinExchange::loadExchangeRatesFromCsv(const std::string& filename) {
    std::ifstream file(filename.c_str());
    std::string line, date;
    double rate;

    if (!file.is_open()) {
        std::cout << "Error: could not open exchange rates file.\n";
        exit(1);
    }

    getline(file, line);

    
    while (getline(file, line)) {
        std::istringstream iss(line);
        
        if (!getline(iss, date, ',') || !(iss >> rate)) {
            std::cout << "Error: bad data in exchange rates file => " << line << std::endl;
            exit(1);
        }

        
        if (!isValidDate(date)) {
            std::cout << "Error: invalid date format (follow YYYY-MM-DD) => " << date << std::endl;
            exit(1);
        }

        if (rate < 0) {
            std::cout << "Error: negative rate in exchange rates file => " << rate << std::endl;
            exit(1);
        }

        exchangeRates[date] = rate;
    }

    file.close();
}


std::string BitcoinExchange::findClosestDate(const std::string& date) {
    
    
    std::map<std::string, double>::const_iterator it = exchangeRates.lower_bound(date);

    
    if (it != exchangeRates.begin() && (it == exchangeRates.end() || it->first != date)) {
        --it;
    }
    return it->first;
}


void BitcoinExchange::calculateAndPrintValue(const std::string& date, double value) {
    std::string closestDate = findClosestDate(date);
    double exchangeRate = exchangeRates[closestDate];

    
    if (exchangeRate == 0 && date != closestDate) {
        std::cout << date << "=> " << value << " = " << "No exchange rate available for this date" << std::endl;
    } else {
    
        std::cout << date << "=> " << value << " = " << (value * exchangeRate) << std::endl;
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }

    int year, month, day;
    std::istringstream dateStream(date);
    dateStream >> year; 
    dateStream.ignore();
    dateStream >> month;
    dateStream.ignore();
    dateStream >> day;

    if (year < 0 || month < 1 || month > 12 || day < 1) {
        return false;
    }


    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    if (month == 2 && (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))) { 
        daysInMonth[1] = 29;
    }


    return day <= daysInMonth[month - 1];
}


void BitcoinExchange::processInputFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    std::string line, date;
    double value;


    if (!file.is_open()) {
        std::cout << "Error: could not open input file." << std::endl;
        exit(1);
    }


    while (getline(file, line)) {

        size_t delimiterPos = line.find(" | ");
        if (delimiterPos == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }


        date = line.substr(0, delimiterPos); 
        std::string valueStr = line.substr(delimiterPos + 3);

        std::istringstream iss(valueStr);

        if (!(iss >> value)) { 
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }


        if (!isValidDate(date)) {
            std::cout << "Error: invalid date format (follow YYYY-MM-DD) => " << date << std::endl;
            continue;
        }


        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }


        calculateAndPrintValue(date, value);
    }

    file.close();
}
