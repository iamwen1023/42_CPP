#include <iostream>
#include "whatever.hpp"
#include <cstring>
const char *min(const char *s1,const char *s2){
    return strcmp(s1, s2) >= 0 ? s2: s1;
}
const char *max(const char *s1,const char *s2){
    return strcmp(s1, s2) <= 0 ? s2: s1;
}

int main( void ) {
    int a = -2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    float e =3.99;
    float f =-4.99;
    ::swap(e, f);
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
    std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
    const char* s1="toto";
    const char* s2="tata";
    //swap(s1, s2);
    std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
    std::cout << "min( s1, s2 ) = " << ::min( s1, s2 ) << std::endl;
    std::cout << "max( s1, s2 ) = " << ::max( s1, s2 ) << std::endl;

    return 0;
}