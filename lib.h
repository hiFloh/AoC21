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
#include <iomanip>
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
            if(!file.eof()) {
                file >> x;

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
/**
 * @brief c++ styled commandline arguments
 */
using arguments=std::vector<std::string>;

/**
 * @brief executes a class representing a Day of AoC
 * and prints results and time to std::cout
 * @tparam T class to execute
 * @param args commandline arguments
 * @return
 */
template<typename T>
int executeDay(arguments args)
{
    std::string  filename="../test.txt";
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
    std::cout<<"\nPart1: "<<std::setw(3)<<t1.getDuration()<<t1.getDurationUnit()<<" for "<<p1 <<std::endl;
    std::cout<<"\nPart2: "<<std::setw(3)<<t2.getDuration()<<t2.getDurationUnit()<<" for "<<p2 <<std::endl;
    return 0;
}

#endif //AOC21_LIB_H
