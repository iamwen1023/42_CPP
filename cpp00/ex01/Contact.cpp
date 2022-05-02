#include "main.hpp"

Contact::Contact()
{
    this->first_name="";
    this->last_name="";
    this->nick_name="";
    this->phone_number="";
    this->darkest_secret="";
    return ;
}
Contact::~Contact()
{
    return ;
}

void Contact::set_first_name(std::string name)
{
    this->first_name = name;
}
void Contact::set_last_name(std::string name)
{
    this->last_name = name;
}
void Contact::set_nick_name(std::string name)
{
    this->nick_name = name;
}
void Contact::set_phone_number(std::string nbr)
{
    this->phone_number = nbr;
}
void Contact::set_darkest_secret(std::string nbr)
{
    this->darkest_secret = nbr;
}
std::string Contact::get_first_name(void) const
{
    return this->first_name;
}
std::string Contact::get_last_name(void) const
{
    return this->last_name;
}
std::string Contact::get_nick_name(void) const
{
    return this->nick_name;
}
std::string Contact::get_phone_number(void) const
{
    return this->phone_number;
}
std::string Contact::get_darkest_secret(void) const
{
    return this->darkest_secret;
}