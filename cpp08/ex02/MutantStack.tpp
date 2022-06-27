#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack():std::stack<T>(){
}
template <typename T>
MutantStack<T>::~MutantStack(){
}
template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const & src):std::stack<T>(){
    (*this) = src;
}
template <typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack<T> const & src){
    if (this != &src)
			this->c = src.c;
    return (*this);
}