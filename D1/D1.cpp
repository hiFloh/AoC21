/**
 * @author Florian Gapp
 * @date 01.12.21
 *
 * code for Day 1 of AoC (https://adventofcode.com/)
 */


#include "D1.h"
#include "../lib.h"
#include <iostream>

/**
 *
 * @param heightProfile
 * @return nuber of elements where the next one is higher
 */
int D1::getHeight(std::vector<int> const& heightProfile)
{
    int increasedCount=0;
 for (auto height=++heightProfile.cbegin(); height != heightProfile.cend(); height++)
 {
    if(*height > *(height - 1))
        increasedCount++;
 }
 return increasedCount;
}

/**
 *
 * @param heightProfile
 * @param count
 * @return the smoothed vector
 * @brief averages a vector to smooth it out
 */
std::vector<int> D1::getAverage(const std::vector<int> &heightProfile,size_t const&count=3) {
    std::vector<int> summed;
    auto end=heightProfile.cend()-(count-1);
    for (auto itr=heightProfile.cbegin(); itr != end; itr++)
    {
        int sum=0;
        auto  itr2=itr;
        for(int i=0;i<count;i++)
        {
            sum+=*itr2;
            itr2++;
        }
        summed.push_back(sum);
    }
    return summed;
}

/**
 *
 * @param args
 * @return
 * @brief executes day1 task
 */
int D1::mmain(std::vector<std::string> const&args) {
    std::string  filename="../D1/D1.txt";
    if(args.size()>=2)
    {
        filename=args[1];
    }
    auto heightProfile= readFile<int>(filename);
    auto increased= getHeight(heightProfile);
    auto HeightProfileAverage = getAverage(heightProfile);
    auto increasedAverage= getHeight(HeightProfileAverage);
    std::cout <<"Part1: "<< increased << " times increased"<<std::endl;
    std::cout <<"Part2: " << increasedAverage<< " times increased"<<std::endl;
    return EXIT_SUCCESS;
}
