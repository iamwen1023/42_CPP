#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void){

}														
Intern::Intern(Intern const & src){
    (*this) = src;
}
Intern::~Intern(void){

}
Intern & Intern::operator=(Intern const & src){
    (void)src;
    return (*this);
}
char const *	Intern::TargetEmptyException::what() const throw()
{
    return ("TargetName is empty");
}
char const *	Intern::InvalidFormException::what() const throw()
{
    return ("Invalid FormName");
}

AForm *Intern::makeForm(std::string formName, std::string target) const{
    std::string formNameList[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    AForm*	(Intern::*ft_ptr[3])(std::string) const = {
		&Intern::makePPF, &Intern::makeRRF, &Intern::makeSCF
	};
    if (target.empty())
        throw Intern::TargetEmptyException();
    else{
        for(int i = 0; i < 3; i++){
            if(formNameList[i].compare(formName) == 0)
                return ((this->*ft_ptr[i])(target));
        }
    }
    throw Intern::InvalidFormException();
}
AForm *Intern::makePPF(std::string target) const{
    return (new PresidentialPardonForm(target));
}
AForm *Intern::makeRRF(std::string target) const{
    return (new RobotomyRequestForm(target));
}
AForm *Intern::makeSCF(std::string target) const{
    return (new ShrubberyCreationForm(target));
}