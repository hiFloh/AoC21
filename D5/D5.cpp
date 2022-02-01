/**
 * @author Florian Gapp
 * @date 05.12.21
 *
 * code for Day 5 of AoC (https://adventofcode.com/)
 */

#include "D5.h"

int D5::mmain(arguments args) {
    std::string  filename="../D5/D5.txt";
//    filename="../test.txt";
    if(args.size()>=2)
    {
        filename=args[1];
    }
    auto input=readFile<line>(filename);
    P1(input);
    P2(input);
    return 0;
}

int D5::P1(std::vector<line> &input) {
    Matrix2D<size_t> matrix;
    for(auto i:input)
    {
        if(i.isHorizontal())
        {
            if(i.xfrom()<i.xto()) {
                for (size_t x = i.xfrom(); x <= i.xto(); x++) {
                    matrix.get(x, i.yfrom()) += 1;
                }
            }
            else
            {
                for (size_t x = i.xto(); x <= i.xfrom(); x++) {
                    matrix.get(x, i.yfrom()) += 1;
                }
            }
        }
        if(i.isVertical())
        {
            if(i.yfrom()<i.yto()) {
                for (size_t y = i.yfrom(); y <= i.yto(); y++) {
                    matrix.get(i.xfrom(), y) += 1;
                }
            }
            else
            {
                for (size_t y = i.yto(); y <= i.yfrom(); y++) {
                    matrix.get(i.xfrom(), y) += 1;
                }
            }
        }
    }
    // count positions with at least one intersection
    size_t count=0;
    for(auto y=0;y<matrix.sizeX();y++)
    {
        for(auto x=0;x<matrix.sizeY();x++)
        {

            if(matrix.get(x,y)>1)
                count++;
        }
    }
    // print result
    //std::cout<<matrix<<std::endl;
    std::cout<<"P1: "<<count;
    return count;
}
int D5::P2(std::vector<line> &input) {
    Matrix2D<size_t> matrix;
    for(auto i:input)
    {
        if(i.isHorizontal())
        {
            if(i.xfrom()<i.xto()) {
                for (size_t x = i.xfrom(); x <= i.xto(); x++) {
                    matrix.get(x, i.yfrom()) += 1;
                }
            }
            else
            {
                for (size_t x = i.xto(); x <= i.xfrom(); x++) {
                    matrix.get(x, i.yfrom()) += 1;
                }
            }
        }
        if(i.isVertical())
        {
            if(i.yfrom()<i.yto()) {
                for (size_t y = i.yfrom(); y <= i.yto(); y++) {
                    matrix.get(i.xfrom(), y) += 1;
                }
            }
            else
            {
                for (size_t y = i.yto(); y <= i.yfrom(); y++) {
                    matrix.get(i.xfrom(), y) += 1;
                }
            }
        }
        if(i.isDiagonalSame())
        {
            if(i.xfrom()>i.xto()) {
                for (size_t f = 0; f < i.xfrom() - i.xto()+1; f++)
                {
                    matrix.get(i.xto()+f,i.yto()+f)+=1;
                }
            } else
            {
                for (size_t f = 0; f < i.xto() - i.xfrom()+1; f++)
                {
                    matrix.get(i.xfrom()+f,i.yfrom()+f)+=1;
                }
            }
        }
        if(i.isDiagonalOposite())
        {
            if(i.xfrom()>i.xto()) {
                for (size_t f = 0; f < i.xfrom() - i.xto()+1; f++)
                {
                    matrix.get(i.xfrom()-f,i.yfrom()+f)+=1;
                }
            } else
            {
                for (size_t f = 0; f < i.xto() - i.xfrom()+1; f++)
                {
                    matrix.get(i.xto()-f,i.yto()+f)+=1;
                }
            }
        }
    }

    // count positions with at least one intersection
    size_t count=0;
    for(auto y=0;y<matrix.sizeX();y++)
    {
        for(auto x=0;x<matrix.sizeY();x++)
        {

            if(matrix.get(x,y)>1)
                count++;
        }
    }
    // print results
    //std::cout<<matrix<<std::endl;
    std::cout<<"P2: "<<count;
    return count;
}

std::istream &operator>>(std::istream &ist, line &l) {
    size_t xf,yf,xt,yt;
    char c;
    ist>>xf;
    ist>>c;
    ist>>yf;
    ist>>c;
    ist>>c;
    ist>>xt;
    ist>>c;
    ist>>yt;
    l=line(xf,yf,xt,yt);
    return ist;
}

std::ostream &operator<<(std::ostream &ost, std::vector<std::vector<size_t>> mat) {
    for(auto x:mat)
    {
        for(auto y:x)
        {
            ost<<y;
        }
        ost<<std::endl;
    }
    return ost;
}

line::line(size_t xf, size_t yf, size_t xt, size_t yt):xFrom(xf),yFrom(yf),xTo(xt),yTo(yt) {
}

bool line::isVertical() const{
    return xFrom==xTo;
}


bool line::isHorizontal() const{
    return yFrom==yTo;
}

size_t line::xto() {
    return xTo;
}

size_t line::yto() {
    return yTo;
}

size_t line::xfrom() {
    return xFrom;
}

size_t line::yfrom() {
    return yFrom;
}

bool line::isDiagonalSame() const {
    return (xFrom-xTo)==(yFrom-yTo);
}

bool line::isDiagonalOposite() const {
    return (xTo-xFrom)==(yFrom-yTo);
}

