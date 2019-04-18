#include "cities.hh"
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::istringstream in("1 1\n2 2\n3 3\n4 4\n5 4\n6 4");  // test cities stream
    
    //Cities c(in);

    Cities * c = new Cities();      // using >> instead of the constructor (which is worse because the constructor ensures immutibility, but this was also part of the assignment)
    std::cin >> *c;

    std::cout << *c << std::endl;                                           // print to see
    std::cout << c->total_path_distance({0, 1, 2, 3, 4, 5}) << std::endl;   // no permute
    std::cout << c->total_path_distance({2, 1, 0, 3, 5, 4}) << std::endl;   // permuted
    Cities h = c->reorder({2, 1, 0, 3, 5, 4});                              // print to check if it permuted correctly
    std::cout << h << std::endl;                                            

    std::cout << *c << std::endl;                            // print to see if c was mutated (because it can be mutated :c )

    std::cout << "Permutations" << std::endl;

    auto rand_d = random_permutation(6);        // testing to he how random the random permutations are
    auto rand_e = random_permutation(6);
    auto rand_f = random_permutation(6);
    Cities d = c->reorder(rand_d);              // also testing reorder on the random permutations
    Cities e = c->reorder(rand_e);
    Cities f = c->reorder(rand_f);
    

    std::cout << d << std::endl;
    std::cout << e << std::endl;
    std::cout << f << std::endl;
    
    delete c;
    return 0;
}
