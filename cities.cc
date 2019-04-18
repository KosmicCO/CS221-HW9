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
    std::string text(std::istreambuf_iterator<char>(input), {});    // gets all the text from an input stream
    std::istringstream iterable_string(text);                       // turns the text into a stringstream for getline

    std::deque<int> raw_coords;                 // creates a new deque to hold the coords
    std::string line_space;                     // holding variable for the output of getline

    

    while(std::getline(iterable_string, line_space, ' ')){  // splits string by ' '
        std::istringstream iterable_substring(line_space);
        std::string line;
        
        while(std::getline(iterable_substring, line, '\n')){    // splits string by '\n'
            raw_coords.push_back(std::stoi(line));
        }
    }

    while(raw_coords.size() > 1){
        const int x = raw_coords.front();
        raw_coords.pop_front();
        const int y = raw_coords.front();
        raw_coords.pop_front();
        city_coords_.push_back(std::make_pair(x, y));   // puts each pair coord into the city_coords vector
    }

    assert(raw_coords.empty()); // makes sure that there wasnt an odd number of coords in the file
}

std::vector<Cities::coord_t> Cities::permute(const permutation_t& ordering) const
{
    std::vector<Cities::coord_t> permuted;
    for(const auto i : ordering){
        permuted.push_back(city_coords_[i]);    // permutes matrix here
    }
    return permuted;
}

Cities Cities::reorder(const permutation_t& ordering) const
{
    Cities c(permute(ordering));
    return c;
}

// finds the distance between cities
double dist(Cities::coord_t a, Cities::coord_t b)
{
    const double xdif = static_cast<double>(a.first - b.first);
    const double ydif = static_cast<double>(a.second - b.second);
    return std::sqrt(xdif * xdif + ydif * ydif);
}

double Cities::total_path_distance(const permutation_t& ordering) const
{

    if(city_coords_.size() < 2){    // cant leave if there is only one city to go to ;)
        return 0;
    }

    std::vector<Cities::coord_t> permuted = permute(ordering);

    coord_t previous = permuted.back();     // makes sure to make a loop

    auto add_dist = [&previous](double d, Cities::coord_t n){
        const double dist_new = dist(previous, n) + d;  // finds dist between prev and current using the captures
        previous = n;
        return dist_new;
    };

    const double sum = std::accumulate(permuted.cbegin(), permuted.cend(), static_cast<double>(0), add_dist);   // adds everything
    return sum;
}

Cities cities_from_file(const char * file_name)
{
    std::ifstream input(file_name);     // makes file
    assert(input.good());
    Cities cities(input);               // constructs Cities from Cities(std::istream) constructor
    input.close();
    return cities;
}

std::ostream& operator<<(std::ostream& os, const Cities& cities)
{
    for(Cities::coord_t c : cities.city_coords_){
        const int f = c.first;
        const int s = c.second;
        os << f << " " << s << std::endl;   // prints each coord
    }

    return os;
}


std::istream& operator>>(std::istream& is, Cities& cities)
{
    Cities c(is);   // uses the Cities(std::istream) constructor
    cities = c;     // since its a reference it can change the original version
    return is; 
}

Cities::permutation_t random_permutation(unsigned int len)
{
    Cities::permutation_t permute;
    for(unsigned int i = 0; i < len; i++){  // creates the identity permutation, i.e. {0, 1, 2, ..., len - 1}
        permute.push_back(i);
    }

    std::random_shuffle(permute.begin(), permute.end());    // randomize the identity permutation
    return permute;
}















