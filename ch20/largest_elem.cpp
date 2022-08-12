
#include "../std_lib_facilities.h"

template<typename Iterator>
Iterator high(Iterator first, Iterator last)
//  return an iterator to the element in [first:last) that has the highest value
{
    Iterator high=first;
    for (Iterator p=first; p!=last;++p)
        if(*high<*p) high=p;
    return high;
}


// the high() template function can be used for any sequence defined by a
// pair of iterators. for example, we can exactly replicate our example
// program

double* get_from_jack(int* count);      //jack puts doubles into an
                                        // array and returns the number
                                        // of elements in *count
vector<double>* get_from_jill();        //jill fills the vector

void fct()
{
    int jack_count=0;
    double* jack_data=get_from_jack(&jack_count);
    vector<double>* jill_data=get_from_jill();

    double* jack_high=high(jack_data,jack_data+jack_count);
    vector<double>& v=*jill_data;
    double* jill_high=high(&v[0],&v[0]+v.size());
    cout<<"jill's high"<<*jill_high<<";jack's high"<<*jack_high;
    //.....
    delete[] jack_data;
    delete jill_data;
}