//
// Created by flori on 06.12.21.
//

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
            heights[i]+=crabSub.simulate(i);
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
            heights[i]+=crabSub.simulate2(i);
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

unsigned long CrabSubmarine::simulate(size_t i) {
    return i < height ? (height - i) : (i - height);
}

unsigned int calcFuleV2(unsigned int n) {
    unsigned int result=0;
    for(unsigned int i=0;i<n;i++)
    {
        result+=i+1;
    }
    return result;
}
unsigned long CrabSubmarine::simulate2(size_t i) {
    if (i > height)
        return calcFuleV2(i - height);
    else
        return calcFuleV2(height - i);
}


bool operator<(CrabSubmarine const& c1, CrabSubmarine const& c2)
{
    return c1.getHeight()<c2.getHeight();
}
