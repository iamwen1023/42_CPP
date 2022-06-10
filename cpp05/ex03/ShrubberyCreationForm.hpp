#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include<string>
class Bureaucrat;
class ShrubberyCreationForm: public AForm{
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string target);															
	    ShrubberyCreationForm(ShrubberyCreationForm const & src);
        ~ShrubberyCreationForm(void);
        ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src);
        std::string getTarget(void) const;
        void execute(Bureaucrat const & executor) const;
    private:
        std::string _target;

};
#endif