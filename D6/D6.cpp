/**
 * @author Florian Gapp
 * @date 06.12.21
 *
 * code for Day 6 of AoC (https://adventofcode.com/)
 */

#include <iterator>
#include <algorithm>
#include "D6.h"

int D6::mmain(arguments args) {
    std::string  filename="../D6/D6.txt";
//    filename="../test.txt";
    if(args.size()>=2)
    {
        filename=args[1];
    }
    auto input=readFile<input_type>(filename);
    P1(input);
    P2(input);
    return 0;
    return 0;
}

void D6::P1(std::vector<input_type> &input) {
    auto fishs=input;
    std::copy(fishs.begin(), fishs.end(), std::ostream_iterator<Fish>(std::cout, ","));
    std::cout<<std::endl;
    for(int i=0;i<80;i++) {
        size_t newFish=std::count_if(fishs.begin(),fishs.end(),[](Fish &f){return f.grow();});
        for(int f=0;f<newFish;f++)
        {
            Fish fish;
            fishs.push_back(fish);
        }
//        std::copy(fishs.begin(), fishs.end(), std::ostream_iterator<Fish>(std::cout, ","));
//        std::cout<<std::endl;
    }
    std::cout<<fishs.size()<<std::endl;
}

void D6::P2(std::vector<input_type> &input) {
    auto fishs=input;
    std::copy(fishs.begin(), fishs.end(), std::ostream_iterator<Fish>(std::cout, ","));
    std::cout<<std::endl;
    for(int i=0;i<256;i++) {
        size_t newFish=std::count_if(fishs.begin(),fishs.end(),[](Fish &f){return f.grow();});
        for(int f=0;f<newFish;f++)
        {
            Fish fish;
            fishs.push_back(fish);
        }
        std::cout<<i<<std::endl;
//        std::copy(fishs.begin(), fishs.end(), std::ostream_iterator<Fish>(std::cout, ","));
//        std::cout<<std::endl;
    }
    std::cout<<fishs.size()<<std::endl;
}

Fish::Fish():age(8) {

}

bool Fish::grow() {
    if(age>0) {
        age--;
        return false;
    } else {
        age = 6;
        return true;
    }
}

std::istream &operator>>(std::istream &ist, Fish &f) {
    char c;
    ist>>f.age;
    if(ist.peek()==',')
        ist>>c;
    return ist;
}

size_t Fish::getAge() const{
    return age;
}

std::ostream &operator<<(std::ostream &ost, const Fish &f) {
    ost<<f.getAge();
    return ost;
}
