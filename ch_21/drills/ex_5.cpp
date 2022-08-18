

#include <stdlib.h>
#include <iostream>
#include <vector>


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

template<typename T, typename iterator>
void find(const T& object, iterator first, iterator last)
{
    int finder=0;
    while (first!=last)
    {
        if (*first==object) 
        {
            std::cout<<"position of the value appears at"<<finder<<"\n";
            if (*first!=object)
                continue;}
            ++first;
            ++finder;
 
    }
    
}

int main(){
    std::vector<char> vec{'s','s','s','t','s','t','s'};
    int s;
    char val='s';
    find(val,vec.begin(),vec.end());
    //std::cout<<"# of occurence "<<count(val,vec.begin(),vec.end())<<"\n";
    //std::cout<<"value found in "<<s<<"\n";
    return 0;
}