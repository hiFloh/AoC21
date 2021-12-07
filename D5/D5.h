/**
 * @author Florian Gapp
 * @date 05.12.21
 *
 * header for Day 5 of AoC (https://adventofcode.com/)
 */

#ifndef AOC21_D5_H
#define AOC21_D5_H
#include "../lib.h"
#include <iostream>
class line{
public:
    line()=default;
    /**
     * create line from 2 Points
     * @param xf
     * @param yf
     * @param xt
     * @param yt
     */
    line(size_t xf, size_t yf, size_t xt, size_t yt);
    /**
     * @returns true if both y values are the same
     * @returns false otherwise
     */
    bool isHorizontal() const;
    /**
     * @returns true if both x values are the same
     * @returns false otherwise
     */
    bool isVertical() const;

    /**
     * @returns true if change on both axis is the same
     * @returns false otherwise
     */
    bool isDiagonalSame() const;
    /**
     * @returns true if change on both axis is the same but the sign is diffrent
     * @returns false otherwise
     */
    bool isDiagonalOposite() const;
    /**
     * @returns x position to
     */
    size_t xto();
    /**
     * @returns y position to
     */
    size_t yto();
    /**
     * @returns x position from
     */
    size_t xfrom();
    /**
     * @returns y position from
     */
    size_t yfrom();
    /**
     * input operator for point ("%u,%u -> %u,%u)
     * @param ist stream to read from
     * @param l line to read to
     * @return
     */
    friend std::istream & operator>>(std::istream & ist, line & l);
private:
    size_t xFrom;
    size_t yFrom;
    size_t xTo;
    size_t yTo;

};
std::istream & operator>>(std::istream & ist,line & l);

/**
 * Class managing a matrix
 * @tparam T
 */
template<class T>
class Matrix{
public:
    /**
     * sets the size of the matrix
     * @param x
     * @param y
     */
    void resize(size_t x,size_t y);
    /**
     * sets the x size of the matrix
     * @param x
     */
    void resizex(size_t x);
    /**
     * sets the y size of the matrix
     * @param y
     */
    void resizey(size_t y);
    /**
     * sets (x,y) to val
     * @param x
     * @param y
     * @param val
     */
    void set(size_t x,size_t y, T val);
    /**
     * @returns x size
     */
    size_t sizeX(){return board.size();};
    /**
     * @returns y size
     */
    size_t sizeY(){return ysize;};
    /**
     * gets the T object at (x,y)
     * @param x
     * @param y
     * @return
     */
    T& get(size_t x,size_t y);

//    std::vector<T> operator[](std::size_t pos);
private:
    size_t ysize=0;
    std::vector<std::vector<T>> board;
};

//template<class T>
//std::vector<T> Matrix<T>::operator[](std::size_t pos) {
//    return board[pos];
//}

template<class T>
void Matrix<T>::resizey(size_t y) {
    ysize=y+1;
    for(auto r=board.begin();r!=board.end();r++)
    {
        r->resize(ysize);
    }
}

template<class T>
void Matrix<T>::resizex(size_t x) {
    board.resize(x+1);
    resizey(ysize-1);
}

template<class T>
void Matrix<T>::resize(size_t x, size_t y) {

    board.resize(x);
    resizey(y);
}

template<class T>
void Matrix<T>::set(size_t x, size_t y, T val) {
    if(y>ysize)
        resizey(y);
    if(x>board.size())
        resizex(x);
    board[x][y]=val;
}

template<class T>
T& Matrix<T>::get(size_t x, size_t y) {
    if(y+1>(ysize))
        resizey(y);
    if(x+1>(board.size()))
        resizex(x);
    return board[x][y];
}
template<typename T>
std::ostream &operator<<(std::ostream&ost,Matrix<T> mat){
    for(auto y=0;y<mat.sizeX();y++)
    {
        for(auto x=0;x<mat.sizeY();x++)
    {

            ost<<mat.get(x,y);
        }
        ost<<std::endl;
    }
    return ost;
}

class D5 {
public:
    using input_type=line;
    static int mmain(arguments args);
    static int P1(std::vector<input_type> &input);
    static int P2(std::vector<line> &input);
};




#endif //AOC21_D5_H
