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

class ship{
public:
    void execute(Command const&c);
    int getX()const;
    int getY()const;

protected:
    virtual void up(int i);
    virtual void down(int i);
    virtual void forward(int i);

    int x=0;
    int y=0;
};

class ship2: public ship{

protected:
    int aim =0;

    void up(int i) override;

    void down(int i) override;

    void forward(int i) override;
};

std::istream &operator>>(std::istream&input,Command&C);

class D2 {
    public:
    static int mmain(std::vector<std::string> const& args);

};



#endif //AOC21_D2_H
