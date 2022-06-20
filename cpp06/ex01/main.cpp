#include "Data.hpp"
#include <iostream>
#include <stdint.h>

uintptr_t serialize(Data* ptr){
    return (reinterpret_cast<uintptr_t>(ptr));
}
Data* deserialize(size_t raw){
    return (reinterpret_cast<Data *>(raw));
}

int main()
{
    Data before;
    Data *after;
    uintptr_t data_ptr;

    // std::cout << "size of :" << sizeof(&before)<< std::endl; 
    // std::cout << "size of :" << sizeof(uintptr_t)<< std::endl;
    // std::cout << "size of :" << sizeof(int)<< std::endl;
    // std::cout << "size of :" << sizeof(size_t)<< std::endl;
    before.t_char = '*';
    before.t_int = 42;
    before.t_float = 42.0f;
    before.t_double = 42.0;
    before.t_string = "42";

    data_ptr = serialize(&before);
    std::cout << "before address: " << &before << std::endl;
    // std::cout << "uintptr_t :" << data_ptr << std::endl;
    // std::cout << "uintptr_t add:" << &data_ptr << std::endl;
    after = deserialize(data_ptr);
    std::cout << "after address: " << after << std::endl;
    std::cout << "after.char:" << after->t_char << std::endl;
    std::cout << "after.int:" << after->t_int << std::endl;
    std::cout << "after.float:" << after->t_float << std::endl;
    std::cout << "after.double:" << after->t_double << std::endl;
    std::cout << "after.string:" << after->t_string << std::endl;

    return 0;
}
