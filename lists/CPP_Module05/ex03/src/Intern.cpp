#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <cstddef>

struct FormFactory
{
	const char	*name;
	AForm		*(*create)(std::string const &target);
};

static AForm	*createShrubbery(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*createRobotomy(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*createPardon(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

Intern::Intern(void)
{
}

Intern::Intern(Intern const &other)
{
	(void)other;
}

Intern	&Intern::operator=(Intern const &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern(void)
{
}

AForm	*Intern::makeForm(std::string const &name,
	std::string const &target) const
{
	static const FormFactory	factories[] = {
		{"shrubbery creation", createShrubbery},
		{"criacao de arbustos", createShrubbery},
		{"robotomy request", createRobotomy},
		{"pedido de robotomia", createRobotomy},
		{"presidential pardon", createPardon},
		{"perdao presidencial", createPardon}
	};
	AForm					*form;

	for (int i = 0; i < 6; ++i)
	{
		if (name == factories[i].name)
		{
			form = factories[i].create(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
	}
	std::cout << "Intern could not create " << name << std::endl;
	return (NULL);
}
