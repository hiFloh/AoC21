//
// Created by flori on 04.12.21.
//

#include "lib.h"

std::vector<std::string> stringSplit(std::string src, std::string pattern) {
    std::vector<std::string> split;
    std::string::size_type pos;
    std::string::size_type lastPos=0;
    do {
        pos=src.find(pattern,lastPos);
        if(pos!=std::string::npos)
        {
            split.push_back(src.substr(lastPos,pos-lastPos));
            lastPos=pos+pattern.size();
        }
    } while (pos!=std::string::npos);
    if(lastPos!=src.size())
        split.push_back(src.substr(lastPos));
    return split;
}