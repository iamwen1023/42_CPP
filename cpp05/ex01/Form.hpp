#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>
class Bureaucrat;

class Form
{
    public:
        Form(void);
        Form(std::string name, int signGrade, int execGrade);															
	    Form(Form const & src);
        ~Form(void);
        Form & operator=(Form const & src);
        std::string getName(void) const;
        bool getIfSign(void) const;
        int getSignGrade(void) const;
        int getExecGrade(void) const;
        void beSigned(Bureaucrat const *Bureaucrat);

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
        const std::string _name;
        bool _ifSigned;
        const int _signGrade;
        const int _execGrade; 

};
std::ostream  &operator<<(std::ostream &o, Form const & input);

#endif