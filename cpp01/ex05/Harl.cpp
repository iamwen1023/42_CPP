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
void Harl::complain( std::string level )
{
    void (Harl::*fcnPtr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string fcnName[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int index(0);
    while (index < 4)
    {
        if (level.compare(fcnName[index]) == 0)
        {
            (this->*fcnPtr[index])();
            return ;
        }
        index++;
    } 
}

void Harl::debug( void )
{
    std::cout<< "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\n";
}
void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!\n";
}
void Harl::warning( void )
{
    std::cout<< "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
}
void Harl::error( void )
{
    std::cout<< "This is unacceptable! I want to speak to the manager now.\n";
}