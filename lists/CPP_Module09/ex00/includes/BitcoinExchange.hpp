/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:00:00 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/26 21:41:39 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &other);
		~BitcoinExchange(void);

		BitcoinExchange	&operator=(BitcoinExchange const &other);

		void	processInputFile(std::string const &fileName) const;

	private:
		enum ValueStatus
		{
			VALUE_OK,
			VALUE_BAD,
			VALUE_NEGATIVE,
			VALUE_TOO_LARGE
		};

		std::map<std::string, double>	_rates;

		void		loadDatabase(std::string const &fileName);
		void		processLine(std::string const &line) const;
		double		getRateForDate(std::string const &date) const;

		static bool			isValidDate(std::string const &date);
		static std::string	trim(std::string const &text);
		static ValueStatus	parseValue(std::string const &text,
							double &value);
};

#endif
