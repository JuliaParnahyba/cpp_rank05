#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat					boss("Zaphod", 1);
	Bureaucrat					manager("Marvin", 50);
	Bureaucrat					intern("Arthur", 150);
	ShrubberyCreationForm		shrubbery("garden");
	RobotomyRequestForm			robotomy("Bender");
	PresidentialPardonForm		pardon("Trillian");

	std::cout << shrubbery << std::endl;
	intern.executeForm(shrubbery);
	intern.signForm(shrubbery);
	manager.signForm(shrubbery);
	manager.executeForm(shrubbery);

	manager.signForm(robotomy);
	manager.executeForm(robotomy);
	boss.executeForm(robotomy);

	manager.signForm(pardon);
	boss.signForm(pardon);
	boss.executeForm(pardon);
	return (0);
}
