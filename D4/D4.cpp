/**
 * @author Florian Gapp
 * @date 04.12.21
 *
 * code for Day 4 of AoC (https://adventofcode.com/)
 */

#include "D4.h"
#include <sstream>
#include <iostream>
#include <algorithm>
int D4::mmain(arguments args) {
    std::string  filename="../D4/D4.txt";
//    filename= "../test.txt";
    if(args.size()>=2)
    {
        filename=args[1];
    }

    // read entire input file
    std::string input;
    std::fstream file;
    file.open(filename,std::fstream::in);
    do{
        std::string s;
        getline(file,s);
        input.append(s+"\n");
    } while (file.good());

    // remove double space
    std::string::size_type pos;
    do{
        pos=input.find("  ",pos);
        if(pos!=std::string::npos)
            input.replace(pos,2," ");
    } while (pos!=std::string::npos);

    // remove space at linestart
    pos=0;
    do{
        pos=input.find("\n ",pos);
        if(pos!=std::string::npos)
            input.replace(pos,2,"\n");
    } while (pos!=std::string::npos);

    // split sBoards
    auto sBoards= stringSplit(input, "\n\n");
    //split draws
    auto sDraws= stringSplit(sBoards[0], ",");
    std::vector<size_t> draws;
    //convert draws to int
    for(auto sDraw:sDraws)
    {
        draws.push_back(stoi(sDraw));
    }
    sBoards.erase(sBoards.begin(), ++sBoards.begin());
    // convert bingoboards
    std::vector<BingoBoard> boards;
    for(auto xx:sBoards)
    {
        boards.emplace_back(xx);
    }
    //execute Part1
    P1(boards,draws);
    //execute Part2
    P2(boards,draws);
    return 0;
}

int D4::P1(std::vector<BingoBoard> boards,std::vector<size_t> draws)
{
    for(auto draw:draws)
    {
        for(int i=0;i<boards.size();i++)
        {
            if(boards[i].set(draw))
            {
                auto f= boards[i].addUpNonHitFields();
                std::cout<<"part 1 result is "<<f*draw<<std::endl;
                return 0;
            }
        }
    }
    return -1;
}

int D4::P2(std::vector<BingoBoard> boards, std::vector<size_t> draws) {
    std::vector<std::size_t> boardsInGame;
    for(int i=0;i<boards.size();i++)
    {
        boardsInGame.push_back(i);
    }

    for(auto draw:draws)
    {
        bool boardHasWon= false;
        std::vector<std::size_t> boardsWon;
        for(size_t i=0; i < boardsInGame.size(); i++) {
            if (boards[boardsInGame[i]].set(draw)) {
                if (boardsInGame.size() == 1)
                {// if last board won
                    auto f = boards[boardsInGame[i]].addUpNonHitFields();
                    std::cout<<"part 2 result is "<<f*draw<<std::endl;
                    return 0;
                }
                else
                { // register board for delete
                    boardHasWon = true;
                    boardsWon.push_back(boardsInGame[i]);
                }
            }
        }
        //delete all boards which won
        if(boardHasWon)
        {
            for(auto boardWon:boardsWon) {
                boardsInGame.erase(std::find(boardsInGame.cbegin(), boardsInGame.cend(), boardWon));
            }
        }
    }
    return -1;
}

BingoBoard::BingoBoard(std::string s) {
    auto sRows= stringSplit(s, "\n");
    for(auto sRow:sRows)
    {
        std::vector<boardType> rowVal;
        std::vector<bool> rowHit;
        auto sCols= stringSplit(sRow, " ");
        for(auto col:sCols)
        {
            if(col != "");
                rowVal.push_back(stoi(col));
        }
        rowHit.resize(rowVal.size());
        hits.push_back(rowHit);
        board.push_back(rowVal);
    }
}

size_t BingoBoard::addUpNonHitFields() {
    size_t ret=0;
    for(size_t x=0;x<hits.size();x++)
    {
        for(size_t y=0;y<hits[x].size();y++)
        {
            if(hits[x][y]== false)
            {
                ret+=board[x][y];
            }
        }
    }
    return ret;
}

bool BingoBoard::set(BingoBoard::boardType num) {
    for(size_t x=0;x<board.size();x++)
    {
        for(size_t y=0;y<board[x].size();y++)
        {
            if(board[x][y]== num)
            {
                hits[x][y]= true;
                if(testRow(y) || testCol(x))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool BingoBoard::testRow(size_t num) {
    for(size_t x=0;x<hits.size();x++)
    {
        if(!hits[x][num])
            return false;
    }
    return true;
}

bool BingoBoard::testCol(size_t num) {
    for(size_t y=0;y<hits[num].size();y++)
    {
        if(!hits[num][y])
            return false;
    }
    return true;
}
