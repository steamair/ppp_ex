
#include "../std_lib_facilities.h"
#include <map>

int main()
{
    map<string,int> words;      //keep (word,freq) pairs

    for(string s; cin>>s;)
        ++words[s];       //words is subscripted by a string

    for (const auto& p:words)
        cout<<p.first<<":"<<p.second<<"\n";
}

// 21.6.2 map overview

// the stl map implementations tend to be balanced binary search trees.
// more specifically, they are red-black trees

// given that the name of the node member that holds the key value is first
// the basic rule of a binary serach tree is

left->first<first && first<right->first

//that is for every node,
// its left sub_node has a key that is less than the node's key
// the node's key is less than the key of its right sub-node

//interface of map provided by the std lib

template<typename Key, typename Value, typename Cmp=less<key>>
        //requires binary_operation<Cmp,value>()(19.3.3)

class map{
    //....
    using value_type=pair<Key,value>            // a map deals in <key,value> pairs

    using iterator=sometype1;           //similar to a pointer to a tree mode

    using const_iterator=sometype2;

    iterator begin();           //points to first elem
    iterator end();             //points one beyond the last elem

    Value& operator[] (const key& k);       //subscript with k
    iterator find (const key& k);           // is there an entry for k?

    void erase(iterator p);         //remove elem pointed to by p
    pair<iterator,bool> insert(const value_type&);      //insert a (key,value) pair
    //....
};

//iterator to be similar to a Node* 

//when you iterate the elems are pairs-of type pair<key,value>

template<typename T1, typename T2>
struct pair{                //simplied std::pair
    using first_type=T1;
    using second_type=T2;

    T1 first;
    T2 second;

    //...
};

template<typename T1, typename T2>
pair<T1,T2> make_pair(T1 x, T2 y)
{
    return {x,y};
}

//can define the meaning of the order used by a map by supplying a 
// third argument (Cmp in the map declaration)

map<string,double,No_case> m;

// No_case defines case-insensitive compare.
// by default the oder is defined by less<key> meaning less than

//revisit stock index price example

// make the (symbol, price) map

map<string,double> dow_price={      //dow jones ind index (symbol,price);
                                    // for up_to_date quotes see
                                    // www.djindexes.com
    
    {"MMM",81.86},
    {"AA",34.69},
    {"MO",54,45},
    //....
};

// the (symbol,weight) map

map<string,double> dow_weight={
    {"MMM",5.8549},
    {"AA",2.4808},
    {"MO",3.8940},
    //...
};

// the (symbol,name) map

map<string,string> dow_name={
    {"MMM","3M Co."},
    {"AA"]="Alcoa Inc."},
    {"MO"]="Altria Group Inc."},
    //...
};


double alcoa_price=dow_price["AA"];         //read value from a map
double boeing_price=dow_price["BA"];

if(dow_price.find("INTC")!=dow_price.end())     //find an entry in a map
    cout<<"intel is in the dow";

//iterating a map

// write price for each company in the Dow ind

for (const auto& p:dow_price){
    const string& symbol=p.first;           // the ticker symbol
    cout<<symbol<<'t'
        <<p.second<<'t'
        <<dow_names[symbol]<<'\n'
}

//calculate values

double weighted_value(
    const pair<string,double>& a,
    const pair<string,double>& b)
    {
        return a.second*b.second;
    }
//plugin the func into the generalized version of inner_product()

double dji_index=
    inner_product(dow_price.begin(),dow_price.end(),
    dow_weight.begin(),     //weights
    0.0,                    //init value
    plus<double>(),         // add
    weighted_value);        //extract values and weights and multiply


// 21.6.4 unordered map

//hash table

//for some types, integers and char strings,
// idea is that given a key, we can compute an index into a vector
// the index is called hash value.
// and the container use this technique is called a hash table

// the stl unordered_map is implemented usig a hash table
// just as the stl map is implemented using a balanced binary tree
// and an stl vector is implemented using an array

// the rule of thumb is

