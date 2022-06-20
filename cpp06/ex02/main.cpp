#include "main.hpp"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Base * generate(void){
    int num ;

    srand (time(NULL));
    num = rand() % 3;
    switch(num){
        case 0:
            return (new A);
        case 1:
            return (new B);
        case 2:
            return (new C);
        default:
            return NULL;
    }
    return NULL;
}
void identify(Base* p){
    A *a = dynamic_cast<A *>(p);
    B *b = dynamic_cast<B *>(p);
    C *c = dynamic_cast<C *>(p);
    if (a)
        std::cout << "ptr A" << std::endl;
    else if (b)
        std::cout << "ptr B" << std::endl;
    else if (c)
        std::cout << "ptr C" << std::endl;
    else 
         std::cout << "unidentified obj" << std::endl;
}
void identify(Base& p){
    try{
       A &a = dynamic_cast<A &>(p); 
       (void)a;
       std::cout << "ref A" << std::endl;
    }catch(std::exception &e){}
    try{
       B &b = dynamic_cast<B &>(p); 
       (void)b;
       std::cout << "ref B" << std::endl;
    }catch(std::exception &e){}
    try{
       C &c = dynamic_cast<C &>(p); 
       (void)c;
       std::cout << "ref C" << std::endl;
    }catch(std::exception &e){}

}
int main(){
    Base *base_ptr = generate();
    Base &base_ref = *base_ptr;
    Base *another= NULL;
    identify(base_ptr);
    //identify(another);
    identify(base_ref);
    delete base_ptr;
    return 0;
}