#include "cities.hh"
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::istringstream in("1 1\n2 2\n3 3\n4 4\n5 4\n6 4");
    
    Cities c(in);

    //Cities c();
    //std::cin >> c;

    std::cout << c << std::endl;
    std::cout << c.total_path_distance({0, 1, 2, 3, 4, 5}) << std::endl;
    std::cout << c.total_path_distance({2, 1, 0, 3, 5, 4}) << std::endl;
    Cities h = c.reorder({2, 1, 0, 3, 5, 4});
    std::cout << h << std::endl;

    std::cout << c;

    std::cout << "Permutations" << std::endl;

    auto rand_d = random_permutation(6);
    auto rand_e = random_permutation(6);
    auto rand_f = random_permutation(6);
    Cities d = c.reorder(rand_d);
    Cities e = c.reorder(rand_e);
    Cities f = c.reorder(rand_f);
    

    std::cout << d << std::endl;
    std::cout << e << std::endl;
    std::cout << f << std::endl;

    //std::cout << random_permutation(6) << std::endl;
    //std::cout << random_permutation(6) << std::endl;
    

    return 0;
}