// use vector unless you have reason not to
// use map if you need to look up based on a a value
// (if your key type has a reasonable and dfficient less-than operation)
// use unordered_map if you need to do a lot of look up in a large map
// and you dont need an ordered traversal(and if you can find a good
// hash func for your key type)

unordered_map<string,double> dow_price;

for (const auto& p:dow_price){
    const string& symbol=p.first;           // the "ticker" symbol
    cout<<symbol<<'\t'
        <<p.second<<'\t'
        <<dow_name[symbol]<<'\n'
}

// 21.6.5

// can think of set as a map where we are not intersted in the values,
// a map without values

struct fruit{
    string name;
    int count;
    double unit_price;
    Date last_sale_date;
    //...
};

struct fruit_order{
    bool operator()(const fruit& a, const fruit& b) const
    {
        return a.name<b.name
    }
}

set<fruit, fruit_order> inventory;

// we use function object. see how function object can significantly 
// increase the range of problems for which an stl component is useful

// set does not support suscript [], and push_back() (use insert())

inventory.insert(fruit{"quince",5});
inventory.insert(fruit{"apple",200,0.37});

// advantage of set over map is that you can use the value obtained from
// an iterator directly. Since there is no (key,value) pair as for map
// the dereference operator gives a value of the elem type

for (auto p=inventory.begin(); p!=inventory.end();++p)
    cout<<*p<<'\n';

//assuming you have defined << for fruit, 
for(const auto& x:inventory)
    cout<<x<<'\n'

// 21.7.1 copy

template<typename ln,typename out>
        //requires input_iterator<ln>() && output_iterator<out>()
out copy (ln first, ln last, out res)
{
    while(first !=last){
        *res=*first;        //copy element
        ++res;
        ++first;
    }
}

//given a pair of iterators copy() copies a seq into another seq specified
// by an iterator to its first elem

void f(vector<double>& vd, list<int>& li)
        //copy the elems of a list of ints into a vector of doubles
{
    if(vd.size()<li.size()) error("target container too small")
    copy(li.begin(),li.end(),vd.begin());
    //....
}

//stream copy

ostream_iterator<string>oo{cout};      //assigning to *oo is to write to cout

*oo="hello,";           //meaning cout<<"hello";
++oo;           //get ready for next output operation

*oo="world\n";      //meaning cout<<"world\n";

//the standard library provides an ostream_iterator type that works like that
// ostream_iterator<T> is an iterator that you can use to write value of type T

//the standard libarary provides the type istream_iterator<T> for raeding
// values of type T

istream_iterator<string> ii{cin};           //reading *ii is to read a string from cin
 string s1=*ii;         //meaning cin>>s1;

 ++ii;                  //get ready for next operation
 string s2=*ii;         //meaning cin>>s2;


 // using ostream_iterator and istream_iterator can use copy() for
 // four I/O

 int main()
 {
    string from, to;
    cin>>from>>to;          //get source and target file names

    istream is{from};           //open input stream
    ostream os{to};             //open output stream

    istream_iterator<string> ii{is};        //make input iterator for stream
    istream_iterator<string> eos;           //input sentinel
    ostream_iterator<string> oo{os,"\n"};   //make output iterator for stream
    
    vector<string> b {ii,eos};              //b is a vector initialized from input
    sort(b.begin(),b.end());                //sort the buffer
    copy(b.begin(),b.end(),to);             //copy buffer to output
 }

 // the iterator eos is the stream iterator's representation of "end of input"
 // when an istream reaches end of input(often referred to as eof),
 // its istream_iterator will equal the default istream_iterator(here caled eos)

 // note that we initialized the vector by a pair of iterators.
 // as the initializers for a container, a pair of iterators(a,b) means
 // read the seq [a:b) into the container. Naturally, the pair of iterators
 // that we used was (ii,eos). that saves us from explicitly using >>
 // and push_back(). 

 //use unique_copy() avoid duplicates of texts


 //using a set to keep order

 int main()
 {
    string from,to;
    cin>>from>>to;          //get source and target file names

    ifsgream is{from};          //make input stream
    ofstream os{to};            //make output stream

    set<string> b {istream_iterator<string>{is}, istream_iterator<string{}};
    copy(b.begin(),b.end(),ostream_iterator<string>{os,""});   //copy buffer to output

 }


 // 21.7.4 copy_if

 // copy_if only copies elems for which a predicate is true

 template<typename ln, typename out, typename pred>
        //requires input_iterator<ln>() && output_operator<out>()
        // && predicate<pred,value_type<ln>>()
