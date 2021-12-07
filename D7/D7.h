//
// Created by flori on 06.12.21.
//

#ifndef AOC21_D7_H
#define AOC21_D7_H
#include "vector"
#include "iostream"
class CrabSubmarine{
public:
//    CrabSubmarine();
    size_t getHeight() const;
    friend std::istream & operator>>(std::istream&ist, CrabSubmarine & f);
    unsigned long simulate(size_t i);
    unsigned long simulate2(size_t i);

private:
    unsigned int height;
};
std::istream & operator>>(std::istream&ist, CrabSubmarine & f);

bool operator<(CrabSubmarine const& c1, CrabSubmarine const& c2);
class D7 {
public:
    using input_type=CrabSubmarine;
    static int P1(std::vector<input_type>const &input);
    static int P2(std::vector<input_type>const &input);
};

/*
 * Part1: 345197 after 35818us
Part2: 96361606 after 3747586us

 */
#endif //AOC21_D7_H
