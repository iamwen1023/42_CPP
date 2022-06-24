#include <iostream>
template< typename T >
void easyfind(T &contain, int toFind){
    for(unsigned int i= 0; i < contain.size();i ++){
        if (contain[i] == toFind){
            std::cout <<" found :" << contain[i] <<std::endl;
            return ;
        }
    }
    std::cout <<" error" <<std::endl; 
    //throw IndexErrorException();
}
