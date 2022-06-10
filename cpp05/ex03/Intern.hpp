#ifndef INTERN_HPP
#define INTERN_HPP
#include <string.h>
#include <iostream>
class AForm;
class Intern{
    public:
        Intern(void);														
	    Intern(Intern const & src);
        ~Intern(void);
        Intern & operator=(Intern const & src);
        AForm *makeForm(std::string formName, std::string target) const;
        AForm *makePPF(std::string target) const;
        AForm *makeRRF(std::string target) const;
        AForm *makeSCF(std::string target) const;
        class TargetEmptyException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class InvalidFormException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
    

};
#endif