/*
 * API file for Travelling-Salesperson Cities class and utilities
 */

#pragma once

#include <vector>
#include <istream>
#include <ostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <iostream>

// Representation of an ordering of cities
class Cities {
  public:
    // A pair of integral coordinates for each city
    using coord_t = std::pair<int, int>;

    // An ordering of the cities in cities_t. Each value represents a unique index
    // into the current city ordering.
    using permutation_t = std::vector<unsigned int>;

    friend std::ostream& operator<<(std::ostream& os, const Cities& cities);

    // Pulls the necessary city data from a stream;
    Cities(std::istream& input);

    // Makes a cities object that does not have any cities points in it 
    Cities() = default;

    // Given a permutation, return a new Cities object where the order of the
    // cities reflects the original order of this class after reordering with
    // the given ordering. So for example, the ordering { 1, 0 } simply swaps
    // the first two elements (coordinates) in the new Cities object.
    Cities reorder(const permutation_t& ordering) const;

    // For a given permutation of the cities in this object,
    // compute how long (distance) it would take to traverse all the cities in the
    // order of the permutation, and then returning to the first city.
    // The distance between any two cities is computed as the Euclidean 
    // distance on a plane between their coordinates.
    double total_path_distance(const permutation_t& ordering) const;

    // returns the number of cities
    int num_cities() const { return city_coords_.size(); }

  private:
    // Vector storing the location of each city
    std::vector<coord_t> city_coords_;

    // Create a vector of coords based off of the permutation
    std::vector<coord_t> permute(const permutation_t& ordering) const;

    // Makes a new cities object from a vector of coord_t
    Cities(std::vector<coord_t> cities_order) : city_coords_(cities_order) {};
};

// creates a Cities object from a file name
Cities cities_from_file(const char * file_name);

// gives a random permutation vector
Cities::permutation_t random_permutation(unsigned int len);

// overrides the >> operator (warning, must dereference a Cities * into it, DO NOT PUT IN AN OBJECT BECAUSE CPP BREAKS AND COMPLAINS THAT IT "CANNOT FIND OPERATOR" (references: Dylan)
std::istream& operator>>(std::istream& is, Cities& cities);
