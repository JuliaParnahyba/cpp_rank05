#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;

		static void	validateGrade(int grade);

	public:
		Form(void);
		Form(std::string const &name, int signGrade, int executeGrade);
		Form(Form const &other);
		Form	&operator=(Form const &other);
		~Form(void);

		std::string const	&getName(void) const;
		bool				getIsSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecuteGrade(void) const;
		void				beSigned(Bureaucrat const &bureaucrat);

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

std::ostream	&operator<<(std::ostream &out, Form const &form);

#endif
