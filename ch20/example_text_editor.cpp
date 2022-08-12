

#include "../std_lib_facilities.h"

// 20.6
// to conveniently moving around (insert, delete) chars, we represent
// a document as a list of "lines",list<line>, where a line is a vector<char>
// so that memory space needed to move around text are significantly reduced
// can use iterators and pointers.


// represent a document as an object of class Document.
// stripped of all refinements, our document type looks like this

using Line=vector<char>;        //a line is a vector of chars

struct Document{
    list<Line> line;        //a documnet is a list of lines
    Document(){line.push_back(Line{});}
};


// reading and splitting into lines can be done like this



istream& operator>>(istream& is, Document& d)
{
    for (char ch; is.get(ch);)
    {
        d.line.back().push_back(ch);        //add the char
        if(ch=='\n')
            d.line.push_back(line{});       //ad another line

    }
    if(d.line.back().size()) d.line.push_back(Line{});      // add final empty line
    return is;
}

class Text_iterator{        // keep track of line and char position within a line
    list<Line>::iterator ln;
    Line::iterator pos;
public:
    //start the iterator at line ll's char position pp
    Text_iterator(list<Line>::iterator ll,Line::iterator pp)
        :ln{ll},pos{pp}{}
    char& operator*(){return *pos;}
    Text_iterator& operator++();
    bool operator==(const Text_iterator& other) const 
        {return ln==other.ln && pos==other.pos;}
    bool operator!=(const Text_iterator& other) const
        {return !(*this==other);}
};


Text_iterator& Text_iterator::operator++()
{
    ++pos;      //proceed to next char
    if(pos==(*ln).end()){
        ++ln;       //proceed to next line
        pos=(*ln).begin()       //bad if ln==line.end(); so make sure it isnt

    }
    return *this;
}


// to make text_iterator useful, we need to equip lass document with
// conventional begin() and end() functions;

struct Document{
    list<Line> line;
    
    Text_iterator begin()       //first char of first line
        {return Text_iterator(line.begin(),(*line.begin()).begin());} 
                            //line.begin(), postion of line
                            //(*line.begin()).begin() position of char of a line
                            //equivalent to line.begin()->begin()
    Text_iterator end()
    {
        auto last=line.end();
        --last;     //we know that the document is not empy
        return Text_iterator(last,(*last).end());
    }  
};

// now iterate over the chars of a document like this:

void print(Document& d)
{
    for(auto p: d) cout<<p;
}

print(my_doc);

//code to delete line n;

void erase_line(Document& d, int n)
{
    if(n<0||d.line.size()-1<=n) return;
    auto p=d.line.begin();
    advance(p,n);
    d.line.erase(p);
}

// a call advance(p,n) moves an iterator p n elems forward
// advance() is a std lib fct
// but we can implement it ourselves like this

template<typename Iter>     //requires Forward_iterator<Iter>

void advance(Iter& p, int n)
{
    while(0<n) {++p;--n;}
}


// for a vector called v, p=v.begin(); advance(p,n); *p=x
// is roughly equivalent to v[n]=x

// to handle search like string\nstring, a line ending with a string followed
// by a line starting with a string
// use the below algorithm

// find hte first char of our search string in the docu
// see if that char and the following chars match our search string
// if so, we are finished, if not, we look for the next occurrence of that
// first char

Text_iterator find_txt(Text_iterator first, Text_iterator last, const string& s)
{
    if(s.size()==0) return last;        //cant find an empty string
    char first_char=s[0];
    while (true){
        auto p=find(first,last,first_char);
        if(p==last || match(p,last,s)) return p;
        first=++p;      //look at the next char
    }
}

auto p=find_txt(my_doct.begin(),my_doc.end(),"secret\nhomestead");
if(p==my_doc.end())
    cout<<"not found";
else{
    //do something
}

//four ways to store a seq of chars

// char[]       array of chars
// vector<char>
// string
// list<char>


//Elem[]  doesnt know its own size. doesnt have begin(), end() or any of 
// the other useful container member functions. cant be systematically checked

//vector<Elem> can do just about everything, including insert(), erase().
// a vector is expandable

//string: provides all the common ans useful operations plus specific text
// manipulation operations, such as concatenation(+ and +=). a string
// is expandable

//list<elem> provides all the common and usual operations, except subscripting
// we can insert and erase(), without moving other elemts.


// adapting vector to the stl

template<typename T, typename A=allocator<T>>
    //requires Element<T>() && Allocator<A>() (19.3.3)
class vector{
    int sz;     //the size
    T* elem; //  a pointer to the elem
    int space;      // number of elem plus number of free space "slots"
    A alloc;        //use allocate to handle memory for elem
public:
    //....all the other stuff from ch19 and 20.5
    using iterator=T*;      //T* is the simplest possible iterator

    iterator insert(iterator p, const T& val);
    iterator erase(iterator p);
    };

