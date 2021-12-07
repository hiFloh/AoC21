//
// Created by flori on 06.12.21.
//

#ifndef AOC21_D7_H
#define AOC21_D7_H
#include "vector"
#include "iostream"
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

class D7 {
public:
    using input_type=int;
    static int P1(std::vector<input_type>const &input);
    static int P2(std::vector<input_type>const &input);
};


#endif //AOC21_D7_H
