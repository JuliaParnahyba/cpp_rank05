/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jparnahy <jparnahy@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:00:00 by jparnahy          #+#    #+#             */
/*   Updated: 2026/05/26 21:43:09 by jparnahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cstddef>
# include <deque>
# include <string>
# include <vector>

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(int argc, char **argv);
		PmergeMe(PmergeMe const &other);
		~PmergeMe(void);

		PmergeMe	&operator=(PmergeMe const &other);

		void	run(void) const;

	private:
		struct VectorPair
		{
			int	high;
			int	low;
		};

		struct VectorPending
		{
			int		value;
			int		high;
			bool	hasHigh;
		};

		struct DequePair
		{
			int	high;
			int	low;
		};

		struct DequePending
		{
			int		value;
			int		high;
			bool	hasHigh;
		};

		std::vector<int>	_input;

		void	parseArguments(int argc, char **argv);
		bool	containsValue(int value) const;

		void	sortVector(std::vector<int> &values) const;
		void	insertVectorPendings(std::vector<int> &values,
					std::vector<VectorPending> const &pending) const;
		void	insertVectorPending(std::vector<int> &values,
					VectorPending const &pending) const;

		void	sortDeque(std::deque<int> &values) const;
		void	insertDequePendings(std::deque<int> &values,
					std::deque<DequePending> const &pending) const;
		void	insertDequePending(std::deque<int> &values,
					DequePending const &pending) const;

		static int			parsePositiveInteger(std::string const &token);
		static int			findVectorLow(std::vector<VectorPair> const &pairs,
								int high);
		static std::size_t	findVectorBound(std::vector<int> const &values,
								int high);
		static std::size_t	lowerBoundVector(std::vector<int> const &values,
								int value, std::size_t end);
		static int			findDequeLow(std::deque<DequePair> const &pairs,
								int high);
		static std::size_t	findDequeBound(std::deque<int> const &values,
								int high);
		static std::size_t	lowerBoundDeque(std::deque<int> const &values,
								int value, std::size_t end);
		static double		getMicroseconds(void);
		static void			printVector(char const *label,
								std::vector<int> const &values);
		static bool			isSorted(std::vector<int> const &values,
								std::deque<int> const &other);
};

#endif
