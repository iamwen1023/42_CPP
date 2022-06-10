#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  /* time */

RobotomyRequestForm::RobotomyRequestForm(void):AForm("default robot",72, 45), _target("Default"){

}	
RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("default robot", 72, 45), _target(target){

}														
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src):AForm(src.getName(), 72,45){
    (*this) = src;
}
RobotomyRequestForm::~RobotomyRequestForm(void){

}
RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src){
    this->_target = src.getTarget();
    return (*this);
}
std::string RobotomyRequestForm::getTarget(void) const{
    return this->_target;
}
void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    if (this->getIfSign() == false)
        throw AForm::FormUnsignedException();
    srand (time(NULL));
    if (rand() % 2 == 0)
        std::cout << "the lobotomy is successful" << std::endl;
    else
        std::cout << "the lobotomy is failed" << std::endl;

}
