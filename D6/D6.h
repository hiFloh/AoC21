/**
 * @author Florian Gapp
 * @date 06.12.21
 *
 * header for Day 6 of AoC (https://adventofcode.com/)
 */


#ifndef AOC21_D6_H
#define AOC21_D6_H
#include "../lib.h"

class Fish{
public:
    Fish();
    bool grow();
    size_t getAge() const;
    friend std::istream & operator>>(std::istream&ist,Fish & f);
private:
    short age;
};
std::istream & operator>>(std::istream&ist,Fish & f);
std::ostream & operator<<(std::ostream&ost,Fish const&f);
class D6 {
public:
    static int mmain(arguments args);
    using input_type=Fish;
private:
    static void P1(std::vector<input_type> &input);
    static void P2(std::vector<input_type> &input);
};


#endif //AOC21_D6_H
