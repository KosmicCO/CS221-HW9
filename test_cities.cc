#include "cities.hh"
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::istringstream in("1 1 2 2\n3 3");
    
    Cities c(in);
    //Cities c;
    //std::cin >> c;
    //std::cout << c;
    print_cities(c);
    return 0;
}
