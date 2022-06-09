#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
class Form;
class Bureaucrat
{
    public:
        Bureaucrat(void);																
	    Bureaucrat(Bureaucrat const & src);
        ~Bureaucrat(void);
        Bureaucrat & operator=(Bureaucrat const & src);
        Bureaucrat(std::string name, int grade);
        std::string getName() const;
        int getGrade() const;
        void increGrade();
        void decreGrade();
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        void signForm(Form &form) ;
        void executeForm(Form const & form) ;
        
    private:
        const std::string name;
        int grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & i);
#endif