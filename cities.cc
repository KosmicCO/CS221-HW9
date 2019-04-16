#include "cities.hh"

friend std::istream Cities::operator>>(std::istream& is, Cities::Cities& cities)
{
    std::string text(std::istreambuf_iterator<char>(input), {});
    std::istringstream iterable_string(text);

    std::vector<int> raw_coords;
    std::string line;

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

friend std::ostream Cities::operator<<(std::ostream& os, Cities::Cities& cities) const
{
    std::for_each(cities.city_coords_.cbegin(), cities.city_coords_.cend(), [&os](coord_t coord){
        os << coord.first() << " " << coord.second() << std::endl; 
    });
}

Cities::Cities(std::istream * input)
{
    input >> * this;
}

Cities::Cities Cities::reorder(const permutation_t& ordering) const
{
    return nullptr;
}

double Cities::total_path_distance(const permutation_t& ordering) const
{
    return nullptr;
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
