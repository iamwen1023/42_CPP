// #include <iostream>
// #include <string.h>
// #include "PhoneBook.hpp"
#include "main.hpp"

PhoneBook::PhoneBook()
{
    std::cout << "PhoneBook construict" << std::endl;
    return ;
}
PhoneBook::~PhoneBook()
{
    std::cout << "PhoneBook DEconstruict" << std::endl;
    return ;
}

void PhoneBook::add_contact(Contact Contact)
{
    //Contact NewContact;
    char cmd[250];

    (void)index;
    std::cout << "Firstname:"<< std::endl;
    std::cin >> cmd;
    Contact.set_first_name(cmd);




}
void PhoneBook::menu(Contact ContactArr[8])
{
    char cmd[7];
    int index = 0;
    while (1)
    {
        std::cout << "Welcome to PhoneBook, pleass enter: ADD, SEARCH or EXIT"<< std::endl;
        std::cin >> cmd;
        std::cout << cmd << std::endl;
        if (!strcmp(cmd, "ADD"))
        {
            if (index > 0)
                index++;
            if (index == 7)
                index = 0;
            PhoneBook::add_contact(ContactArr[index]);
            std::cout << "in add" << std::endl;
            std::cout << ContactArr[index].get_first_name() << std::endl;
            std::cout << "in add" << std::endl;

        }
        else if(!strcmp(cmd, "SEARCH"))
        {
            std::cout << "in search" << std::endl;
        }
        else if(!strcmp(cmd, "EXIT"))
        {
            std::cout << "in exit" << std::endl;
            break;
        }
    }
    std::cout << "EXIT"<< std::endl;
    //return 0;

}


// class Contact
// {
//    public:
//       double contacts[8];   // 长度

// };

// class PhoneBook
// {
//    public:
//       double contacts[8];
// };

// int main(void)
// {
//     char cmd[7];
//     while (1)
//     {
//         std::cout << "Welcome to PhoneBook, pleass enter: ADD, SEARCH or EXIT"<< std::endl;
//         std::cin >> cmd;
//         std::cout << cmd << std::endl;
//         if (!strcmp(cmd, "ADD"))
//         {

//         }
//         else if(!strcmp(cmd, "SEARCH"))
//         {

//         }
//         else if(!strcmp(cmd, "EXIT"))
//         {
//             break;
//         }
//     }
//     std::cout << "EXIT"<< std::endl;
//     return 0;
// }