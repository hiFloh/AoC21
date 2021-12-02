//
// Created by flori on 02.12.21.
//

#include "D2.h"
#include "../lib.h"

int D2::mmain(const std::vector<std::string> &args) {
    std::string  filename="../D2/D2.txt";
    if(args.size()>=2)
    {
        filename=args[1];
    }

    auto xx=readFile<Command>(filename);
    ship s;
    ship2 s2;
    for(auto x:xx)
    {
        s.execute(x);
        s2.execute(x);
    }

    std::cout<<"task1: x="<<s.getX()<<", y="<<s.getY()<<", x*y="<<s.getX()*s.getY()<<std::endl;
    std::cout<<"task2: x="<<s2.getX()<<", y="<<s2.getY()<<", x*y="<<s2.getX()*s2.getY()<<std::endl;


}

void ship::execute(const Command &c) {
    if(c.dir=="forward")
    {
        forward(c.value);
    }
    else if(c.dir=="up")
    {
        up(c.value);
    }
    else if(c.dir=="down")
    {
        down(c.value);
    }
    else
    {
        throw std::string("unkonwn command");
    }
}

int ship::getX() const {
    return x;
}

int ship::getY() const {
    return y;
}

void ship::up(int i) {
    y-=i;
}

void ship::down(int i) {
    y+=i;
}

void ship::forward(int i) {
    x+=i;
}

std::istream &operator>>(std::istream&input,Command&C)
{
input>>C.dir>>C.value;
return  input;
}

void ship2::up(int i) {
    aim-=i;
}

void ship2::down(int i) {
    aim+=i;
}

void ship2::forward(int i) {
    x+=i;
    y+=aim*i;
}
