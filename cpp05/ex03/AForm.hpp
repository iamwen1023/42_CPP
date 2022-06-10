#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <string>
class Bureaucrat;

class AForm
{
    public:
        AForm(void);
        AForm(std::string name, int signGrade, int execGrade);															
	    AForm(AForm const & src);
        virtual ~AForm(void);
        AForm & operator=(AForm const & src);
        std::string getName(void) const;
        bool getIfSign(void) const;
        int getSignGrade(void) const;
        int getExecGrade(void) const;
        void beSigned(Bureaucrat const *Bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;

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
        class FormUnsignedException : public std::exception
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
std::ostream  &operator<<(std::ostream &o, AForm const & input);

#endif