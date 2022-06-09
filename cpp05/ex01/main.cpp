#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main(){
	Form	f1("f1", 150, 150);
	Form	f2("f2", 149, 149);
	std::cout << f1;
	std::cout << f2;
	std::cout << "\n";

	Bureaucrat b1("b1", 150);
	std::cout << b1;
	std::cout << "\n";
	try {
		std::cout << "Try to downgrade b1:\n";	
		b1.decreGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------" << std::endl;
	b1.signForm(f1);
	std::cout << f1 << std::endl;

	std::cout << "-------------" << std::endl;
	b1.signForm(f2);
	std::cout << f2<< std::endl;

	try {
		std::cout << "Try to upgrade b1:\n";	
		b1.increGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << b1;
	std::cout << "\n";

	b1.signForm(f1);
	std::cout << f1;
	b1.signForm(f2);
	std::cout << f2;

	return (0);
}
