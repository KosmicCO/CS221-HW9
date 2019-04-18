#include "cities.hh"

int main(int argc, char ** argv)
{

    if(argc != 3){
        std::cerr << "Needs exactly 2 argument.";
        return 1;
    }


    const int max_run = std::stoi(argv[2]);
    const Cities c = cities_from_file(argv[1]);
    
    Cities::permutation_t lowest = random_permutation(c.num_cities());
    double current_lowest = c.total_path_distance(lowest);

    for(auto i = 0; i < max_run; i++){
        Cities::permutation_t candidate = random_permutation(c.num_cities());
        const double dist = c.total_path_distance(candidate);
        if(dist < current_lowest){
            current_lowest = dist;
            lowest = candidate;
            std::cout << i << "\t" << dist << std::endl;
        }
    }
}
