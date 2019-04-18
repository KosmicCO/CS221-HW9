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

Cities Cities::reorder(const permutation_t& ordering) const
{
    std::vector<coord_t> permuted;
    for(const auto i : ordering){
        permuted.push_back(city_coords_[i]);
    }
    Cities c(permuted);
    return c;
}

double dist(Cities::coord_t a, Cities::coord_t b)
{
    const double xdif = static_cast<double>(a.first - b.first);
    const double ydif = static_cast<double>(a.second - b.second);
    return std::sqrt(xdif * xdif + ydif * ydif);
}

double Cities::total_path_distance(const permutation_t& ordering) const
{

    if(city_coords_.size() < 2){
        return 0;
    }

    std::vector<Cities::coord_t> permuted;

    for(const auto i : ordering){
        permuted.push_back(city_coords_[i]);
    }

    coord_t previous = permuted.back();

    auto add_dist = [&previous](double d, Cities::coord_t n){
        const double dist_new = dist(previous, n) + d;
        previous = n;
        return dist_new;
    };

    const double sum = std::accumulate(permuted.cbegin(), permuted.cend(), static_cast<double>(0), add_dist);
    return sum;
}

Cities cities_from_file(const char * file_name)
{
    std::ifstream input(file_name);
    assert(input.good());
    Cities cities(input);
    input.close();
    return cities;
}

std::ostream& operator<<(std::ostream& os, const Cities& cities)
{
    for(Cities::coord_t c : cities.city_coords_){
        const int f = c.first;
        const int s = c.second;
        os << f << " " << s << std::endl;
    }

    return os;
}


/*
std::istream& operator>>(std::istream& is, Cities& cities)
{
    Cities c(is);
    cities = c;
    return is; 
}
*/

Cities::permutation_t random_permutation(unsigned int len)
{
    Cities::permutation_t permute;
    for(unsigned int i = 0; i < len; i++){
        permute.push_back(i);
    }

    std::random_shuffle(permute.begin(), permute.end());
    return permute;
}















