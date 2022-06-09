 #include "Bureaucrat.hpp"
 #include "Form.hpp"

Bureaucrat::Bureaucrat(void):name("default"), grade(150)
{
     std::cout << "Default constructor called" << std::endl;
}																
Bureaucrat::Bureaucrat(Bureaucrat const & src):name(src.getName())
{
    std::cout << "copy constructor called" << std::endl;
    *this=src;
}
Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Destructor called" << std::endl;
}
Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
    if (this == &src) 
        return *this;
    this->grade = src.getGrade();
    return (*this);
}
Bureaucrat::Bureaucrat(std::string name, int grade):name(name), grade(grade)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    std::cout << "Parameter constructor called" << std::endl;
}
std::string Bureaucrat::getName() const
{
    return this->name;
}
int Bureaucrat::getGrade() const
{
    return this->grade;
}
void Bureaucrat::increGrade()
{
    if (this->grade == 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade -= 1;    
}
void Bureaucrat::decreGrade()
{
    if (this->grade == 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade += 1;  

}
char const *	Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade Too High");
}
char const *	Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade Too Low");
}
void Bureaucrat::signForm(Form &form)
{
    try {
        form.beSigned(this);
        std::cout << this->name << " signed " << form.getName() << std::endl;

    }
    catch(Form::GradeTooLowException &e){
        std::cout << this->name <<" couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
    catch(std::exception &e){
        std::cout << this->name <<" couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
        
}
std::ostream & operator<<(std::ostream & o, Bureaucrat const & input)
{
    o << input.getName() << ", bureaucrat grade " << input.getGrade() << "." << std::endl ;
    return o; 
}