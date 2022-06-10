#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
#include<string>
class Bureaucrat;
class PresidentialPardonForm: public AForm{
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);															
	    PresidentialPardonForm(PresidentialPardonForm const & src);
        ~PresidentialPardonForm(void);
        PresidentialPardonForm & operator=(PresidentialPardonForm const & src);
        std::string getTarget(void) const;
        void execute(Bureaucrat const & executor) const;
    private:
        std::string _target;

};
#endif