#include "Contact.hpp"

Contact::Contact()
{
    std::cout << "Contact construict" << std::endl;
    return ;
}
Contact::~Contact()
{
    std::cout << "Contact DEconstruict" << std::endl;
    return ;
}

void Contact::set_first_name(std::string name)
{
    this->first_name = name;
}
void set_last_name(std::string name)
{
    this->last_name = name;
}
void set_nick_name(std::string name)
{
    this->nick_name = name;
}
void set_phone_number(std::string nbr)
{
    this->phone_number = nbr;
}
void set_darkest_secret(std::string name)
{
    this->darkest_secret = nbr;
}
std::string get_first_name(void) const
{
    return this->first_name;
}
std::string get_last_name(void) const
{
    return this->last_name;
}
std::string get_nick_name(void) const
{
    return this->nick_name;
}
std::string get_phone_number(void) const
{
    return this->phone_number;
}
std::string get_darkest_secret(void) const
{
    return this->darkest_secret;
}