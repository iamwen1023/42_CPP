#include "Conversion.hpp"

Conversion::Conversion(void):_input(NULL){
}
Conversion::Conversion(std::string input):_input(input){

}
Conversion::~Conversion(void){
}														
Conversion::Conversion(Conversion const & src){
    (*this) = src;
}
Conversion & Conversion::operator=(Conversion const & src){
    if (this == &src) 
        return *this;
    this->_input = src.getInput();
    return (*this);
}
std::string Conversion::getInput(void) const{
    return this->_input;
}
void Conversion::toChar() const{
    std::string input = this->getInput();
    long double temp = 0;
    char *str_end = NULL;

    temp = std::strtold(input.c_str(), &str_end);
    std::cout << "char: ";
    if (this->ifNanOrInf() == true)
        throw Conversion::ImpossibleException();
    else if (errno == ERANGE || temp > 255 || temp < 0)
        throw Conversion::ImpossibleException();
    else if (input.length() == 1 && !isdigit(input.c_str()[0])){
        if (!isprint(input.c_str()[0]))
			throw Conversion::NonDisplayableException();
		else
			std::cout << static_cast<char>(input.c_str()[0]) << std::endl;
    }
    else if (temp < 32 || temp > 126)
        throw Conversion::NonDisplayableException();
    else
        std::cout << static_cast<char>(temp) << std::endl;
}
void Conversion::toInt() const{
    std::string input = this->getInput();
    long double temp = 0;
    char *str_end = NULL;

    temp = std::strtold(input.c_str(), &str_end);
    std::cout << "int: ";
    if (this->ifNanOrInf() == true)
        throw Conversion::ImpossibleException();
    else if ( errno == ERANGE || temp > std::numeric_limits<int>::max() || temp < std::numeric_limits<int>::min())
        throw Conversion::ImpossibleException();
    else if (input.length() == 1 && !isdigit(input.c_str()[0]))
		std::cout << static_cast<int>(input.c_str()[0]) << std::endl;
    else
        std::cout << static_cast<int>(temp) << std::endl;
    
}
void Conversion::toFloat() const{
    std::string input = this->getInput();
    long double temp = 0;
    char *str_end = NULL;

    temp = std::strtold(input.c_str(), &str_end);
    std::cout << "float: ";
    if (input.compare("-inf") || input.compare("+inf") || input.compare("nan"))
        std::cout << input << "f" << std::endl;
    if (input.compare("-inff") || input.compare("+inff") || input.compare("nanf"))
        std::cout << input  << std::endl;
    else if ( errno == ERANGE || temp > std::numeric_limits<float>::max() || temp < std::numeric_limits<float>::min())
        throw Conversion::ImpossibleException();
    else if (input.length() == 1 && !isdigit(input.c_str()[0]))
		std::cout << static_cast<float>(input.c_str()[0]) << std::endl;
    else
        std::cout << std::setprecision(1) << std::fixed << static_cast<float>(temp) << "f" << std::endl;


}

void Conversion::toDouble() const{
    long double temp = 0;
    char *str_end = NULL;

    temp = std::strtold(this->getInput().c_str(), &str_end);
    if ((temp < std::numeric_limits<double>::min()) || 
        (temp > std::numeric_limits<double>::max()) || 
        errno == ERANGE)
        std::cout << "overflow" << temp << std::endl;
    std::cout << "temp :" << temp << std::endl;
    std::cout << "temp :|" << str_end <<"|" << std::endl;
    temp = std::strtold(str_end, &str_end);
    std::cout << "temp :" << temp << std::endl;
    std::cout << "temp :|" << str_end <<"|" << std::endl;
}


void Conversion::printOut() const{
    try {
        this->toChar();

    } catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
    try {
        this->toInt();

    } catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
    try {
        this->toFloat();

    } catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
    
}

const char *Conversion::NonDisplayableException::what() const throw() {
	return ("Non displayable");
}

const char *Conversion::ImpossibleException::what() const throw() {
	return ("impossible");
}

bool Conversion::ifNanOrInf() const{
    std::string temp = this->getInput();
    if (!temp.compare("-inf") || !temp.compare("+inf") || !temp.compare("nan") ||
        !temp.compare("-inff") || !temp.compare("+inff") || !temp.compare("nanf"))
        return true;
    else
        return false;
}