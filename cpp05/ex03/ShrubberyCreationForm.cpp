#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void):AForm("default SCF",145,137), _target("Default"){

}	
ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm("default SCF",145,137), _target(target){

}														
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src):AForm(src.getName(),145,137){
    (*this) = src;
}
ShrubberyCreationForm::~ShrubberyCreationForm(void){

}
ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src){
    this->_target = src.getTarget();
    return (*this);
}
std::string ShrubberyCreationForm::getTarget(void) const{
    return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
    std::ofstream myfile;
    std::string fileName = this->_target;  
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    if (this->getIfSign() == false)
        throw AForm::FormUnsignedException();
    try {
        myfile.open(fileName.append("_shrubbery").c_str(), std::fstream::out);
        myfile << "root node" <<std::endl
           << "├─ node1" <<std::endl
           << "│  └─ node11" <<std::endl
           << "└─ node2" <<std::endl;
        myfile.close();
    }
    catch(std::exception &e){
        std::cout<< "file can not be open" <<std::endl;
    }
}
