/**
 * @author Florian Gapp
 * @date 03.12.21
 *
 * code for Day 3 of AoC (https://adventofcode.com/)
 */

#include <iostream>
#include <cmath>
#include <algorithm>
#include "D3.h"

int D3::mmain(arguments args) {
    std::string  filename="../D3/D3.txt";
    if(args.size()>=2)
    {
        filename=args[1];
    }
    auto input=readFile<std::string>(filename);
    A1(input);
    A2(input);
    return 0;
}

/**
 * Part2 of Day 3
 * @param inp
 * @return
 */
int D3::A2(std::vector<std::string> const &inp) {

    std::vector<std::string> inp2=inp;
    for(int i=0;(i<inp[0].size())&(inp2.size()>1);i++)
    {
        auto is1=[&i](std::string c){return c[i]=='1';};
        auto is0=[&i](std::string s){return s[i]=='0';};

        size_t once=std::count_if(inp2.cbegin(),inp2.cend(),is1);

        if(once>=(inp2.size()-once))
            inp2.erase(std::remove_if(inp2.begin(),inp2.end(),is0),inp2.end());
        else
            inp2.erase(std::remove_if(inp2.begin(),inp2.end(),is1),inp2.end());
    }
    size_t oxygenGeneratorRating= bin2Int(inp2[0]);


    inp2=inp;
    for(int i=0;(i<inp[0].size())&(inp2.size()>1);i++)
    {
        auto is1=[&i](std::string c){return c[i]=='1';};
        auto is0=[&i](std::string s){return s[i]=='0';};

        size_t once=std::count_if(inp2.cbegin(),inp2.cend(),is1);

        if(once>=(inp2.size()-once))
            inp2.erase(std::remove_if(inp2.begin(),inp2.end(),is1),inp2.end());
        else
            inp2.erase(std::remove_if(inp2.begin(),inp2.end(),is0),inp2.end());
    }
    size_t Co2ScrubberRating= bin2Int(inp2[0]);


    std::cout << "oxygen generator rating: " << oxygenGeneratorRating << "\nCO2 scrubber rating: " << Co2ScrubberRating << "\noxygen generator rating*CO2 scrubber rating: " << Co2ScrubberRating * oxygenGeneratorRating;
    return 0;
}
/**
 * Part 1 of Day 3
 * @param inp
 * @return
 */
int D3::A1(std::vector<std::string> const&inp) {
    std::vector<size_t> once;
    once.resize(inp[0].length());
    for(auto s :inp)
    {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
            {
                once[i]++;
            }
        }
    }
    size_t gammarate=0x0;
    size_t epsilonrate=0x0;
    for(int i=0;i<once.size();i++)
    {
        gammarate=gammarate << 1;
        epsilonrate=epsilonrate << 1;
        if(once[i]>(inp.size()-once[i]))
        {
            gammarate|=0x1;
        }
        else
        {
            epsilonrate|=0x1;
        }
    }

    std::cout << "gammarate: "<<gammarate<<"\nepsilonrate: "<<epsilonrate<<"\ngammarate*epsilonrate:"<<gammarate * epsilonrate<<std::endl;
    return 0;
}
/**
 * reads string of 0 and 1s to an unsigned integer(from binary)
 * @param s
 * @return
 */
int D3::bin2Int(std::string const &s) {
    size_t val=0x0;
    for(int i=0;i<s.size();i++)
    {
        val=val<<1;
        if(s[i]=='1')
        {
            val|=0x1;
        }
    }
    return val;
}
