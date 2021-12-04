//
// Created by flori on 04.12.21.
//

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
    std::string input;
    std::fstream file;
    file.open(filename,std::fstream::in);
    do{
        std::string s;
        getline(file,s);
        input.append(s+"\n");
    } while (file.good());

    std::string::size_type pos;
    do{
        pos=input.find("  ",pos);
        if(pos!=std::string::npos)
            input.replace(pos,2," ");
    } while (pos!=std::string::npos);


    pos=0;
    do{
        pos=input.find("\n ",pos);
        if(pos!=std::string::npos)
            input.replace(pos,2,"\n");
    } while (pos!=std::string::npos);

    auto x= stringSplit(input,"\n\n");

    auto sdraws= stringSplit(x[0],",");
    std::vector<size_t> draws;
    for(auto sdraw:sdraws)
    {
        draws.push_back(stoi(sdraw));
    }
    x.erase(x.begin(),++x.begin());
    std::vector<BingoBoard> boards;
    for(auto xx:x)
    {
        boards.emplace_back(xx);
    }

    P1(boards,draws);
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
                auto f=boards[i].calc1();
                std::cout<<f*draw<<std::endl;
                return 0;
            }
        }
    }
}

int D4::P2(std::vector<BingoBoard> boards, std::vector<size_t> draws) {
    std::vector<std::size_t> board_ids;
    for(int i=0;i<boards.size();i++)
    {
        board_ids.push_back(i);
    }

    for(auto draw:draws)
    {
        bool somethingToErase= false;
        std::vector<std::size_t> toErase;
        for(size_t i=0;i<board_ids.size();i++) {
            if (boards[board_ids[i]].set(draw)) {
                if (board_ids.size() == 1) {
                    auto f = boards[board_ids[i]].calc1();
                    std::cout << f * draw << std::endl;
                    return 0;
                } else {
                    somethingToErase = true;
                    toErase.push_back(board_ids[i]);
                }
            }
        }
        if(somethingToErase)
        {
            for(auto erase:toErase) {
                auto pos = std::find(board_ids.cbegin(), board_ids.cend(), erase);
                board_ids.erase(pos);
            }
        }

    }
}

BingoBoard::BingoBoard(std::string s) {
    auto xx= stringSplit(s,"\n");
    for(auto x:xx)
    {
        std::vector<boardType> r;
        std::vector<bool> hr;
        auto yy= stringSplit(x," ");
        for(auto y:yy)
        {
            if(y!="");
                r.push_back(stoi(y));
        }
        hr.resize(r.size());
        hits.push_back(hr);
        board.push_back(r);
    }
}

size_t BingoBoard::calc1() {
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
