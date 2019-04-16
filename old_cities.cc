#include "cities.hh"
#include <string>
#include <cassert>
#include <iterator>
#include <cmath>
#include <numeric>

double euclid_dist(const coord_t&, const coord_t&);

std::istream Cities::operator>>(std::istream& input, Cities::Cities cities)
{
    std::string text(std::istreambuf_iterator<char>(input), {});
    std::string line;
    std::istringstream iterable_string(text);

    std::vector<int> raw_coords;

    while(std::getline(iterable_string, line, ' ')){
        raw_coords.push_back(std::stoi(line));
    }

    cities.city_coords_.clear();

    while(raw_coords.size() > 1){
        const int x = raw_coords.pop_top();
        const int y = raw_coords.pop_top();
        cities.city_coords_.push_back(std::make_pair(x, y));
    }

    assert(raw_coords.isEmpty());
}

Cities::Cities cities_from_file(const char * file_name)
{
    std::ifstream input(file_name);
    input.open();
    assert(input.good());
    Cities cities(input);
    input.close();
    return cities;
}

istream Cities::operator>>(std::istream& is, Cities::Cities cities)
{
    
}

Cities::Cities Cities::reorder(const permutation_t& ordering) const
{
    std::vector<coord_t> next_cities;
    for(int i : ordering){
        next_cities.push_back(city_coords_[i]);
    }
    Cities cities(next_cities);
    return cities;
}

double Cities::total_path_distance(const permutation_t& ordering) const
{
    if(city_coords.size() < 2){
        return 0;
    }

    std::vector distances;
    std::transform( city_coords_.begin(), city_coords.end(),                // NOPE
                    
}

double euclid_dist(const coord_t& c1, const coord_t& c2){

    double xdif = static_cast<double>(c1.first - c2.first);
    double ydif = static_cast<double>(c1.second - c2.second);

    return std::sqrt(xdif * xdif + ydif * ydif);
}
