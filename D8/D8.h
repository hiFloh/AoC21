/**
 * @author Florian Gapp
 * @date 08.12.21
 *
 * header for Day 8 of AoC (https://adventofcode.com/)
 */

#ifndef AOC21_D8_H
#define AOC21_D8_H

#include <vector>
#include <iostream>
#include <array>


class Seg7{
public:
    Seg7();
    Seg7(std::string const&s);
    Seg7(std::array<bool,7>&s);
    int getCountOn ()const;
    int getCountOff()const;
    friend std::istream & operator>>(std::istream&ist,Seg7 & f);
    [[nodiscard]] std::array<bool,7>::const_iterator cbegin() const;
    [[nodiscard]] std::array<bool,7>::const_iterator cend() const;
    bool get(int i)const;
    bool operator=(Seg7 const& s);
    std::array<bool,7> getSig()const;
private:
    std::array<bool,7> signals;
};


class Decoder{
public:
    static std::array<int,7> calc(std::vector<Seg7> const&inp);
    void learn(std::vector<Seg7> const&segs);
    Seg7 decode(Seg7 const&seg)const;
    size_t conv(Seg7 const&seg)const;
    using encoding=std::array<bool[7],10>;
    using mapping=std::array<int8_t ,7>;
    private:
    constexpr static const encoding def={{
            //a b c d e f g
            {1,1,1,0,1,1,1}, //0
            {0,0,1,0,0,1,0}, //1
            {1,0,1,1,1,0,1}, //2
            {1,0,1,1,0,1,1}, //3
            {0,1,1,1,0,1,0}, //4
            {1,1,0,1,0,1,1}, //5
            {1,1,0,1,1,1,1}, //6
            {1,0,1,0,0,1,0}, //7
            {1,1,1,1,1,1,1}, //8
            {1,1,1,1,0,1,1} //9
    }};

    mapping _mapping={-1,-1,-1,-1,-1,-1,-1};
};
class LedDigetDataset{
public:

    friend std::istream & operator>>(std::istream&ist,LedDigetDataset & f);

    std::vector<Seg7> inp;
    std::vector<Seg7> out;
};

class D8 {
public:
    using input_type=LedDigetDataset;
    static int P1(std::vector<input_type>const &input);
    static int P2(std::vector<input_type>const &input);
};

#endif //AOC21_D8_H
