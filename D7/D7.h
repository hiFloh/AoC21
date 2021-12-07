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

private:
    short height;
};
std::istream & operator>>(std::istream&ist, CrabSubmarine & f);

bool operator<(CrabSubmarine const& c1, CrabSubmarine const& c2);
class D7 {
public:
    using input_type=CrabSubmarine;
    static int P1(std::vector<input_type>const &input);
    static int P2(std::vector<input_type>const &input);
};


#endif //AOC21_D7_H
