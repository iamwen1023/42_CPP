#include "Span.hpp"

Span::Span(void){}
Span::Span(unsigned int num):_num(num){
    this->_vect.reserve(num);
}
Span::~Span(void){
    this->_vect.clear();
}
Span::Span(Span const & src){
    (*this) = src;
}
Span & Span::operator=(Span const & src){
	this->_vect.reserve(src._vect.capacity());
	this->_vect.assign(src._vect.begin(), src._vect.end());
	return (*this);
}
void Span::addNumber(int number){
    if (this->_vect.size() == this->_num || !this->_num)
        throw Span::SpanIsFullException();
    this->_vect.push_back(number);
}

void Span::addNumber(){
    if (this->_vect.size() == this->_num || !this->_num)
        throw Span::SpanIsFullException();
    srand(time(NULL));
    for (int i = this->_vect.size(); i < (int)this->_vect.capacity(); ++i){
        int number = rand()  % 100 + 1; // in the range 1 to 100
        this->_vect.push_back(number);
    }
}

int Span::shortestSpan() const{
    if (this->_vect.size() <= 1)
        throw Span::NoSpanCanBeFoundException();
    std::vector<int> diff(this->_vect.size());
    std::vector<int> sortVect(this->_vect);
    std::sort(sortVect.begin(), sortVect.end());
    
    // for (int i = 0; i < (int)sortVect.size(); i++)
    //     std::cout << sortVect[i] << ",";
    // std::cout << "\n";

    std::adjacent_difference(sortVect.begin(), sortVect.end(), diff.begin());
    
    // for (int i = 0; i < (int)diff.size(); i++)
    //     std::cout << diff[i] << ",";
    // std::cout << "\n";

    return (*std::min_element(diff.begin() + 1, diff.end()));
}
int Span::longestSpan() const{
    if (this->_vect.size() <= 1)
        throw Span::NoSpanCanBeFoundException();
    std::vector<int> sortVect(this->_vect);
    std::sort(sortVect.begin(), sortVect.end());
    return (sortVect.back() -  sortVect.front());
}
void	Span::printContainer() const{
    for (int i = 0; i < (int)this->_vect.size(); i++)
        std::cout << this->_vect[i] << ",";
    std::cout << "\n";
}

char const *	Span::SpanIsFullException::what() const throw()
{
    return ("Span is full");
}
char const *	Span::NoSpanCanBeFoundException::what() const throw()
{
    return ("No Span Can Be Found");
}