// implement vector<T,A>:: erase() by copying all elems after the elem we
// erase( remove, delete). using the def of vec from 19.3.7, with the 
// additions above, we get

template<typename T, typename A>        //requires Element<T>()&&
                                        //Allocator<A>() 19.3.3
vector<T,A>::iterator vector<T,A>::erase(iterator p)
{
    if (p==end()) return p;
    for (auto pos=p+1; pos!=end(); ++pos)
        *(pos-1)=*pos;          //copy elem 'one position to the left'
    alloc.destory(&*(end()-1))  //destory surplus copy of last elem
    --sz;
    return p;

}

templeate<typename T, typename A>            //requires Element<T>()&&
                                        //Allocator<A>() 19.3.3
vector<T,A>::iterator vector<T,A>::insert(iterator p, const T& val)
{
    int index =p-begin();
    if(size()==capacity())
        reserve(size()==0?8:2*size());      //make sure we have space
    // first copy last elem into uninitialized space

    alloc.construct(elem+sz,*back());
    ++sz;
    iterator pp=begin()+index;          //the place to put val
    for(auto pos=end()-1; pos!=pp; --pos)
        *pos=*(pos-1);          //copy elem on position to the right
    *(begin()+index)=val;           //"insert " val
    return pp;
}

// A is the cllocator argument


// built-in arrays to the stl

// weakness of the built in arrays. they implicitly conver to pointers at 
// the slightest provocation, they cant be copied using assignment,
// they dont know their own size, etc

// strength: they model physical memory almost perfectly

// to get the best of both worlds, we can build an array container that provides
// the benefits of arrays without the weakness. a version of array
// was introduced into the standard as part of technical report. 
// since a feature from a tr is not required to be part of every implementation
// array may not be part of implementation you use. 

template<typename T, int N>         //requires element<T>()

struct array{                       // not quite the standard array
    using value_type=T;
    using iterator = T*;
    using const_iterator=const T*;
    using size_type=unsigned int;       //the type of a subscript

    T elems[N];
    // no explicit consturct/copy/destory needed

    iterator begin(){return elems;}
    const_iterator begin() const {return elems;}
    iterator end() {return elems+N;}
    const_iterator end() {return elems+N;}

    size_type size() const;

    T& operator[](int n) {return elems[N];}
    const T& operator[] (int n) const {return elems[N];}

    const T& at(int n) const;       //range-checked access
    T& at(int n);           //range-checked access

    T* data(){return elems;}            
    const T* data() const {return elems;}

};

//nnote that because array<T,N> knows that its size is N, we can do provide
// assignment ==,!=,etc just as for vector

// array with the STL version of high() from 20.4.2

void f()
{
    array<double,6> a={0.0,1.1,2.2,3.3,4.4,5.5};
    array<double,6>::iterator p=high(a.begin(),a.end());
    cout<<"the highest value was"<<*p<<'\n';
}

// we didnt think of array when we wrote high(), being able to use high()
// for an array is a simple consequence of following standard conventions 
// for both


// an stl container
// is a sequence of elements[begin():end()).
// provides copy operations that copy elements. copying can be done with
// assignment or a copy constructor

// names its element type value_type

// has iterator types called iterator and const_iterator. iterators provide *
// ++(both prefix and postfix),== and != with the appropriate semantics
// the iterators for list also provide -- for moving backward in the seq
// thats called a bidireactional iterator. the iterators for vec also provide
// -- [] + - and are called random-access iterators

// provides insert() erase() front() and back() push_back() pop_back() size()
// vector and map also provide subscripting(operator [])

// provides comparison operators(==,!=,<,<=,>,>=) that compare the elems,
// containers use lexicographical odering for <,<=,>,>=; they compare
// the elems in order starting with the first

// 20.10.1 iterator categories

// input iterator 
// we can iterate forward using ++ and read elem values using *.
// this is the kind of of iterator that istream offers. see 21.7.2 
// if (*p).m if valid, p->m can be used as a shorthand.

// output iterator
// we can iterator forward using ++ and write element values using *
// this is the kind of iterator that ostream offers. see 21.7.2

// forward iterator
// we can iterate  forward repeatedly using ++ and read and write
// (unless the elements are const,) element value using *. if(*p).m
// is valid, p->, can be used as a shorthand.

//bidirectional iterator
// we can iterate forward(using ++) and backward (using --) and read and write
// (unless the elements are const) elem values using *. this is the kind of iterator
// that list, map, set offer. if (*p).m is valid, p->m can be used as a shorthand

// random-access iterator
// we can iterator forward(using ++) and backward (using --) and read and
// write (unless elem are const) element values using * and []. we can
// subscript and add an integer to a random-access iterator using + and
// subtract an integer using -.we can find the ditance between two random-access
// iterators to the same sequence by subtracting one from the other. this is the kind
// of iterator that vector offers. if (*p).m is valid, p->m can be used 

