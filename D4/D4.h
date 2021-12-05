/**
 * @author Florian Gapp
 * @date 04.12.21
 *
 * header for Day 4 of AoC (https://adventofcode.com/)
 */

#ifndef AOC21_D4_H
#define AOC21_D4_H

#include <lib.h>


class BingoBoard{
public:
    using boardType=size_t;
    /**
     * creates BingoBoard from string Input
     * @param s string
     */
    BingoBoard(std::string s);
    /**
     * executes a draw with specific number
     * @param num
     * @return true if board has won
     */
    bool set(boardType num);

    /**
     * adds up the values of all fields which had no hit.
     * @return
     */
    size_t addUpNonHitFields();

private:
    /**
     * checks row num for winn
     * @param num
     * @return true if entire row has been hit
     * @return false if no win in selected row
     */
    bool testRow(size_t num);

    /**
     * checks col num for winn
     * @param num
     * @return true if entire col has been hit
     * @return false if no win in selected col
     */
    bool testCol(size_t num);
    /// @brief stores values of board
    std::vector<std::vector<boardType>> board;
    /// @brief stores hits of board
    std::vector<std::vector<bool>> hits;
};

class D4 {
public:
    static int mmain(arguments);

private:
    static int P1(std::vector<BingoBoard> boards,std::vector<size_t> draws);
    static int P2(std::vector<BingoBoard> boards,std::vector<size_t> draws);
};


#endif //AOC21_D4_H
