#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(){
	std::cout << "~~~~~~~ Intern tests ~~~~~~~\n";
	Bureaucrat b1("b1", 80);
	Bureaucrat b2("b2", 25);
	std::cout << b1;
	std::cout << b2;
	std::cout << "\n";

	Intern	someRandomIntern;

	AForm*	rrf;
	try {
		rrf = someRandomIntern.makeForm("robotomy request", "RRF_Target");
		b1.signForm(*rrf);
		b1.executeForm(*rrf);
		b2.signForm(*rrf);
		b2.executeForm(*rrf);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	delete rrf;
	std::cout << "\n";

	AForm*	scf;
	try {
		scf = someRandomIntern.makeForm("shrubbery creation", "SCF_Target");

		b1.signForm(*scf);
		b1.executeForm(*scf);
		b2.signForm(*scf);
		b2.executeForm(*scf);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	delete scf;
	std::cout << "\n";

	AForm*	ppf;
	try {
		ppf = someRandomIntern.makeForm("presidential pardon", "PPF_Target");

		b1.signForm(*ppf);
		b1.executeForm(*ppf);
		b2.signForm(*ppf);
		b2.executeForm(*ppf);
	} catch (std::exception &e) {
		std::cout << e.what()<< std::endl;
	}

	delete ppf;
	std::cout << "last one\n";

	AForm*	naf;
	try {
		naf = someRandomIntern.makeForm("Not A Form", "NAF_Target");
		b1.signForm(*naf);
		b1.executeForm(*naf);
		b2.signForm(*naf);
		b2.executeForm(*naf);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	//delete naf;

	return (0);
}
