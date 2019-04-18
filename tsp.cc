#include "cities.hh"

int main(int argc, char ** argv)
{

    if(argc != 3){                                  // testing arguments
        std::cerr << "Needs exactly 2 argument.";
        return 1;
    }


    const long long max_run = std::stoll(argv[2]);  // read in how long it should run for (-1 means forever)
    const Cities c = cities_from_file(argv[1]);     // read in file to read from
    
    Cities::permutation_t lowest = random_permutation(c.num_cities());  // to start
    double current_lowest = c.total_path_distance(lowest);              // start distance

    for(long long i = 0; (i < max_run) || (max_run == -1); i++){                // either a loop that runs forever or until max_run
        Cities::permutation_t candidate = random_permutation(c.num_cities());   // creates a new candidate and associated dist
        const double dist = c.total_path_distance(candidate);
        if(dist < current_lowest){                                              // if its less, then make it the current and print the info
            current_lowest = dist;
            lowest = candidate;
            std::cout << i << "\t" << dist << std::endl;
        }
    }
}
