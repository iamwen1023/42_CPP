#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void):AForm(_name("default SCF"), _signGrade(145), _execGrade(137)), _target("Default"){

}	
ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm(_name("default SCF"), _signGrade(145), _execGrade(137)), _target(target){

}														
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src):AForm(_name(src.getName()), _signGrade(145), _execGrade(137)){
    //this->_target = src.getTarget();
    (*this) = src;
}
ShrubberyCreationForm::~ShrubberyCreationForm(void){

}
ShrubberyCreationForm::ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src){
    this->_target = src.getTarget();
    return (*this);
}
std::string ShrubberyCreationForm::getTarget(void){
    return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
    std::ofstream myfile;
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    if (this->getIfSign() == false)
        throw AForm::FormUnsignedException();
    try {
        myfile.open(this->_target.append("_shrubbery").c_str(), std::fstream::out));
        myfile << "root node"
           << "├─ node1"
           << "│  └─ node11"
           << "└─ node2" <<std::endl;
        myfile.close();
    }
    catch{
        std::cout<< "file can not be open" <<std::endl;
    }
}
