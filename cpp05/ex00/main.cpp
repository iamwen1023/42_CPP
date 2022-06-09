#include "Bureaucrat.hpp"
#include <iostream>

int	main(){
	std::cout << "~~~~~~~ Basic tests ~~~~~~~\n";
	std::cout << "------- b1 -------\n";
	Bureaucrat b1("b1", 150);
	std::cout << b1 << std::endl;
	try {
		std::cout << "Try to downgrade b1:\n";
		b1.decreGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "Try to upgrade b1:\n";
		b1.increGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << b1 << std::endl;

	std::cout << "------- b2 -------\n";
	Bureaucrat b2("b2", 1);
	std::cout << b2 << std::endl;
	try {
		std::cout << "Try to upgrade b2:\n";
		b2.increGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "Try to downgrade b2:\n";
		b2.decreGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << b2 << std::endl;

	std::cout << "~~~~~~~ Bureaucrat on the heap  ~~~~~~~\n";
	Bureaucrat* hb = new Bureaucrat("hb", 130);
	std::cout << *hb;
	try {
		std::cout << "Try to downgrade hb:\n";
		hb->decreGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	delete hb;
	std::cout << "~~~~~~~ instancialize with bad grade value ~~~~~~~\n";

	try {
		Bureaucrat b3("abcde", 12345);
		std::cout << b1 << "\n";
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b4("abcde", 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b5("abcde", -1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
