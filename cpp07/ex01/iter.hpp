#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T>
void iter(const T *arr_ptr, int len, void (*func)(const T &item)){
    for(int i = 0; i < len; i++){
        func(arr_ptr[i]);
    }
}

template <typename A>
void printOut(const A &i){
    std::cout << i << std::endl;
}

#endif