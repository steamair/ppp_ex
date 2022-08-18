

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <math.h>

// read floating values
void read_values(std::vector<double>& a)
{
    double input;
    std::cin>>input;
    if (!std::cin) throw std::runtime_error("not a valid input, please try again");
    a.push_back(input);
}

//copy vectors

void copy_vec(std::vector<double> vd, std::vector<int>& vi)
{
    for (int i=0;i<vd.size();++i)
        vi[i]=vd[i];
}
template<typename T>
T sum_vec(std::vector<T> vd)
{
    T accu=0;
    for (int i=0;i<vd.size();++i)
        accu+=vd[i];
    return accu;
}


int main()
{
    std::vector<double> vd;
    std::vector<int> vi(16);
    std::vector<double> vd2;
    double diff=0.0;
    double diff_vec=0.0;
    double mean=0;
    int i=0;
    std::cout<<"please enter a floating value"<<"\n";
    for (int i=0;i<16;++i)
        read_values(vd);
    for (auto c: vd)
        std::cout<<c<<"\n";

    // copy value from vd to vi
    copy_vec(vd,vi);
    for (int i=0;i<vd.size();++i)
    {
        diff=std::abs(vi[i]-vd[i]);
        std::cout<<"("<<vi[i]<<","<<vd[i]<<")"<<"\n";
        std::cout<<"difference is "<<diff<<"\n";
    }
    
    diff_vec=sum_vec(vd)-sum_vec(vi);
    std::cout<<"difference between the sum of vd and sum of vi is "<<diff_vec<<'\n';

    std::reverse(vd.begin(),vd.end());
    mean=sum_vec(vd)/vd.size();
    std::cout<<"mean is "<<mean<<"\n";
    for (int i =0; i<vd.size();++i)
    {
        if (vd[i]<mean)
            vd2.push_back(vd[i]);
    }
    //sort

    std::sort(vd.begin(),vd.end());
    for (auto p: vd2)
        std::cout<<p<<"\n";
    
    
}