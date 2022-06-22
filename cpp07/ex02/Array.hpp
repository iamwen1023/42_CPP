#ifndef ARRAY_HPP
#define ARRAY_HPP
template <typename T>
class Array{
    Array();
    Array(size_t size);
    ~Array(void);														
	Array(Array const & src);
    Array & operator=(Array const & src);


};
#endif