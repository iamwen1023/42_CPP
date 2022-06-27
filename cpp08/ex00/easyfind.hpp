#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
//#include <iterator>
#include <algorithm>

class NotFoundException : public std::exception{
    public:
            virtual const char* what() const throw();
};

template< typename T >
void easyfind(T &contain, int toFind){
    typename T::iterator	i = std::find(contain.begin(), contain.end(), toFind);
    if (i == contain.end())
        throw NotFoundException();
    std::cout << "Found :" << *i <<  ", index :" << std::distance(contain.begin(), i) <<std::endl; 
}

template <typename T>
void	printContainer(T container) {
    for (typename T::iterator it = container.begin(); it!=container.end(); ++it){
        std::cout << *it << ",";
    }
    std::cout << "\n";
}
#endif
