#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include "functs.h"
std::map<int,int> m;
int cmp(std::string &a, std::unordered_set<char> &b);
int decode(std::vector<std::string> &inp, std::vector<std::string> &sig)
{
    std::unordered_set<char> cf,bd;
    int tmp,i;
    for(tmp=0; inp[tmp].size()!=2; tmp++);
    cf.insert(inp[tmp][0]);
    cf.insert(inp[tmp][1]);
    for(tmp=0; inp[tmp].size()!=4; tmp++);
    for(i=0; i<4; i++)
    {
        if(!cf.count(inp[tmp][i]))
            bd.insert(inp[tmp][i]);
    }
    int n=0;
    for(i=0; i<4; i++)
    {
        tmp=sig[i].length();
        tmp*=10;
        tmp+=cmp(sig[i],cf);
        tmp*=10;
        tmp+=cmp(sig[i],bd);
        n*=10;
        n+=m[tmp];
    }
    return n;
}

int cmp(std::string &a, std::unordered_set<char> &b)
{
    int c=0;
    for(int i=0; i<a.size(); i++)
        c+=b.count(a[i])?1:0;
    return c;
}

int main()
{
    std::ifstream fin("inp8.txt");
    std::vector<std::string> inp,sgn;
    int count=0, i;
    m[621]=0;
    m[220]=1;
    m[511]=2;
    m[521]=3;
    m[422]=4;
    m[512]=5;
    m[612]=6;
    m[320]=7;
    m[722]=8;
    m[622]=9;
    while(fin)
    {
        for(i=1; i<=10; i++)
            inp.push_back(readstr(fin));
        for(i=1; i<=4; i++)
            sgn.push_back(readstr(fin));
        count+=decode(inp,sgn);
        inp.clear();
        sgn.clear();
    }
    fin.close();
    std::cout<<count<<std::endl;
    getchar();
    return 0;
}