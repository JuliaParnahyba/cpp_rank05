#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string	_target;

	protected:
		virtual void	executeAction(void) const;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &other);
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &other);
		virtual ~PresidentialPardonForm(void);
};

#endif
