#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class PhoneBook
{
    public:
        PhoneBook(void);
		~PhoneBook(void);
        void menu();
        int add_contact(Contact *Contact);
        int show_contacts(void);
        int search_contact(void);
        void show_contact_detail(int index);

    private:
        Contact ContactArr[8];
};
#endif