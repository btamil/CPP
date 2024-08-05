/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:58:01 by tponnusa          #+#    #+#             */
/*   Updated: 2024/07/29 17:12:28 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

# include <algorithm>
# include <exception>
# include <string>
# include <map>
# include <ctime>
# include <iostream>
# include <fstream>
# include <sys/stat.h>
# include <cctype>
# include <sstream>


class BitcoinExchange {
	private:
		std::map<std::string, std::string> exchangeRate;

		
		std::string		extractDate(const std::string& partStr);
		std::string 	extractValue(const std::string& partStr);
		bool 			checkDateFormat(const std::string& date);
		bool 			isLeapYear(int year);
		void 			checkValue(const std::string& val);
		double 			ft_stod(const std::string& val);
		bool 			isEmptyFile(const std::string& filename);
		std::string 	previousDate(const std::string& date);
		int 			ft_stoi(const std::string& str);
		std::string 	intToString(int number);
		void			trim(std::string &str);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);
		~BitcoinExchange();

		void 	displayExchangeRate(const std::string& input);
		void	initDatabase();
};

#endif
