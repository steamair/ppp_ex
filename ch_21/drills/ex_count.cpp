

// implement count()

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <ostream>

template<typename iterator, typename T>
int count(const T& object, iterator first, iterator last)
{
    int recorder=0;
    while (first!=last)
    {
        if (*first==object) ++recorder;
        ++first;
    }
    return recorder;
}

int main(){
    std::vector<char> vec{'s','s','s','s','s','s','s'};
    char val='s';
    std::cout<<"# of occurence "<<find(val,vec.begin(),vec.end())<<"\n";
    return 0;
}