#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class PhoneBook
{
    public:
        PhoneBook(void);
		~PhoneBook(void);
        void menu();
        void add_contact(Contact *Contact) const;
        void show_contacts(void);
        void search_contact(void);
        void show_contact_detail(int index);

    private:
        Contact ContactArr[8];
};
#endif