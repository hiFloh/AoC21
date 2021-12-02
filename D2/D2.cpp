//
// Created by flori on 02.12.21.
//

#include "D2.h"
#include "../lib.h"

int D2::mmain(const std::vector<std::string> &args) {
//    std::string  filename="../test.txt";
    std::string  filename="../D2/D2.txt";
    if(args.size()>=2)
    {
        filename=args[1];
    }

    auto xx=readFile<Command>(filename);
    shipp s;
    shipp2 s2;
    for(auto x:xx)
    {
        s.execute(x);
        s2.execute(x);
    }

    std::cout<<"task1: x="<<s.getX()<<", y="<<s.getY()<<", x*y="<<s.getX()*s.getY()<<std::endl;
    std::cout<<"task2: x="<<s2.getX()<<", y="<<s2.getY()<<", x*y="<<s2.getX()*s2.getY()<<std::endl;


}

void shipp::execute(const Command &c) {
    if(c.dir=="forward")
    {
        x+=c.value;
    }
    else if(c.dir=="up")
    {
        y-=c.value;
    }
    else if(c.dir=="down")
    {
        y+=c.value;
    }
    else
    {
        throw std::string("unkonwn command");
    }
}

int shipp::getX() const {
    return x;
}

int shipp::getY() const {
    return y;
}

std::istream &operator>>(std::istream&input,Command&C)
{
input>>C.dir>>C.value;
return  input;
}

void shipp2::execute(const Command &c) {
    if(c.dir=="forward")
    {
        x+=c.value;
        y+=aim*c.value;
    }
    else if(c.dir=="up")
    {
        aim-=c.value;
    }
    else if(c.dir=="down")
    {
        aim+=c.value;
    }
    else
    {
        throw std::string("unkonwn command");
    }
}
