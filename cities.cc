#include "cities.hh"
#include <sstream>
#include <deque>
#include <fstream>
#include <string>
#include <cassert>
#include <algorithm>

Cities::Cities(std::istream& input)
{
    std::string text(std::istreambuf_iterator<char>(input), {});
    std::istringstream iterable_string(text);

    std::deque<int> raw_coords;
    std::string line;

    while(std::getline(iterable_string, line, ' ')){
        raw_coords.push_back(std::stoi(line));
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
    
    std::vector<coord_t> v;
    v.push_back(std::make_pair(ordering.size(), ordering.size()));
    Cities c(v);
    return c;
}

double Cities::total_path_distance(const permutation_t& ordering) const
{
    return ordering.size();
}

Cities cities_from_file(const char * file_name)
{
    std::ifstream input(file_name);
    assert(input.good());
    Cities cities(input);
    input.close();
    return cities;
}