out copy_if(ln first, ln last, out res, pred p)
        //copy elems that fulfill the predicate
{
    while (first!=last){
        if(p(*first) *res++=*first);
        ++first;
    }
    return res;
}

//using larger_than func object from 21.4, we can find all elems of 
// a seq larger than 6 like this

void f(const vector<int>& v)
            //copy all elems with a value larger than 6
{
    vector<int> v2(v.size());
    copy_if(v.begin(),v.end(),v2.begin(),larger_than(6));
    //....
}


//apply own criteria for sort()

template<typename Ran>
    //require random_access_iterator<Ran>()
void sort(Ran first, Ran last);

template<typename Ran, typename Cmp>
        //requires random_access_iterator<Ran>()
        // && less_than_comparable<Cmp, Value_type<Ran>>()
void sort(Ran first, Ran last, Cmp cmp);

struct No_case{     //is lowercase(x)<lowercase(y)?
    bool operator()(const string& x, const string& y) const
    {
        for(int i=0; i<x.length();++i)
        {
            if(i==y.length()) return false; //y<x
            char xx=tolower(x[i]);
            char yy=tolower(y[i]);
            if(xx<yy) return true;      //x<y
            if(yy<xx) return false;     //y<x
        }
        if(x.length()==y.length()) return false;        //x==y
        return true;            //x<y (fewer chars in x)
    }

}

void sort_and_print(vector<string>& vc)
{
    sort(vc.begin(),vc.end(),No_case());

    for(const auto& s:vc)
        cout<<s<<"\n";
}

//a binary search works like this
// assume that we are looking for the value x; look at the middle elem

// if the element's value equalx, we found it
// if the elem's value is less than x, any elem with value x must be to the right
// (doing binary search on that half)
// if the value of x is less than the elem's value, search the left
// if we have reached the last elem, without finding x, there is no elem
// with that value

//the std lib provides binary_search(), and equal_range()

// the binary_search algo comes in two variants

template<typename Ran, typename T>
bool binary_search(Ran first, Ran last, const T& val);

template<typename ran,typename T, typename Cmp>
bool binary_search(Ran first, Ran last, const T& val, Cmp cmp);


//these algos require input seq is sorted.

void f(vector<string>& vs)      //vs is sorted
{
    if(binary_search(vs.begin(),vs.end(),"starfruit")){
        // we have a starfruit
    }
    //....
}

//21.9 container algo

// an input seq is defined as a pair of iterators[b:e) where b
// points to the first elem of the seq and e to the one-past-the-end elem
// of the seq.

// an output seq is specified as simply an iterator to its first elem

void test(vector<int>& v)
{
    sort(v.begin(),v.end());        //sort v's elem from v.begin() to v.end()
}

void test(vector<int>& v)
{
    sort(v.begin(),v.end()+v.size()/2); //sort first half of v's elems
    sort(v.begin()+v.size()/2,v.end());     //sort second half of v's elem
}

void test(vector<int>& v)
{
    sort(v);    //sort the whole seq
}

// that variant of sort() is not provided by std lib,
template<typename C> //requires container<C>()

void sort(C& c)
{
    std::sort(c.begin(),c.end());
}

//tend to leave return types as iterators

template<typename C, typename V> //requires Container<C>()

iterator<C> find(C& c, V v)
{
    return std::find(c.begin(),c.end(),v)
}

//naturally, iterator<C> is C's iterator type

// end of ch 21
//--------------------
