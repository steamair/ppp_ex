

#include <iostream>
#include <stdlib.h>
#include <vector>
template<typename iterator, typename T,typename pred>
int count_if(iterator first, iterator last, pred condition)
{
    int counter=0;
    while (first != last)
    {
        if(condition(*first)) ++counter;
        ++first;
    }
    return counter;
}

bool is_odd(int i){ return (i%2!=0);}

int main(){
    std::vector<int> s={1,2,3,4,5,6};
    int counter=0;
    counter=count_if(s.begin(),s.end(),is_odd);
    std::cout<<"# of odd number in the seq is "<<counter<<"\n";
    return 0;
}