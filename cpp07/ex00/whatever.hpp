#ifndef TEMP_HPP
#define TEMP_HPP

template <typename T>
void swap ( T& a, T& b ){
    T c = a;
    a = b;
    b = c; 
}
template <typename T>
T &min(const T &a,const T &b){
    return const_cast<T &>(a >= b? b : a);
}
template <typename T>
T &max(T &a, T &b){
    return const_cast<T &>(a <= b? b : a);
}

#endif