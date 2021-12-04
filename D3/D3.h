/**
 * @author Florian Gapp
 * @date 03.12.21
 *
 * header for Day 3 of AoC (https://adventofcode.com/)
 */
#ifndef AOC21_D3_H
#define AOC21_D3_H

#include "lib.h"

class D3 {
public:
    static int mmain(arguments);
    static int A1(std::vector<std::string> const&inp);
    static int A2(std::vector<std::string> const&inp);
    static int bin2Int(std::string const&i);
};


#endif //AOC21_D3_H
