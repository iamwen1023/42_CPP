#include "Harl.hpp"

int main(int ac, char** av)
{
    Harl New_Harl;

    if (ac != 2)
    {
        std::cout << "Please enter a level.\n";
        return 0;
    }  
    New_Harl.harlFilter(av[1]);
    return 0;
}