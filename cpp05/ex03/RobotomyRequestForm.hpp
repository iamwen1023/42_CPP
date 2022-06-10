#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include<string>
class Bureaucrat;
class RobotomyRequestForm: public AForm{
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);															
	    RobotomyRequestForm(RobotomyRequestForm const & src);
        ~RobotomyRequestForm(void);
        RobotomyRequestForm & operator=(RobotomyRequestForm const & src);
        std::string getTarget(void) const;
        void execute(Bureaucrat const & executor) const;
    private:
        std::string _target;

};
#endif