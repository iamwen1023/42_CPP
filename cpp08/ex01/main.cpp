#include "Span.hpp"
#include <iostream>
int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.printContainer();
    try
	{
		std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
    Span sp1 = Span(5);
    sp1.printContainer();
    try
	{
		std::cout << sp1.shortestSpan() << std::endl;
        std::cout << sp1.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    std::cout << " ~~~~~ Test auto addNumber ~~~~~ \n";
	{
        try {
		Span sp2 = Span(4);
        sp2.addNumber();
		sp2.printContainer();
		std::cout << "shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp2.longestSpan() << std::endl;
        }
        catch(const std::exception &e)
	    {
		    std::cerr << e.what() << std::endl;
	    }

	}
    return 0;
}


// int	main(){
// 	std::cout << " ~~~~~ Simple span test ~~~~~ \n";
// 	{
// 		std::cout << "Create a span with 11 slots.\n";
// 		Span	newSpan = Span(11);
// 		std::cout << "Add number 22 and 11 into it.\n";
// 		newSpan.addNumber(22);
// 		newSpan.addNumber(11);
//         newSpan.printContainer();

// 	}
// 	std::cout << "\n";

// 	std::cout << " ~~~~~ Test in subject ~~~~~ \n";
// 	{
// 		Span sp = Span(5);
// 		sp.addNumber(2);
// 		sp.addNumber(3);
// 		sp.addNumber(17);
// 		sp.addNumber(9);
// 		sp.addNumber(11);
// 		sp.printContainer();
// 		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
// 		std::cout << "longest span: " << sp.longestSpan() << std::endl;
// 	}
// 	std::cout << "\n";

// 	std::cout << " ~~~~~ Test with negative value ~~~~~ \n";
// 	{
// 		Span sp = Span(5);
// 		sp.addNumber(-88);
// 		sp.addNumber(3);
// 		sp.addNumber(17);
// 		sp.addNumber(9);
// 		sp.addNumber(11);
// 		sp.printContainer();
// 		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
// 		std::cout << "longest span: " << sp.longestSpan() << std::endl;
// 	}
// 	std::cout << "\n";

// 	std::cout << " ~~~~~ Test auto addNumber ~~~~~ \n";
// 	{
// 		Span sp = Span(100);
// 		sp.addNumber(5);
//         sp.addNumber();
// 		sp.printContainer();
// 		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
// 		std::cout << "longest span: " << sp.longestSpan() << std::endl;
// 	}
// 	std::cout << "\n";
// 	return 0;
// }