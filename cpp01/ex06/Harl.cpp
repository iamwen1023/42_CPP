#include "Harl.hpp"

Harl::Harl()
{
    //std::cout<< "harl constructor"<< std::endl;
    return ;
}
Harl::~Harl()
{
    //std::cout<< "harl DEconstructor"<< std::endl;
    return ;
}
void Harl::harlFilter( std::string level )
{
    void (Harl::*fcnPtr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string fcnName[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int index(0);
    while (index < 4)
    {
        if (level.compare(fcnName[index]) == 0)
            break ;
        index++;
    }
    switch (index)
    {
        case 0:
            (this->*fcnPtr[0])();
        case 1:
            (this->*fcnPtr[1])();
        case 2:
            (this->*fcnPtr[2])();
        case 3:
            (this->*fcnPtr[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
    }
    
}

void Harl::debug( void )
{
    std::cout<<"[ DEBUG ]"<< std::endl;
    std::cout<< "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI just love it!\n";
}
void Harl::info( void )
{
    std::cout<<"[ INFO ]"<< std::endl;
    std::cout << "I cannot believe adding extra bacon cost more money.\nYou don’t put enough!\nIf you did I would not have to ask for it!\n";
}
void Harl::warning( void )
{
    std::cout<<"[ WARNING ]"<< std::endl;
    std::cout<< "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n";
}
void Harl::error( void )
{
    std::cout<<"[ ERROR ]"<< std::endl;
    std::cout<< "This is unacceptable!\nI want to speak to the manager now.\n";
}