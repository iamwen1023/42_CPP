#include "Array.hpp"
#include <iostream>
template< typename T >
Array<T>::Array(void):_array(new T[0]), _size(0){
    std::cout << "default constructor" << std::endl; 
}
template< typename T >
Array<T>::Array(unsigned int size):_array(new T[size]), _size(size){
    std::cout << "para constructor" << std::endl;
    T * tmp = new T();
	for (unsigned int i = 0; i < size; i++) {
		this->_array[i] = *tmp;
	}
	delete tmp;
    // for (unsigned int i = 0; i <size; i++){
    //     T *a= new T();
    //     this->_array[i] = *a;
    //     delete a;
    // }
}
template< typename T >
Array<T>::~Array(void){
    if (this->_array)
        delete [] this->_array;
    std::cout << "destructeurs" << std::endl; 
}
template< typename T >													
Array<T>::Array(Array const & src){
    std::cout << "copy constructor" << std::endl;
    //this->_array = new T(*(src._array));
    //(*this) = src ;
    this->_size = src._size;
    this->_array = new T[this->_size];
    for(unsigned int i = 0; i < this->_size; i++){
        this->_array[i] = src._array[i];
    }
}
template< typename T >
Array<T> & Array<T>::operator=(Array const & src){
    std::cout << "operator =" << std::endl;
    if (this == &src)
        return (*this);
    //cpp04/ex01
    if (this->_array) {
		delete [] this->_array;
	}
    this->_size = src._size;
    this->_array = new T[this->_size];
    for(unsigned int i = 0; i < this->_size; i++){
        this->_array[i] = src._array[i];
    }
    return (*this);
}
template< typename T >
T & Array<T>::operator[](unsigned int index){
    //std::cout << "operator []" << std::endl;
    if (index >= this->size())
        throw IndexErrorException();
    return this->_array[index];
}
template< typename T >
unsigned int Array<T>::size(void) const{
    return this->_size;

}