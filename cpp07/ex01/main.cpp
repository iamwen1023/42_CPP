#include "iter.hpp"
#include <string>

int main(){
    std::string arr1[] = {"abc", "bcc", "cdd"};
    int	arr2[] = {1, 4, -100, 1000};
    iter(arr1, 3, &printOut);
	iter(arr2, 4, &printOut);
    return 0;
}
