//
// Created by flori on 06.12.21.
//

#ifndef AOC21_D7_H
#define AOC21_D7_H
#include "vector"
#include "iostream"
class CrabSubmarine{
public:
    size_t getHeight() const;
    friend std::istream & operator>>(std::istream&ist, CrabSubmarine & f);
    /**
     * simulates moving to horizontal position i.
     * @param i
     * @returns used fuel according to part 1
     */
    unsigned long simulateMove1(size_t i);/**
     * simulates moving to horizontal position i.
     * @param i
     * @returns used fuel according to part 2
     */
    unsigned long simulateMove2(size_t i);

private:
    unsigned int height;
};
std::istream & operator>>(std::istream&ist, CrabSubmarine & f);
/**
 * @brief less operator for CrabSubmarine
 * @param c1
 * @param c2
 * @return true if height of c1 < c2
 */
bool operator<(CrabSubmarine const& c1, CrabSubmarine const& c2);

class D7 {
public:
    using input_type=CrabSubmarine;
    static int P1(std::vector<input_type>const &input);
    static int P2(std::vector<input_type>const &input);
};

#endif //AOC21_D7_H
