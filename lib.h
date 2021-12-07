/**
 * @author Florian Gapp
 * @date 01.12.21
 * helper functions for AoC (https://adventofcode.com/)
 */


#ifndef AOC21_LIB_H
#define AOC21_LIB_H
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
#include <iostream>
#include "TimeMeasure.h"
/**
 *
 * @tparam T type of data
 * @param filename to read from
 * @return vector of type T
 * @brief sores each line of a file in an vector
 */
template <typename T>
std::vector<T> readFile(std::string filename)
{
    std::fstream file;

    file.open(filename,std::fstream::in);
    std::vector<T> values;

    if(file.is_open())
    {
        while (file.good())
        {
            T x;
            file >> x;
            if(!file.eof()) {
                values.push_back(x);
            }
        }
    }

    file.close();
    return values;
}

/**
 * splits string at pattern
 * @param src string to split
 * @param pattern pattern to search for
 * @return vector containing all parts
 */
std::vector<std::string> stringSplit(std::string src,std::string pattern);

using arguments=std::vector<std::string>;

template<typename T>
int executeDay(arguments args)
{
    std::string  filename="../D6/D6.txt";
    filename="../test.txt";
    if(args.size()>=2)
    {
        filename=args[1];
    }
    auto input=readFile<typename T::input_type>(filename);

    auto t1=TimeMeasure::from();
    int p1=T::P1(input);
    t1.stop();
    auto t2=TimeMeasure::from();
    int p2=T::P2(input);
    t2.stop();
    std::cout<<"\nPart1: "<<p1 <<" after "<<t1.getDurationInMicroseconds()<<"us \nPart2: "<<p2<<" after "<<t2.getDurationInMicroseconds()<<"us"<<std::endl;
    return 0;
}

#endif //AOC21_LIB_H
