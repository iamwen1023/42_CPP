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
    else if (temp > 255 || temp < 0)
        throw Conversion::ImpossibleException();
    else if (input.length() == 1 && !isdigit(input.c_str()[0])){
        if (!isprint(input.c_str()[0]))
			throw Conversion::NonDisplayableException();
		else
			std::cout << static_cast<char>(input.c_str()[0]) << std::endl;
    }
    else if (!isprint(temp))
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
    else if (input.length() == 1 && !isdigit(input.c_str()[0]))
		std::cout << static_cast<int>(input.c_str()[0]) << std::endl;
    else if (temp > std::numeric_limits<int>::max() || temp < std::numeric_limits<int>::min())
        throw Conversion::ImpossibleException();
    else
        std::cout << static_cast<int>(temp) << std::endl;
    
}
void Conversion::toFloat() const{
    std::string input = this->getInput();
    long double temp = 0;
    char *str_end = NULL;

    temp = std::strtold(input.c_str(), &str_end);
    std::cout << "float: ";
    if (!input.compare("-inf") || !input.compare("+inf") || !input.compare("nan"))
        std::cout << input << "f" << std::endl;
    else if (!input.compare("-inff") || !input.compare("+inff") || !input.compare("nanf"))
        std::cout << input  << std::endl;
    else if (input.length() == 1 && !isdigit(input.c_str()[0]))
		std::cout << std::setprecision(1) << std::fixed << static_cast<float>(input.c_str()[0]) << "f" << std::endl;
    else if (temp > std::numeric_limits<float>::max() || temp < -std::numeric_limits<float>::max())
        throw Conversion::ImpossibleException();
    else
        std::cout << std::setprecision(1) << std::fixed << static_cast<float>(temp) << "f" << std::endl;
}

void Conversion::toDouble() const{
    std::string input = this->getInput();
    long double temp = 0;
    char *str_end = NULL;

    temp = std::strtold(input.c_str(), &str_end);
    std::cout << "double: ";
    if (!input.compare("-inf") || !input.compare("+inf") || !input.compare("nan"))
        std::cout << input  << std::endl;
    else if (!input.compare("-inff") || !input.compare("+inff") || !input.compare("nanf"))
        std::cout << input.substr(0, input.length() - 1)  << std::endl;
        else if (input.length() == 1 && !isdigit(input.c_str()[0]))
		std::cout << static_cast<double>(input.c_str()[0]) << std::endl;
    else if (temp > std::numeric_limits<double>::max() || temp < -std::numeric_limits<double>::max())
        throw Conversion::ImpossibleException();
    else
        std::cout << std::setprecision(1) << std::fixed <<  static_cast<double>(temp) << std::endl;
}

bool Conversion::checkChar() const{
    std::string input = this->getInput();
    if (input.length() == 1 && isprint(input.c_str()[0])){
        return true;
    }
    return false;
}

bool Conversion::checkInt() const{
    std::string input = this->getInput();
    size_t i = 0;
    if (input.c_str()[i] == '+' || input.c_str()[i] == '-' )
		i++;
	while (i < input.length())
	{
		if (isdigit(input.c_str()[i]))
			i++;
		else
			return false;
	}
    return true;
}
bool Conversion::checkFloat() const{
    std::string input = this->getInput();
    size_t i = 0;
    int count = 0;
    if (!input.compare("-inff") || !input.compare("+inff") || !input.compare("nanf"))
		return true;
    // if (input.c_str()[input.length() -1] != 'f')
    //     return false;
    if (input.c_str()[i] == '+' || input.c_str()[i] == '-' )
		i++;
    while (i < input.length())
	{
        if (isdigit(input.c_str()[i]))
			i++;
		else if (input.c_str()[i] == '.')
        {
            count++;
            if ( i+1 == input.length() || count > 1 || i+2 == input.length())
                return false;
            i++;
        }
        else if (i + 1 == input.length() && input.c_str()[i] == 'f')
            return true;
        else
            return false;
        
    }
    return true;
}
bool Conversion::checkDouble() const{
    std::string input = this->getInput();
    size_t i = 0;
    int count = 0;
    if (!input.compare("-inf") || !input.compare("+inf") || !input.compare("nan"))
		return true;
    if (input.c_str()[i] == '+' || input.c_str()[i] == '-' )
		i++;
    while (i < input.length())
	{
        if (isdigit(input.c_str()[i]))
			i++;
		else if (input.c_str()[i] == '.')
        {
            count++;
            if ( i+1 == input.length() || count > 1)
                return false;
            i++;
        }
        else
            return false;
    }
    return true;
}


void Conversion::printOut() const{
    if (this->checkChar() == false && this->checkDouble() == false && this->checkFloat() == false && this->checkInt() == false)
    {
        // throw Conversion::ImpossibleException();
        std::cout << "Please enter a parameter with the following type: char, int, float or double." << std::endl;
        return ;
    }
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
    try {
        this->toDouble();

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