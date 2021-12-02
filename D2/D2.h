//
// Created by flori on 02.12.21.
//

#ifndef AOC21_D2_H
#define AOC21_D2_H

#include <vector>
#include <string>
#include <iostream>

class Command{
public:
    int value;
    std::string dir;
};

class shipp{
public:
    void execute(Command const&c);
    int getX()const;
    int getY()const;

protected:
    int x=0;
    int y=0;
};

class shipp2:public shipp{
public:
    void execute(Command const&c);

protected:
    int aim =0;
};

std::istream &operator>>(std::istream&input,Command&C);

class D2 {
    public:
    static int mmain(std::vector<std::string> const& args);

};



#endif //AOC21_D2_H
