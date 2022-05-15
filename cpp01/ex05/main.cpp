#include "Harl.hpp"

int main()
{
    Harl New_Harl;
    New_Harl.complain("DEBUG");
    New_Harl.complain("INFO");
    New_Harl.complain("WARNING");
    New_Harl.complain("warning");
    New_Harl.complain("ERROR");
    New_Harl.complain("infocc");

    return 0;
}