#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include <iostream>
//#include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook(void);
		~PhoneBook(void);
        void menu(Contact ContactArr[8]);
        void add_contact(int index);
        void search_contact();

    private:
        Contact ContactArr[8];

};
#endif