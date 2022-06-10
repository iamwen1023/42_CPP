#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
class Bureaucrat
{
    public:
        Bureaucrat(void);																
	    Bureaucrat(Bureaucrat const & src);
        ~Bureaucrat(void);
        Bureaucrat & operator=(Bureaucrat const & src);
        Bureaucrat(std::string name, int grade);
        std::string getName(void) const;
        int getGrade(void) const;
        void increGrade(void);
        void decreGrade(void);
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
        
    private:
        const std::string name;
        int grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & i);
#endif