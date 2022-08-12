

//

class vector{
    int sz;
    double* elem;
public:
    vector(vector&& a);     //move constructor
    vector& operator=(vector&&);        //move assignment
    ///....
};

//&& is called an rvalue refernece, we use it for defining move operations.
//move operations do not take const arguments

vector::vector(vector&& a)
        :sz{a.sz},elem{a.elem}      //copy a's elem and sz
{
    a.sz=0;             //make a the empty vector
    a.elem=nullptr;
}

vector& vecotr::operator=(vecotr&& a)       //move a to this vector
{
    delete[] elem;          //deallocate old space
    elem=a.elem;            //copy a's elem and sz
    sz=a.sz;                
    a.elem=nullptr;     //make a the empty vector
    a.sz=0;     
    return *this;       //return a self-reference



}

/*

1. a class needs a destructor is simply that is has members that are pointers
or references. if a class has a pointer or a reference member, it often needs
a destructor and copy operations

2. a class that needs a destructor almost always aslo needs a copy 
constructor and a copy assignment. the reason is simply that if an
object has acquired a resource and has a pointer member
pointing to it, the default meaning of copy is almost certainly wrong.
vector is the classic example

3. a class needs a destructor almost always also needs a move constructor
and a move assignment. the reason is simply that if an object has acquired
a resource and has a pointer member pointing to it, the default meaning of
copy shallow, memberwise copy is almost certainly wrong and the usual
remedy copy operations that duplicate the complete object state can be
expensive. vector is the classic example


