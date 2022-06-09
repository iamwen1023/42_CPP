#include "PresidentialPardonForm.hpp"
#include <iostream>


PresidentialPardonForm::PresidentialPardonForm(void):AForm(_name("default robot"), _signGrade(72), _execGrade(45)), _target("Default"){

}	
PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm(_name("default robot"), _signGrade(25), _execGrade(5)), _target(target){

}														
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src):AForm(_name(src.getName()), _signGrade(25), _execGrade(5)){
    (*this) = src;
}
PresidentialPardonForm::~PresidentialPardonForm(void){

}
PresidentialPardonForm::PresidentialPardonForm & operator=(PresidentialPardonForm const & src){
    this->_target = src.getTarget();
    return (*this);
}
std::string PresidentialPardonForm:getTarget(void){
    return this->_target;
}
void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    if (this->getIfSign() == false)
        throw AForm::FormUnsignedException();
    std::cout << this->getTarget() << "has been pardoned by Zaphod Beeblebrox" << std::endl;

}
