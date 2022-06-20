#include <typeinfo>
#include <iostream>
#include <string>
#include "Conversion.hpp"

int main(int ac, char **av){
    if (ac != 2){
        std::cout << "Please enter one argument!" << std::endl;
        return 0;
    }
    Conversion convert(av[1]);
    convert.printOut();
    return 0;
}