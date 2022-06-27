#include "MutantStack.hpp"
#include <iostream>
#include <list>
int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    std::cout << "----------------" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "----------------" << std::endl;
    std::stack<int> s(mstack);
    std::cout << s.top() << std::endl;
    std::cout << s.size() << std::endl;

    
    std::cout << "----------------" << std::endl;
	MutantStack<char> mstack2;
	mstack2.push('s');
	mstack2.push('o');
	std::cout << mstack2.top() << std::endl;
	mstack2.pop();
	std::cout << mstack2.size() << std::endl;
	mstack2.push('a');
	mstack2.push('l');
	mstack2.push('u');
	mstack2.push('t');
	MutantStack<char>::iterator it3 = mstack2.begin();
	MutantStack<char>::iterator ite3 = mstack2.end();
	++it3;
	--it3;
	while (it3 != ite3)
	{
		std::cout << *it3 << std::endl;
		++it3;
	}
    return 0;
}