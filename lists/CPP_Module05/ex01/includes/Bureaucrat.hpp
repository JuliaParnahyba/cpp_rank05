#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

		static void	validateGrade(int grade);

	public:
		Bureaucrat(void);
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat	&operator=(Bureaucrat const &other);
		~Bureaucrat(void);

		std::string const	&getName(void) const;
		int					getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(Form &form) const;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
