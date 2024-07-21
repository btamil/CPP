/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:58:01 by tponnusa          #+#    #+#             */
/*   Updated: 2024/07/11 13:58:09 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitCoinExchange_HPP
#define BitCoinExchange_HPP

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


class BitCoinExchange {
	private:
		std::map<std::string, std::string> exchangeRate;

		std::string		extractDate(const std::string& partStr);
		std::string 	extractValue(const std::string& partStr);
		bool 			checkDateFormat(const std::string& date);
		bool 			isLeapYear(int year);
		void 			checkValue(const std::string& val);
		float 			ft_stof(const std::string& val);
		bool 			isEmptyFile(const std::string& filename);
		std::string 	previousDate(const std::string& date);
		int 			ft_stoi(const std::string& str);
		std::string 	intToString(int number);

	public:
		BitCoinExchange();
		BitCoinExchange(const BitCoinExchange& src);
		BitCoinExchange& operator=(const BitCoinExchange& src);
		~BitCoinExchange();

		void 	displayExchangeRate(const std::string& input);
		


};

#endif
