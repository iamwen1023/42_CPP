#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>


char const *	NotFoundException::what() const throw(){
    return ("Element not found");
}


int main(){
    // TEST 1
	std::cout << "[ 1. Vector OK : find 8 ]" << std::endl;
	std::vector<int>					vect;
	std::vector<int>::iterator			it;
	for (int i = 0; i < 10; i++) {
		vect.push_back(i);
	}
	try
	{
        printContainer(vect);
		easyfind(vect, 8);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	// TEST 2
	std::cout << "[ 2. Vector KO : find 50 ]" << std::endl;
	try
	{
        printContainer(vect);
		easyfind(vect, 50);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	// TEST 3
	std::cout << "[ 3. List OK : find 42 ]" << std::endl;
	std::list<int>					lst(10, 1);
    printContainer(lst);
	for (int i = 42; i < 53; i++) {
		lst.push_back(i);
	}
	try
	{
        printContainer(lst);
		easyfind(lst, 42);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	// TEST 4
	std::cout << "[ 4. List KO : find 100 ]" << std::endl;
	try
	{
        printContainer(lst);
		easyfind(lst, 100);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	// TEST 5
	std::cout << "[ 5. Deque OK : find 50 ]" << std::endl;
	std::deque<int>					deck(8, 2);
    for (int i = 42; i < 53; i++) {
		deck.push_front(i);
	}
	//std::generate_n(deck.begin(), 10, UniqueNumber);
	try
	{
        printContainer(deck);
		easyfind(deck, 50);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	// TEST 6
	std::cout << "[ 6. Deque KO : find 100 ]" << std::endl;
	try
	{
		printContainer(deck);
		easyfind(deck, 100);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
    return 0;
}