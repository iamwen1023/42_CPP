#include <iostream>
#include <cstdlib>
#include "Array.hpp"

char const *	IndexErrorException::what() const throw()
{
    return ("Index out of range");
}

int main(void)
{

	Array<int> a = Array<int>(3);
	for (unsigned int i = 0; i < a.size(); i++) {
		std::cout << a[i] << std::endl;
	}

	std::cout << "-----------" << std::endl;

	Array<char> b = Array<char>(3);
    for (unsigned int i = 0; i < a.size(); i++) {
		std::cout << b[i] << std::endl;
	}
	b[0] = 'a';
	b[1] = 'b';
	b[2] = 'c';

	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << std::endl;

	std::cout << "-----------" << std::endl;

	Array<char> c = Array<char>(b);

	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << c[i] << std::endl;   

	std::cout << "-----------" << std::endl;
    Array<char> d(c);
    std::cout << "c address: " << &d << std::endl;
    std::cout << "d address: " << &c << std::endl;
    std::cout << "-----------" << std::endl;

	Array<std::string> str1 = Array<std::string>();
	Array<std::string> str2 = Array<std::string>(4);
	str2[0] = "how";
	str2[1] = "are";
	str2[2] = "you";
	str2[3] = "?";

	str1 = str2;
	for (int i = 0; i < 4; i++)
		std::cout << str1[i] << " ";
	std::cout << std::endl << "Size = " << str1.size() << std::endl;
	std::cout << "-----------" << std::endl;
	try{
		a[8];
		b[8];
		c[8];
	}catch (std::exception & e){
		std::cout <<  e.what() << std::endl;
		return 0;
	}
	std::cout << "-----------" << std::endl;
	return 0;
}
// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     // for (unsigned int i = 0; i < numbers.size(); i++)
//     //         std::cout << numbers[i] << " , ";
//     // std::cout << "\n";
//     int* mirror = new int[MAX_VAL];
//     // for (unsigned int i = 0; i < MAX_VAL; i++)
//     //         std::cout << mirror[i] << " , ";
//     // std::cout << "\n";

//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//         // for (unsigned int i = 0; i < tmp.size(); i++)
//         //     std::cout << tmp[i] << " , ";
//         // std::cout << "\n";
//         // for (unsigned int i = 0; i < test.size(); i++)
//         //     std::cout << test[i] << " , ";
//         // std::cout << "\n";
//         // std::cout << "tmp addre :" << &tmp << std::endl;
//         // std::cout << "test addre :" << &test << std::endl;
//     }
 
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }