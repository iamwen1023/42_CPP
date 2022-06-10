#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>


PresidentialPardonForm::PresidentialPardonForm(void):AForm("default robot",25,5), _target("Default"){

}	
PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm("default robot",25,5), _target(target){

}														
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src):AForm(src.getName(), 25, 5){
    (*this) = src;
}
PresidentialPardonForm::~PresidentialPardonForm(void){

}
PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src){
    this->_target = src.getTarget();
    return (*this);
}
std::string PresidentialPardonForm::getTarget(void) const{
    return this->_target;
}
void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    if (this->getIfSign() == false)
        throw AForm::FormUnsignedException();
    std::cout << this->getTarget() << "has been pardoned by Zaphod Beeblebrox" << std::endl;

}
