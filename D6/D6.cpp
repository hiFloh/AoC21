/**
 * @author Florian Gapp
 * @date 06.12.21
 *
 * code for Day 6 of AoC (https://adventofcode.com/)
 */

#include <iterator>
#include <algorithm>
#include <execution>
#include "D6.h"
#include "../TimeMeasure.h"

int D6::mmain(arguments args) {
    std::string  filename="../D6/D6.txt";
//    filename="../test.txt";
    if(args.size()>=2)
    {
        filename=args[1];
    }
    auto input=readFile<input_type>(filename);

    auto t1=TimeMeasure::from();
    P1(input);
    t1.stop();
    auto t2=TimeMeasure::from();
    P2(input);
    t2.stop();
    std::cout<<"Part1: "<<t1.getDuration<std::milli>()<<"\nPart2: "<<t2.getDuration<std::milli>()<<std::endl;
    return 0;
}

int D6::P1(std::vector<input_type> const&input) {
    auto fishs=input;
    std::copy(fishs.begin(), fishs.end(), std::ostream_iterator<Fish>(std::cout, ","));
    std::cout<<std::endl;
    for(int i=0;i<80;i++) {
        size_t newFish=std::count_if(std::execution::par, fishs.begin(),fishs.end(),[](Fish &f){return f.grow();});
        for(int f=0;f<newFish;f++)
        {
            Fish fish;
            fishs.push_back(fish);
        }
    }
    std::cout<<fishs.size()<<std::endl;
    return fishs.size();
}

int D6::P2(std::vector<input_type>const &input) {

    std::vector<size_t> fishCount;
    fishCount.resize(9);
    for(auto f : input)
    {
        fishCount[f.getAge()]++;
    }
    for(int i=0;i<256;i++)
    {
        size_t newFisch=fishCount[0];
        fishCount.erase(fishCount.begin());
        fishCount[6]+=newFisch;
        fishCount.push_back(newFisch);
        size_t count=0;
        for(auto f:fishCount)
            count+=f;
        std::cout<<i+1<<":"<<count<<std::endl;
    }
    size_t count=0;
    for(auto f:fishCount)
        count+=f;
    return count;
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
