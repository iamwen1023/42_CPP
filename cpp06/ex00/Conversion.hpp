#ifndef CONVERSION_HPP
#define CONVERSION_HPP
#include <stdlib.h>
#include <string>
#include <iostream>
#include <exception>
#include <iomanip>
#include <limits>

class Conversion{
    public:
        Conversion(void);
        Conversion(std::string input);
        ~Conversion(void);														
	    Conversion(Conversion const & src);
        Conversion & operator=(Conversion const & src);
        std::string getInput(void) const;
        void toChar() const;
		void toInt() const;
		void toFloat() const;
		void toDouble() const;
        void printOut() const;
        bool ifNanOrInf() const;
        bool checkChar() const;
        bool checkInt() const;
        bool checkFloat() const;
        bool checkDouble() const;
        class NonDisplayableException : public std::exception {
			public:
				virtual char const * what() const throw();
		};
		class ImpossibleException : public std::exception {
			public:
				virtual char const * what() const throw();
		};
    private:
        std::string _input;
};


#endif