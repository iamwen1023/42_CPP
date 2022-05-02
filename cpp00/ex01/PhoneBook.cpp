#include "main.hpp"

PhoneBook::PhoneBook()
{
    //std::cout << "PhoneBook construict" << std::endl;
    return ;
}
PhoneBook::~PhoneBook()
{
    //std::cout << "PhoneBook DEconstruict" << std::endl;
    return ;
}

bool is_digits(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

bool is_Alpha(const std::string str)
{
    int i = 0;

    while (str[i])
    {
        if (!isalpha(str[i]))
            return (false);
        i++;
    }
    return (true);
}

bool is_print(const std::string str)
{
    int i = 0;

    while (str[i])
    {
        if (!isprint(str[i]))
            return (false);
        i++;
    }
    return (true);
}

void PhoneBook::add_contact(Contact *Contact)
{
    std::string content("");

    while(content.empty() == true || Contact->get_first_name().empty() == true )
    {
        std::cout << "Firstname:"<< std::endl;
        std::getline(std::cin, content);
        if (content.empty() == true || !is_Alpha(content))
        {
            std::cout << "Firstname should not be empty and be alphabetic characters."<< std::endl;
            content.clear();
        }
        else
            Contact->set_first_name(content);
    }
    content.clear();
    while(content.empty() == true || Contact->get_last_name().empty() == true)
    {
        std::cout << "Lastname:"<< std::endl;
        std::getline(std::cin, content);
        if (content.empty() == true || is_Alpha(content) == false)
        {
            std::cout << "Lastname should not be empty and be alphabetic characters."<< std::endl;
            content.clear();
        }
        else
            Contact->set_last_name(content);
    }
    while(content.empty() == true || Contact->get_nick_name().empty() == true)
    {
        std::cout << "Nickname:"<< std::endl;
        std::getline(std::cin, content);
        if (content.empty() == true || is_Alpha(content) == false)
        {
            std::cout << "Nickname should not be empty and be alphabetic characters."<< std::endl;
            content.clear();
        }
        else
            Contact->set_nick_name(content);
    }
    content.clear();
    while(content.empty() == true || Contact->get_phone_number().empty() == true)
    {
        std::cout << "Phone number:"<< std::endl;
        std::getline(std::cin, content);
        if (content.empty() == true || is_digits(content) == false)
        {
            std::cout << "Phone number should not be empty and be numeric characters."<< std::endl;
            content.clear();
        }
        else
            Contact->set_phone_number(content);
    }
    content.clear();
    while(content.empty() == true || Contact->get_darkest_secret().empty() == true)
    {
        std::cout << "Darkest secret:"<< std::endl;
        std::getline(std::cin, content);
        if (content.empty() == true || is_print(content) == false)
        {
            std::cout << "Darkest secret should not be empty and be printable characters."<< std::endl;
            content.clear();
        }
        else
            Contact->set_darkest_secret(content);
    }
    content.clear();
    std::cout << "New contact saved" << std::endl;
}

std::string content_lenlimit(std::string content)
{
    if (content.size() > 10)
    {
        content.resize (9,'.');
        content.resize (10,'.');
    }
    return content;   
}

void PhoneBook::show_contact_detail(int index)
{
    if (this->ContactArr[index].get_first_name().empty() == true)
    {
        std::cout << "This contact is empty." << std::endl;
        return ;
    }
    std::cout << "First name: " <<this->ContactArr[index].get_first_name() << std::endl;
    std::cout << "Last name: " <<this->ContactArr[index].get_last_name() << std::endl;
    std::cout << "Nickname: " <<this->ContactArr[index].get_nick_name() << std::endl;
    std::cout << "Phone number: " <<this->ContactArr[index].get_phone_number() << std::endl;
    std::cout << "Darkest_secret: " <<this->ContactArr[index].get_darkest_secret() << std::endl;
}

void PhoneBook::search_contact()
{
    std::string content("");
    int i(0);

    std::cout << "Enter an index to get more information: " << std::endl;
    std::getline(std::cin, content);
    while(i < 8)
    {
        if(content.compare(std::to_string(i)) == 0)
        {
            this->show_contact_detail(i);
            return ;
        }
        i++;
    }
    std::cout << "Invalid index!" << std::endl;
    this->search_contact();
}

void PhoneBook::show_contacts()
{
    int index(0);
    std::string content("");

    std::cout << "     Index|First name| Last name|  Nickname|"<< std::endl;
    while(index < 8)
    {
        std::cout << std::right << std::setw(10)<< index<< "|";
        std::cout << std::right << std::setw(10)<< content_lenlimit(this->ContactArr[index].get_first_name())<< "|";
        std::cout << std::right << std::setw(10)<< content_lenlimit(this->ContactArr[index].get_last_name())<< "|";
        std::cout << std::right << std::setw(10)<< content_lenlimit(this->ContactArr[index].get_nick_name())<< "|";
        std::cout << "\n"; 
        index++;
    }
    this->search_contact();
}

void PhoneBook::menu()
{
    char cmd[250];
    int index = -1;
    std::string name;
    while (1)
    {
        std::cout << "Welcome to PhoneBook, pleass enter: ADD, SEARCH or EXIT"<< std::endl;
        //std::getline(std::cin, cmd);
        std::cin.getline(cmd,sizeof(cmd));
        if (!strcmp(cmd, "ADD"))
        {
            if (index >= -1)
                index++;
            if (index == 8)
                index = 0;
            PhoneBook::add_contact(&this->ContactArr[index]);
        }
        else if(!strcmp(cmd, "SEARCH"))
            PhoneBook::show_contacts();
        else if(!strcmp(cmd, "EXIT"))
            break;
    }
}