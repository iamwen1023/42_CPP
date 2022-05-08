#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Enter a filename and two strings" << std::endl;
        return 0;
    }
    std::string     original(av[2]);
    if (original.size() == 0)
    {
        std::cout << "S1 is empty" << std::endl;
        return 0;
    }
    std::string     replace(av[3]);
    std::ifstream	ifs(av[1]);
    if (!ifs.is_open())
    {
        std::cout << "Unable to open intput file\n";
        return (1);
    }
    std::string     filename(av[1]);
    std::ofstream	ofs(filename.append(".replace"));
    if (!ofs.is_open())
    {
        std::cout << "Unable to open ouput file\n";
        return (1);
    }

	std::string str;
    std::string new_str("");

	std::getline(ifs, str, '\0');
	//std::cout << "str:"<< str << std::endl;
    std::size_t pos(str.find(original)); 
    // std::cout << "str:|"<< original << "|" << pos << std::endl;
    // std::cout << "pos: "<< pos << std::endl;
    while(pos != std::string::npos)
    {
        new_str = str.substr(0, pos);
        ofs << new_str;
        ofs << replace;
        str =  str.substr(pos + original.size(), std::string::npos);
        pos = str.find(original);
    }
	ifs.close();
    ofs.close();
    return 0;
}