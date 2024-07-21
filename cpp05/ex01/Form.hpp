/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:57:11 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/13 14:57:11 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

// This forward declaration is required since it is dependent of each other.
class Bureaucrat;

class Form
{
	private:
		const std::string 	name;
		bool 				is_signed;
		const 	int 		sign_grade;
		const 	int			exec_grade;

	public:
		Form();
		Form(const std::string name, int sign_grade, int exec_grade);
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form();

		const std::string	getName(void) const;
		bool 				getIsSignedBool(void) const;
		int 				getSignGrade(void) const;
		int 				getExecGrade(void) const;

		void 				beSigned(Bureaucrat &signer);

	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &os, const Form *srcObj);

#endif