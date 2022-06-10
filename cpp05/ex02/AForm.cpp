#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void): _name("deFault"), _ifSigned(false), _signGrade(150),  _execGrade(150){

}
AForm::AForm(std::string name, int signGrade, int execGrade):_name(name), _ifSigned(false),_signGrade(signGrade),_execGrade(execGrade){
    if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
    else if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
}												
AForm::AForm(AForm const & src):_name(src.getName()),_signGrade(src.getSignGrade()), _execGrade(src.getExecGrade()){
    *this=src;
}
AForm::~AForm(void){}
AForm & AForm::operator=(AForm const & src){
    this->_ifSigned = src.getIfSign();
    return (*this);
}
std::string AForm::getName()const{
    return this->_name;
}
bool AForm::getIfSign()const{
    return this->_ifSigned;
}
int AForm::getSignGrade()const{
    return this->_signGrade;
}
int AForm::getExecGrade()const{
    return this->_execGrade;
}
void AForm::beSigned(Bureaucrat const *bur){
    if (this->_ifSigned == true)
        throw AForm::FormalreadysignedException();
    if (bur->getGrade() > this->getSignGrade())
        throw AForm::GradeTooLowException();
    else
        this->_ifSigned = true;
}

char const *	AForm::GradeTooHighException::what() const throw()
{
    return ("Grade Too High");
}
char const *	AForm::GradeTooLowException::what() const throw()
{
    return ("Grade Too Low");
}
char const *	AForm::FormUnsignedException::what() const throw()
{
    return ("Form has not been signed");
}
char const *	AForm::FormalreadysignedException::what() const throw()
{
    return ("Form has already been signed");
}
std::ostream &operator<<(std::ostream &o, AForm const &i)
{
    o << "name : " << i.getName()
      << ", ifsigned : " << i.getIfSign()
      << ", signGrade :" << i.getSignGrade()
      << ", execGrade :" << i.getExecGrade() << std::endl;
    return o;
}