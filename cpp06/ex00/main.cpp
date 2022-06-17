#include <typeinfo>
#include <iostream>
#include <string>
#include "Conversion.hpp"

int main(int ac, char **av){
    // char *a="hidufz9";
    // std::cout << typeid(a).name() << std::endl;
    if (ac != 2){
        std::cout << "Please enter one argument!" << std::endl;
        return 0;
    }
    Conversion convert(av[1]);
    convert.printOut();
    // std::string a = av[1];
    // std::cout << "string :" << a << std::endl;
    // std::cout << "stoi(str) :" << typeid(av[1]).name() << std::endl;
    return 0;
}