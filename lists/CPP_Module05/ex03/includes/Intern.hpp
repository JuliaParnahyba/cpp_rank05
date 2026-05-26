#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const &other);
		Intern	&operator=(Intern const &other);
		~Intern(void);

		AForm	*makeForm(std::string const &name,
					std::string const &target) const;
};

#endif
