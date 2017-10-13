#include "int.h"

int
main()
{

    Int a(4), b(2);
    
    std::cout << a << " " << b << std::endl;

    std::swap(a, b);
    
    std::cout << a << " " << b << std::endl;
    a=b;
    std::cout << a << " " <<  b << std::endl;
Int c(a);
    return 0;
}
