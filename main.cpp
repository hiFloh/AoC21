/**
 * @author Florian Gapp
 * @date 01.12.2021
 *
 * Main program selecting and executing tasks from Advent of Code(https://adventofcode.com/)
 */

#include "D1/D1.h"
#include "D2/D2.h"
#include "D3/D3.h"
#include "D4/D4.h"
#include "D5/D5.h"
#include <iostream>
#include <D6/D6.h>
#include <D7/D7.h>
#include <D8/D8.h>

int main(int argc,char**argv) {
    std::vector<std::string> args;
    for(int i=0;i<argc;i++)
    {
        args.push_back(std::string(argv[i]));
    }

    if(args.size()>1)
    {
        size_t day=stoi(args[1]);
        args.erase(++args.cbegin());
        switch (day) {
            case 1:
                return D1::mmain(args);
            case 2:
                return D2::mmain(args);
            case 3:
                return D3::mmain(args);
            case 4:
                return D4::mmain(args);
            case 5:
                return executeDay<D5>(args);
                return D5::mmain(args);
            case 6:
                return executeDay<D6>(args);
            case 7:
                return executeDay<D7>(args);
            case 8:
                return executeDay<D8>(args);
//            case 9:
//                return executeDay<D9>(args);
        }
    }
    else
    {
        std::cout<<"x";
    }


    return 0;
}
