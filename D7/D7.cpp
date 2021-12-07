/**
 * @author Florian Gapp
 * @date 07.12.21
 *
 * code for Day 7 of AoC (https://adventofcode.com/)
 */

#include <algorithm>
#include "D7.h"

int D7::P1(std::vector<input_type>const &input) {

    auto max=std::max_element(input.cbegin(),input.cend());
    auto min=std::min_element(input.cbegin(),input.cend());

    std::vector<size_t> heights;
    heights.resize(max->getHeight()-min->getHeight());
    for(int i=0;i<heights.size();i++)
    {
        for(auto crabSub:input)
        {
            heights[i]+= crabSub.simulateMove1(i);
        }
    }
    auto idealHeight=std::min_element(heights.cbegin(),heights.cend());
    return *idealHeight;
}

int D7::P2(const std::vector<input_type> &input) {
    auto max=std::max_element(input.cbegin(),input.cend());
    auto min=std::min_element(input.cbegin(),input.cend());

    std::vector<size_t> heights;
    heights.resize(max->getHeight()-min->getHeight());
    for(int i=0;i<heights.size();i++)
    {
        for(auto crabSub:input)
        {
            heights[i]+= crabSub.simulateMove2(i);
        }
    }
    auto idealHeight=std::min_element(heights.cbegin(),heights.cend());
    return *idealHeight;
}


std::istream &operator>>(std::istream &ist, CrabSubmarine &f) {
    char c;
    ist>>f.height;
    if(ist.peek()==',')
        ist>>c;
    return ist;
}

size_t CrabSubmarine::getHeight() const {
    return height;
}

unsigned long CrabSubmarine::simulateMove1(size_t i) {
    return i < height ? (height - i) : (i - height);
}

unsigned long CrabSubmarine::simulateMove2(size_t i) {
    size_t diff = i > height ? i - height : height - i;

    unsigned int result=0;
    for(unsigned int i=0;i<diff;i++)
    {
        result+=i+1;
    }
    return result;
}


bool operator<(CrabSubmarine const& c1, CrabSubmarine const& c2)
{
    return c1.getHeight()<c2.getHeight();
}
