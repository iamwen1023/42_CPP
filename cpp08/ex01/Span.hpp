#ifndef SPAN_HPP
#define SPAN_HPP
#include <exception>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class Span{
    public:
        Span(unsigned int num);
        ~Span(void);
        Span(Span const & src);
        Span & operator=(Span const & src);
        void addNumber(int number);
        void addNumber(void);
        int shortestSpan() const;
        int longestSpan() const;
        void printContainer() const;
        class SpanIsFullException : public std::exception{
        public:
            virtual const char* what() const throw();
        };
        class NoSpanCanBeFoundException : public std::exception{
        public:
            virtual const char* what() const throw();
        };
    private:
        Span(void);
        std::vector<int> _vect;
        unsigned int _num;

};



#endif