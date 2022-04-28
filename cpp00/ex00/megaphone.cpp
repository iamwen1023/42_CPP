#include <cctype>
#include <iostream>

int main(int ac, char **av) 
{
    int i;
    int y;
    char c;

    i = 0;
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (av[++i])
        {
            y = -1;
            while(av[i][++y])
            {
                c = toupper(av[i][y]);
                std::cout << c;
            }
        }
        std::cout << "\n";
    }
    return (0);
}
