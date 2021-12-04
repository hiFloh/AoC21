//
// Created by flori on 04.12.21.
//

#ifndef AOC21_D4_H
#define AOC21_D4_H

#include <lib.h>

class BingoBoard{
public:
    using boardType=size_t;
    BingoBoard(std::string s);
    bool set(boardType num);
    bool hasWone();

    size_t calc1();

private:
    bool testRow(size_t num);
    bool testCol(size_t num);
    std::vector<std::vector<boardType>> board;
    std::vector<std::vector<bool>> hits;
};

class D4 {
public:
    static int mmain(arguments);
    static int P1(std::vector<BingoBoard> boards,std::vector<size_t> draws);
    static int P2(std::vector<BingoBoard> boards,std::vector<size_t> draws);
};


#endif //AOC21_D4_H
