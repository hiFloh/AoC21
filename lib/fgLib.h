//
// Created by flori on 09.12.21.
//

#ifndef AOC21_FGLIB_H
#define AOC21_FGLIB_H
#include <functional>
namespace fg{

//https://gist.github.com/martinmoene/9410391
        template<class T>
        bool between(T const& val, T const& lo, T const& hi)
        {
            return between( val, lo, hi, std::less<T>() );
        }

        template<class T, class Compare>
        bool between(T const& val, T const& lo, T const& hi, Compare comp)
        {
            return comp(lo, val) && comp(val, hi);
        }
}
#endif //AOC21_FGLIB_H
