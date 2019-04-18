#include "cities.hh"
#include <sstream>
#include <deque>
#include <fstream>
#include <string>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <numeric>

Cities::Cities(std::istream& input)
{
    std::string text(std::istreambuf_iterator<char>(input), {});
    std::istringstream iterable_string(text);

    std::deque<int> raw_coords;
    std::string line_space;

    

    while(std::getline(iterable_string, line_space, ' ')){
        std::istringstream iterable_substring(line_space);
        std::string line;
        
        while(std::getline(iterable_substring, line, '\n')){
            raw_coords.push_back(std::stoi(line));
        }
    }

    while(raw_coords.size() > 1){
        const int x = raw_coords.front();
        raw_coords.pop_front();
        const int y = raw_coords.front();
        raw_coords.pop_front();
        city_coords_.push_back(std::make_pair(x, y));
    }

    assert(raw_coords.empty());
}
/*
std::ostream& operator<<(std::ostream& os, Cities& cities)
{
    for(Cities::coord_t c : cities.city_coords_){
        os << c;
    }

    return os;
}
*/

/*
Cities::Cities(std::istream& input)
{
    input >> * this;
}
*/

Cities Cities::reorder(const permutation_t& ordering) const
{
    std::vector<coord_t> permuted;
    for(const auto i : ordering){
        permuted.push_back(city_coords_[i]);
    }
    Cities c(permuted);
    return c;
}

double Cities::total_path_distance(const permutation_t& ordering) const
{

    if(city_coords_.size() < 2){
        return 0;
    }

    std::vector<std::pair<double, coord_t>> last_length;

    for(const auto i : ordering){
        last_length.push_back(std::make_pair(0, city_coords_[i]));
    }

    return std::accumulate(last_length.cbegin(), last_length.cend(), last_length.back(),
        [](std::pair<double, coord_t> a, std::pair<double, coord_t> b){
            const double xdif = static_cast<double>(a.second.first - b.second.first);
            const double ydif = static_cast<double>(a.second.second - b.second.second);
            return std::sqrt(xdif * xdif + ydif * ydif) + a.first + b.first;
        }).first;
}

Cities cities_from_file(const char * file_name)
{
    std::ifstream input(file_name);
    assert(input.good());
    Cities cities(input);
    input.close();
    return cities;
}

void print_cities(Cities& cities)
{
    for(Cities::coord_t c : cities.get_coords()){
        const int f = c.first;
        const int s = c.second;
        std::cout << f << " " << s << std::endl;
    }
}
