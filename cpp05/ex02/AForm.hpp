/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:57:47 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/13 14:57:47 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define AFORM_H

#include "Bureaucrat.hpp"

// This forward declaration is required since it is dependent of each other.
class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool is_signed;
		const int sign_grade;
		const int exec_grade;

	public:
		AForm();
		AForm(const AForm &src);
		AForm(const std::string name, int sign_grade, int exec_grade);
		AForm &operator=(const AForm &src);
		virtual ~AForm();

		const	std::string	getName(void) const;
		bool	getIsSignedBool(void) const;
		int		getSignGrade(void) const;
		int		getExecGrade(void) const;

		void	beSigned(Bureaucrat &signer);

		virtual	void	execute(const Bureaucrat& executor) const = 0;

	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class NotSignedException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream	&operator<<(std::ostream &os, const AForm *srcObj);

#endif