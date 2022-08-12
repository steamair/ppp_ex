

#include "../std_lib_facilities.h"

template<typename Elem>
class list{
    //representation and implementation details
public:
    class iterator:     //member type:iterator

    iterator begin();       //iterator to first elem
    iterator end();         // iterator to one beyond last elem

    iterator insert(iterator p, const Elem& v);     //inser v into list after p
    iterator erase(iterator p);         //remove p from the list

    void push_back(const Elem& v);      //insert v at end
    void push_from(const Elem& v);      //insert v at front

    void pop_front();       //remove the first elem
    void pop_back();        // remove the last elem

    Elem& front();          // the first elem
    Elem& back();           // the last elem

    //..
};



//20.4.2 iteration

// the list iterator must provide *,++,--,and !=. Since the standard lib
// list is a doubly-linked list, it also provides -- for iterating 'backward'
// toward the front of the list;

template<typename Elem>     //requires Element<Elem>() (19.3.3)
class list<Elem>:: iterator{
private:
    Link<Elem>* curr;       //current link
public:
    iterator(Link(Elem)* p):curr{p}{}
    iterator& operator++(){curr=curr->succ; return *this;}  //forward
    iterator& operator--(){curr=curr->prev; return *this;}  //backward
    Elem* operator*() {return curr->val;}       //get value(dereference)

    bool operator==(const iterator& b) const {return curr==b.curr;}
    bool operator!=(const iterator& b) const {return curr!=b.curr;}
};

// this list iterator is just a pointer to a link with the required operations
// the list iterator provides suitable ++,--,*,==,!= for a link pointer

// high()

template<typename Iter> //requires input_Iter<Iter>() (19.3.3)

Iterator high(Iter first, Iter last)
    //return an iterator to the elem in [first, last) that has the highest value

{
    iterator high=first;
    for( iterator p=first; p!=last; ++p)
        if(*high<*p) high=p;
        return high;
}


// use it on list

void f()
{
    list<int> lst; for(int x; cin>> x; lst.push_front(x));

    list<int>::Iter p=high(lst.begin(),lst.end());
    cout<<"the highest value was "<<*p<<"\n";
}

//the "value" of the iterator argument is list<int>::Iter.

// test end point== first point

list<int>::Iter p=high(lst.begin(),lst.end());
if(p==lst.end())            //did we reach the end?
    cout<<"the list is empty";
else
    cout<<"the highest value is "<<*p<<"\n";

 //20.5 generalizing vector

 //in the std lib vector has an iterator member type and begin() and end()

template<typename T>       //requires Element<T>() (19.3.3)
class vector{

public:
    using size_type=unsigned long;
    using value_type=T;
    using iterator=T*;
    using const_iterator=const T*;
    //....

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    size_type size();
    //....
 };

// a using declaration creates an alias for a type. for our vector
// iterator is a synonym, another name, for the type we chose to use as our iterator:T*

vector<int>::iterator p=find(v.begin(),v.end(),32)
for (vector<int>::size_type i=0;i<v.size();++i) cout<<v[i]<<'\n';


template<typename T>            //requires Element<T>() (19.3.3)

class list{
    public:
    class Link;
    using size_type=unsigned long;
    using value_type=T;
    class iterator;     // see 20.4.2
    class const_iterator;       // like iterator but not allowing writes to elements

    //....

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    size_type size();

    //....
};


// as an alternative to saying C::iterator for some container C, prefer
// iterator<C>. can be achieved trhough a simple template alias;

template<typename C>
using iterator=typename C::iterator;        //iterator<C> means typename
                                            //C::iterator

//similarily, we can use Value_type<C>, instead of C:value_type

template<typename C>
using Value_type=typename C::value_type;

// using declaration is a c++11 notation for and a generalization of what 
// was known in c and c++ as a typedef.


//20.5.1 container traversal

//using size(), can traverse vectors from begining to end
void print1(const vector<double>& v)
{
    for (int i =0; i<v.size();++i)
        cout<<v[i]<<'\n';
}

//however it does not work list, because list dost not provide subscript

void print2(const vector<double>& v, const list<double>& lst)
{
    for (double x:v)                //reads as for double x in vector v
        cout<<x<<'\n'
    for (double x:lst)
        cout<<x<<'\n'
}

//20.5.2 auto

// naming the iterators can be nuisance in writing out loops over a 
// generic structure

tempalte<typename T>        //requires element<T>()
void user(vector<T>&v, list<T>& list)
{
    for (vector<T>::iterator p=v.begin(); p!=v.end();++p)
        cout<<*p<<'\n';
    list<T>::iterator q=find(lst.begin(),lst.end(),T{42});
}

// the complier already knows the iterator type for the list and 
// size_type for the vector. we can declare a variable auto meaning use the type
// of the iterator as the type of the variable

template<typename T>        //requires Element<T>()

void user(vector<T>& v, list<T>& lst)
{
    for (auto p=v.begin();p!=v.end();++p) cout<<*p<<'\n';

    auto q=find(lst.begin(),lst.end(),T{42});
}

