/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:58:03 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/13 14:58:06 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#include "AForm.hpp"

// This forward declaration is required since it is dependent of each other.
class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
		
	public:
		Bureaucrat();
		Bureaucrat(const std::string argName, int argGrade);
        Bureaucrat(Bureaucrat const& srcObj);
        Bureaucrat& operator=(Bureaucrat const & srcObj);
		~Bureaucrat();

		const std::string& getName(void) const;
		int getGrade(void) const;

		void setGrade(int value);

		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(AForm &aform);
		void executeForm(const AForm& aform ) const; 

		class GradeTooHighException : public std::exception {
    		public:
            	virtual const char* what() const throw();
    	};

    	class GradeTooLowException : public std::exception {
        	public:
           		virtual const char* what() const throw();
    	};
};

std::ostream&   operator<<(std::ostream& os, const Bureaucrat& srcObj);

#endif

/**
 * what() - virual function defined in Exception class.
 * So derived class can implement on its own by inheriting Exception class.
*/