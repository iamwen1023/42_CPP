#ifndef ARRAY_HPP
#define ARRAY_HPP
template <typename T>
class Array{
    public:
        Array(void);
        Array(unsigned int size);
        ~Array(void);														
	    Array(Array const & src);
        Array & operator=(Array const & src);
        T & operator[](unsigned int index);
        unsigned int size(void) const;
    private: 
        T *_array;
        unsigned int _size;

};
class IndexErrorException : public std::exception
{
    public:
        virtual const char* what() const throw();
};
#include "Array.tpp"
#endif