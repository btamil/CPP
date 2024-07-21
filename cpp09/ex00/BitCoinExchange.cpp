/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:14:01 by tponnusa          #+#    #+#             */
/*   Updated: 2024/07/11 14:29:26 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinExchange.hpp"

BitCoinExchange::BitCoinExchange()
{
    std::ifstream inFile("data.csv");
    std::string line;

    if (isEmptyFile("data.csv"))
    {
		std::cerr << "Error: Input File is Empty!" << std::endl;
		exit(EXIT_FAILURE);
    }
    //Skip first line
    std::getline(inFile, line);
    while (std::getline(inFile, line))
    {
        size_t pos = line.find(',');

        std::string date = extractDate(line.substr(0, pos));
        std::string value = extractValue(line.substr(pos + 1, line.length()));

        exchangeRate[date] = value;
    }
    inFile.close();
}

BitCoinExchange::BitCoinExchange(const BitCoinExchange &copy)
{
    *this = copy;
}

BitCoinExchange &BitCoinExchange::operator=(const BitCoinExchange &other)
{
    if (this != &other)
        exchangeRate = other.exchangeRate;
    return *this;
}

BitCoinExchange::~BitCoinExchange() {}

bool BitCoinExchange::isEmptyFile(const std::string& filename)
{
    std::ifstream inFile(filename.c_str());
	// Move the file pointer to the end
    inFile.seekg(0, std::ios::end);
    // Get the position of the file pointer
    std::streampos fileSize = inFile.tellg();
    inFile.close();

    return (fileSize == 0);
}


float BitCoinExchange::ft_stof(const std::string& val)
{
    std::stringstream ss(val);
    float value;

    ss >> value;
    return value;
}

void BitCoinExchange::checkValue(const std::string &val) {
    float value;

    try {
        // If there's more than one decimal point, throw an error
        if (std::find(val.begin(), val.end(), '.') != val.end()) {
            size_t decimalPoint = val.find('.');
            if (std::find(val.begin() + decimalPoint + 1, val.end(), '.') != val.end())
                throw std::invalid_argument("too many decimal points");
        }

        // If there's a + or - sign check the next characters
        bool hasSign = val[0] == '+' || val[0] == '-';
        for (size_t i = hasSign ? 1 : 0; i < val.length(); i++) {
            if (::isdigit(val[i]) || val[i] == '.')
                continue;
            throw std::invalid_argument("not a number => " + val);
        }

        value = ft_stof(val);

    } catch (std::exception &e) {
        throw std::invalid_argument("not a number => " + val);
    }

    if (value < 0)
        throw std::invalid_argument("not a positive number");
    if (value > 1000.0)
        throw std::invalid_argument("too large a number");
}

// Since year has 365.25 days, every 4 year , one day is added extra.
// So if it divisible by 4, then leap year
//Ex:2020 , 2000
bool BitCoinExchange::isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int BitCoinExchange::ft_stoi(const std::string& str)
{
    std::stringstream ss(str);
    int value;

    ss >> value;
    return value;
}

std::string BitCoinExchange::intToString(int number) {
    std::stringstream ss;
    ss << number;
    return ss.str();
}


std::string BitCoinExchange::previousDate(const std::string& date) {
    int year = ft_stoi(date.substr(0, 4));
    int month = ft_stoi(date.substr(5, 2));
    int day = ft_stoi(date.substr(8, 2));

    // Days in each month (for non-leap years)
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // February has 29 days in a leap year
    if (isLeapYear(year)) {
        daysInMonth[2] = 29;
    }

    // Decrement the day
    day--;
    // If day is 0, go to previous month
    if (day == 0) {
        month--;
        // if month is 0, then it will december of previous year
        if (month == 0) {
            month = 12;
            year--;
        }
        day = daysInMonth[month];
    }

    // Format the previous date
    std::string newYear = intToString(year);
    std::string newMonth = (month < 10) ? "0" + intToString(month) : intToString(month);
    std::string newDay = (day < 10) ? "0" + intToString(day) : intToString(day);

    return (newYear + "-" + newMonth + "-" + newDay);
}


bool BitCoinExchange::checkDateFormat(const std::string& date)
{
    if (date.size() != 10)
        return false;

    for (size_t i = 0; i < date.length(); i++) {
        if (i == 4 || i == 7) 
        {
            if (date[i] != '-')
                return false;
        }
        else if (!std::isdigit(date[i]))
            return false;
    }

    int yearInt = ft_stoi(date.substr(0, 4));
    int monthInt = ft_stoi(date.substr(5, 2));
    int dayInt = ft_stoi(date.substr(8, 2));

    //Date starts from here. If input, below this date, it is invalid
    if (yearInt == 2009 && monthInt <= 1 && dayInt < 2)
        return false;

    //In general
    if ((yearInt < 2009 || yearInt > 2022) ||
        (monthInt < 1 || monthInt > 12) ||
        (dayInt < 1 || dayInt > 31))
        return false;

    // Months has only 30 days
    if ((monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) && dayInt > 30)
        return false;

    // Check for February
    if (monthInt == 2) {
        // Check for leap year
        bool isLeap = isLeapYear(yearInt);
        if (dayInt > (isLeap ? 29 : 28))
            return false;
    }
    return true;
}

std::string BitCoinExchange::extractDate(const std::string &partStr) {
    std::string date;
   
    // find the last non-space character 
    std::size_t space_pos = partStr.find_last_not_of(' ');
    if (space_pos != std::string::npos)
        date = partStr.substr(0, space_pos + 1);
    return date;
}

std::string BitCoinExchange::extractValue(const std::string& partStr) {
    std::string value;

	// find the first non-space character 
    std::size_t start = partStr.find_first_not_of(' ');
    if (start != std::string::npos) 
        value = partStr.substr(start);     
    return value;
}

void BitCoinExchange::displayExchangeRate(const std::string& input)
{
	std::ifstream inFile(input.c_str());
	std::string          line;

    if (!inFile.is_open())
	{
		std::cerr << "Error: could not open file: " << input << std::endl;
		exit(EXIT_FAILURE);
	}
    if (isEmptyFile(input))
    {
		std::cerr << "Error: Input File is Empty!" << std::endl;
		exit(EXIT_FAILURE);
    }

	// skip first line
	std::getline(inFile, line);
    
    // Trim any extra whitespace or line-ending characters from the header line
    line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
    line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());

	if (line != "date | value") {
        std::cerr << "Error: Invalid file format " << line << std::endl;
        inFile.close();
        exit(EXIT_FAILURE);
    }
	while (std::getline(inFile, line))
    {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
 
		std::size_t pos = line.find('|');

		if (pos == std::string::npos)
		{
        	std::cerr << "Error: bad input =>" << line << std::endl;
			continue;
		}
        std::string date = extractDate(line.substr(0, pos));
	    std::string value = extractValue(line.substr(pos + 1));

        try {
            if (!checkDateFormat(date))
                throw std::invalid_argument("Invalid date: " + (date.empty() ? "\"\"" : "'" + date + "'"));

            if(value.empty())
                throw std::invalid_argument("Invalid value: " + (value.empty() ? "\"\"" : "'" + value + "'"));

            checkValue(value);

            std::map<std::string, std::string>::iterator it;
            std::string prevDate = date;
            it = exchangeRate.find(date);

            //If given date is not found in map, get previous date
            //Check in map until it is found
            while (it == exchangeRate.end()) {
                const std::string& currentDate = prevDate;
                prevDate = previousDate(currentDate);
                it = exchangeRate.find(prevDate);
            }

            std::cout << date << " => " << value  << " = "
                << ft_stof(it->second) * ft_stof(value) << std::endl;

        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

    }
    inFile.close();
}
