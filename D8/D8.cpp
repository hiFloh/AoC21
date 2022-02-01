/**
 * @author Florian Gapp
 * @date 08.12.21
 *
 * code for Day 8 of AoC (https://adventofcode.com/)
 */

#include "D8.h"
#include <algorithm>
#include <set>
bool IsTrue(bool b){return b;}
int D8::P1(const std::vector<input_type> &input) {


    int c1=0;
    int c4=0;
    int c7=0;
    int c8=0;
    for(auto in:input)
        for(auto x:in.out) {
            int i = std::count_if(x.cbegin(), x.cend(), IsTrue);


            switch (i) {
                case 2:
                    c1++;
                    break;
                case 4:
                    c4++;
                    break;
                case 3:
                    c7++;
                    break;
                case 7:
                    c8++;
                    break;
            }
        }
    return c1+c4+c7+c8;
return 0;
}

int D8::P2(const std::vector<input_type> &input) {
    int ret=0;
    for(int i=0;i<input.size();i++)
    {
        int v=0;
        Decoder d;
        d.learn(input[i].inp);
        for(int f=0;f<input[i].out.size();f++)
        {
            v=v*10;
            v+=d.conv(d.decode(input[i].out[f]));
        }
        ret+=v;
    }
    return ret;
}

std::istream &operator>>(std::istream &ist, Seg7 &f) {
    std::string s;
    ist>>s;
    f=s;
    return ist;
}

Seg7::Seg7(const std::string &s) {
    for(int i=0;i<signals.size();i++)
    {
        signals[i]= false;
    }
    for(auto c : s)
    {
        if(c>='a'&&c<='g')
        {
            signals[c-'a']=true;
        } else
        {
            throw std::string ("unknown char" );
        }
    }
}

std::array<bool,7>::const_iterator  Seg7::cbegin() const {
    return signals.cbegin();
}

std::array<bool,7>::const_iterator  Seg7::cend() const{
    return signals.cend();
}

Seg7::Seg7() {
    for(int i=0;i<signals.size();i++)
    {
        signals[i]= false;
    }
}

int Seg7::getCountOn()const {
    return std::count_if(cbegin(),cend(),[](bool i){return i;});
}

int Seg7::getCountOff()const {
    return std::count_if(cbegin(),cend(),[](bool i){return !i;});
}

bool Seg7::get(int i) const {
    return signals[i];
}

bool Seg7::operator=(const Seg7 & s) {
    return signals==s.signals;
}

Seg7::Seg7(std::array<bool, 7> &s) {
    signals=s;
}

std::array<bool, 7> Seg7::getSig() const{
    return signals;
}


std::istream &operator>>(std::istream &ist, LedDigetDataset &f) {

    while(ist.good())
    {
        std::string s;
        ist>>s;
        if(s!="|") {
            f.inp.push_back(s);
        }
        else
        {
            break;
        }
    }
    for(int i=0;i<4&&ist.good();i++)
    {
        std::string s;
        ist>>s;
        f.out.push_back(s);
    }
    return ist;
}


int findUniqe(Decoder::encoding const&enc,std::set<int> const&s,std::vector<std::pair<int,int>> ifyable)
{
    std::array<bool,7> tmp={1,1,1,1,1,1,1};
    for(int i=0;i<7;i++)
    {

        for(int f=0;f<10;f++)
        {
            if(std::find_if(ifyable.cbegin(),ifyable.cend(),[f](std::pair<int,int> s){return s.first==f;})!=ifyable.cend())
            {
                if(std::find(s.cbegin(),s.cend(),f)!=s.cend())
                {
                    if(enc[i][f]==0)
                    {
                        tmp[i]=0;
                    }
                }
                else
                {
                    if(enc[i][f]!=0)
                    {
                        tmp[i]=0;
                    }
                }
            }
        }
    }
    if(std::count_if(tmp.cbegin(),tmp.cend(), IsTrue)==1)
        return std::find(tmp.cbegin(),tmp.cend(),true)-tmp.cbegin();
    return -1;
    std::cout<<(1);
}


std::vector<std::pair<int,int>> getIdentifyable(Decoder::encoding const&enc,Decoder::mapping m)
{
    std::vector<std::pair<int,int>> ret;
    std::array<int,10> tmp={0,0,0,0,0,0,0};
    for(int i=0; i < 7; i++) {
        if (m[i] == -1)
        {
            for(int f=0;f<10;f++)
            {
                if(enc[i][f])
                {
                    tmp[f]++;
                }
            }
        }
    }
    auto x=tmp;
    auto end=std::unique(x.begin(),x.end());
    for(auto a=x.begin();a<end;a++)
    {
        if(std::count(tmp.cbegin(),tmp.cend(),*a)==1)
        {
            ret.push_back(std::pair<int,int>(std::find(tmp.begin(),tmp.end(),*a)-tmp.begin(),*a));
        }
    }
    return ret;
}

bool s(std::pair<int,int> s)
{
    return s.second==2;
}
void Decoder::learn(const std::vector<Seg7> &segs) {
//    std::vector<std::array<short,7>> data;
    auto x=Decoder::calc(segs);
    int8_t e=std::distance(x.cbegin(),std::find(x.cbegin(),x.cend(),-6));
    int8_t b=std::distance(x.cbegin(),std::find(x.cbegin(),x.cend(),-4));
    int8_t f=std::distance(x.cbegin(),std::find(x.cbegin(),x.cend(),-1));

    std::vector<Seg7> s23;
    std::copy_if(segs.cbegin(),segs.cend(),std::back_inserter(s23),[](Seg7 s){return s.getCountOn()==2||s.getCountOn()==3;});
    auto x23=Decoder::calc(s23);
    int8_t a=std::distance(x23.cbegin(),std::find(x23.cbegin(),x23.cend(),-1));

    x23[f]=1;
    int8_t c=std::distance(x23.cbegin(),std::find(x23.cbegin(),x23.cend(),0));

    std::vector<Seg7> s6;
    std::copy_if(segs.cbegin(),segs.cend(),std::back_inserter(s6),[](Seg7 s){return s.getCountOn()==6||s.getCountOn()==5;});
    auto x6=Decoder::calc(s6);

    x6[f]=1;
    int8_t d=std::distance(x6.cbegin(),std::find(x6.cbegin(),x6.cend(),-1));
    x[d]=1;
    int8_t g=std::distance(x.cbegin(),std::find(x.cbegin(),x.cend(),-3));
    _mapping={a,b,c,d,e,f,g};
    std::cout <<"as";
}

std::array<int, 7> Decoder::calc(std::vector<Seg7> const& inp) {
    std::array<int, 7> s;
    std::fill(s.begin(),s.end(),-1*inp.size());

    auto sc=inp.cbegin();
    while(sc!=inp.cend())
    {
        for(int i=0;i<s.size();i++)
        {
                s[i]+=sc->get(i);
        }
        sc++;
    }
    return  s;
}

size_t Decoder::conv(const Seg7 &seg) const {
    for(int i=0;i<def.size();i++)
    {
        bool b=true;
        for(int f=0;f<sizeof(def[i]);f++)
        {
            b&=seg.get(f)==def[i][f];
        }
        if(b)
            return i;
    }

}

Seg7 Decoder::decode(const Seg7 &seg) const{
    std::array<bool,7> s;
    for(int i=0;i<7;i++)
    {
        s[i]=seg.get(_mapping[i]);
    }
    return Seg7(s);
}
