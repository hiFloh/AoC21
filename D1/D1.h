/**
 * @author Florian Gapp
 * @date 01.12.21
 *
 * header for Day 1 of AoC (https://adventofcode.com/)
 */

#ifndef AOC21_D1_H
#define AOC21_D1_H
#include <vector>
#include <string>

class D1{
public:
    static int mmain(std::vector<std::string> const& args);
    static int getHeight(std::vector<int> const& heightProfile);
    static std::vector<int> getAverage(std::vector<int> const& heightProfile,size_t const &count);
};

#endif //AOC21_D1_H
