#include "Array.hpp"
#include <iostream>
template <>
Array(void):_array(new T[0], _size(0),{
    std::cout << "default constructor" << std::endl; 
}
Array(unsigned int size):_array(new T[size], _size(size)){
    std::cout << "para constructor" << std::endl;
    std::cout << "array :" << std::endl;
    for (unsigned int i = 0; i <size; i++){
        T *a= new T();
        array[i] = a;
        std::cout << array[i] << " , ";
        delete a;
    }
    std::endl;
}
~Array(void){
    delete [] this->_array;
    std::cout << "destructeurs" << std::endl; 
}														
Array(Array const & src){
    std::cout << "copy constructor" << std::endl;
    (*this) = src ;
}
Array & operator=(Array const & src){
    std::cout << "operator =" << std::endl;
    if ()

}
unsigned int size(void) const{
    return this->_size;

}