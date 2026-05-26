#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		std::string	_target;

	protected:
		virtual void	executeAction(void) const;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &other);
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &other);
		virtual ~RobotomyRequestForm(void);
};

#endif
