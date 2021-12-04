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


std::vector<std::string> stringSplit(std::string src,std::string pattern);


using arguments=std::vector<std::string>;

#endif //AOC21_LIB_H
