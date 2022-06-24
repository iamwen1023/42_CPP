#include "easyfind.tpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>


// char const *	IndexErrorException::what() const throw()
// {
//     return ("Index out of range");
// }

int main(){
    std::vector<int> g1;
 
    for (int i = 1; i <= 5; i++)
        g1.push_back(i);
    // try {
    //     easyfind(g1, 2);
    // }catch (std::exception & e){
	// 	std::cout <<  e.what() << std::endl;
	// }
    easyfind(g1, 2);
    
    std::deque<int> d;
    for (int i = 1; i <= 5; i++)
        d.push_back(i);
    // try {
    //     easyfind(d, 2);
    // }catch (std::exception & e){
	// 	std::cout <<  e.what() << std::endl;
	// }   
    easyfind(d, 2);
     easyfind(d, 6);
    
    std::list<int> l ;
    for (int i = 1; i <= 5; i++)
        l.push_back(i);
    easyfind(l, 16);
    return 0;
}