#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void): _name("deFault"), _ifSigned(false), _signGrade(150),  _execGrade(150){

}
Form::Form(std::string name, int signGrade, int execGrade):_name(name), _ifSigned(false),_signGrade(signGrade),_execGrade(execGrade){
    if (signGrade > 150 || execGrade > 150)
        throw Form::GradeTooLowException();
    else if (signGrade < 1 || execGrade < 1)
        throw Form::GradeTooHighException();
}												
Form::Form(Form const & src):_name(src.getName()),_signGrade(src.getSignGrade()), _execGrade(src.getExecGrade()){
    *this=src;
}
Form::~Form(void){}
Form & Form::operator=(Form const & src){
    this->_ifSigned = src.getIfSign();
    return (*this);
}
std::string Form::getName()const{
    return this->_name;
}
bool Form::getIfSign()const{
    return this->_ifSigned;
}
int Form::getSignGrade()const{
    return this->_signGrade;
}
int Form::getExecGrade()const{
    return this->_execGrade;
}
void Form::beSigned(Bureaucrat const *bur){
    if (bur->getGrade() > this->getSignGrade())
        throw Form::GradeTooLowException();
    else
        this->_ifSigned = true;
}

char const *	Form::GradeTooHighException::what() const throw()
{
    return ("Grade Too High");
}
char const *	Form::GradeTooLowException::what() const throw()
{
    return ("Grade Too Low");
}
std::ostream &operator<<(std::ostream &o, Form const &i)
{
    o << "name : " << i.getName()
      << ", ifsigned : " << i.getIfSign()
      << ", signGrade :" << i.getSignGrade()
      << ", execGrade :" << i.getExecGrade() << std::endl;
    return o;
}