

template<typename ln, typename T>
    //requires input_iterator<ln>()
    // && equality_comparable<value_type<T>>() (19.3.3)

ln find(ln fisrt, ln last, const T& val)
        //find the first elem in [first, last) that equals val
{
    while(first!=last && *first !=val) ++first;
    return first;
}

//returning an iterator to the one-beyond-the-last elem of a seq is the most
//common stl way of reporting "not found"

void f(vector<int>& v, int x)
{
    auto p=find(v.begin(),v.end(),x);
    if(p!=v.end()){
        //we found x in v
    }
    else {
        // no x in v
    }
    //...
}

// the type of the value returned is the iterator passed as an argument
// to avoid naming the type returned, we use auto. an object defined with
// the "type" auto gets the type of its initializer

auto ch='c';        // ch is a char
auto d=2.1;         // d is a double



// "predestrain way"

template<typename ln, typename T>
    //requires input_iterator<ln>()
    // && equality_comparable<value_type<T>>()(19.3.3)

ln find(ln first, ln last, const T& val)
    //find the first elem in [first, last) that equals val
{
    for(ln p=first;p!=last; ++p)
        if(*p==val) return p;
    return last;
}

void f(vector<int>& v, int x)       //works for vector of int
{
    vector<int>::iterator p=find(v.begin(),v.end(),x);
    if(p!=end()){/*we found x*/}
    //...
}



// find() is flexible, as long as we obey the rules for iterators,
// we can use find() to find elems for any seq we can think of
// and for any container

//use find to look for a char in a document as defined in 20.6

void f(Document& v, char x)     //works for document of char

{
    Text_iterator p=find(v.begin(),v.end(),x)
    if(p!=v.end())
    {/* we found x*/}
    //...
    }



//find_if()

// a standard algo that searches based on a user suppiled criterion


tempalte<typename ln, typename Pred>
// requires input_iterator<ln>() && predicate<pred,value_type>()

ln find_if(ln first, ln last, Pred pred)
{
    while (first!=last && !pred(*first) ++first);
    return first;
}

bool odd(int x){return x%2;}        
void f(vector<int>& v)
{
    auto p=find_if(v.begin(),v.end(),odd);
    if(p!=end())//{ we found a odo number}
    //..
}

// find the first elem of a list with a value larger than 42

bool larger_than_42(double x){return x>42;}
void f(list<double>& v)
{
    auto p=find_if(v.begin(),v.end(),larger_than_42);
    if (p!=end())//{found the object}
    //...
}

// make a global variable so that the function do not need to be rewrite
// after placing another value

double v_val;
bool larger_than_val(double x){return x>v_val;}

void f(list<double>& v, int x)
{
    v_val=31;
    auto p=find_if(v.begin(),v.end(),larger_than_val);
    if(p!=end())

    v_val=x;
    auto q=find_if(v.begin(),v.end(),larger_than_val);
    if(p!=end())
    //...
}

void f(list<string>& v, string x)       //for list
{
    list<string>::iterator p=find(v.begin(),v.end(),x);
    if(p!=v.end()){/* we found x*/}
    //....
}


//21.4 functions objects

// we want to pass a predicate to find_if(), we want that predicate to compare
// elems to a value we specify as some kind of arugment, something like:

void f(list<double>& v, int x)
{
    auto p=find_if(v.begin(),v.end(),larger_than(31));
    if(p!=end())//{found 31}

    auto q=find_if(v.begin(),v.end(),larger_than(x));
        if(p!=end())//{found x}

}

//larger_than must be something that
// we can call as a predicate, e.g., pred(*first)
//can store a value, such as 31 or x, for use when called

// we need a "function object", an object that can behave like a function
// we need an object because objects can store data, such as the value 
// with which to compare.

class larger_than{
    int v;
public:
    larger_than(int vv):v(vv){ }            //store the argument
    bool operator()(int x) const{return x>v;}   //compare

    
}

//() operator, also called the function call operator and the application
// operator, just like v[o] is given meaning by vector::operator[]

class F{        //abstract example of a function object
    S s;        //state

public:
    F(const S& ss):s(ss) //{establish intial state}
    T operator()(const S& ss) const
    {
        //do something with ss to s
        // return a value of type T(T is often void, bool or S)
    }

    const S& state() const{return s;}       //reveal state
    void reset(const S& ss){s=ss;}          //reset state

}


// use of function objects is the main method of parametrerization 
// in the STL.

//sorting a record by several criteria

struct Record{
    string name;            //standard string for ease of use
    char addr[24];          // old style to match database layout
    //.....
};


vector<Record> vr;

//want to sort vr by name, or address

//....
sort(vr.begin(),vr.end(),Cmp_by_name());     //sort by name
//....
sort(vr.begin(),vr.end(),Cmp_by_addr());        //sort by addr
//....

//Cmp_by_name is a function object that compares two records by comparing their
// name members.
// Cmp_by_addr is a function object that compares two records by comparing
// their addr members

struct Cmp_by_name{
    bool operator()(const Record& a, const Record& b) const
        {return  a.name<b.name;}
};

struct Cmp_by_addr{
    bool operator()(const Record& a, const Record& b) const
        {return strncmp(a.addr,b.addr,24)<0;}  //??
};

// strcncmp compares fixed length strings and returns a negative if
// second string comes lexicographically after the first.

//21.4.3 lambda expressions

//defining a function object( or a function) in one place in a program and
// then using it in another can be a bit tedious

//lambda expression is as a short hand notation for defining a func object
// (a class with an operator ()) and then immediately creating an object
// of it

//...,.
sort(vr.begin(),vr.end(),     //sort by name
        [](const Record& a, const Record& b)
            [return a.name<b.name;]
);

//....

sort(vr.begin(),vr.end(),       //sort by addr
    [](const Record& a, const Record& b)
        {return strcncmp(a.addr,b.addr,24)<0;}
);
//...


void f(list<double>& v, int x)
{
    auto p=find_if(v.begin(),v.end(),larger_than(31));
    if(p!=end())//{found 31}

    auto q=find_if(v.begin(),v.end(),larger_than(x));
        if(p!=end())//{found x}

}

// can be rewrite us lambada expression as

void f(list<double>& v, int x)
{
    auto p=find_if(v.begin(),v.end(),[](double a){return a>31;});
    if(p!=v.end())//{found a value>31}
    auto q=find_if(v.begin(),v.end(),[&](double a){return a>x;});
    if(q!=v.end())
    //...
}


//numerical algo

// accumulate 21.5.1

template<typename ln, typename T>
        //requires input_iterator<ln>() && Number<T>()
T accumulate(ln first, ln last, T init)
{
    while (first!=last){
        init=init+*first;
        ++first;
    }
    return init;
}

// init, the varaible in which the sum is computed is called the accumulator

int a[]={1,2,3,4,5};
cout<<accumulate(a,a+sizeof(a)/sizeof(int),0)

void f(vector<double>& vd,int* p,int n){
    double sum=accumulate(vd.begin(),vd.end(),0.0);
    int sum2=accumulate(p,p+n,0);
}

void g(int* p, int n){
    int s1=accumulate(p,p+n,0);     //sum into int
    long sl=accumulate(p,p+n,long{0})   //sum into long
    double s2=accumulate(p,p+n,0.0);    //sum into double
}


void f(vector<double>& vd, int* p, int n)
{
    double s1=0;
    s1=accumulate(vd.begin(),vd.end(),s1);
    int s2=accumulate(vd.begin(),vd.end(),s2);  //error
    float s3=0;
    accumulate(vd.begin(),vd.end(),s3);     //error
}

//generalizing accumulate()

template<typename ln, typename T, typename Binop>
    //requires Input_operator<ln>() && number<T>()
    // && binary_operator<Binop,value_type<ln>,T>()
T accumulate (ln first, ln last, T init, Binop op)
{
    while(first!=last){
        init = op(init,*first);
        ++first;
    }
    return init;
}

//any binary operation that accpets two arguments of the accumualtor's
// type can be used

vector<double> a={1.1,2.2,3.3,4.4};
cout<<accumulate(a.begin(),a.end(),1.0,multiplies<double>());

//result is 35.1384, 1.0*1.1*2.2*3.3*4.4, (1.0 is the init value)
// multiplies<double> is a std lib func

struct Record{
    double unit_price
    int units;      // numb of units sold
    //...
}

double price(double v, const Record& r)
{
    return v+r.unit_price*r.units;      //calculate price and accumulate
}

void f(const vector<Record>& vr)
{
    double total=accumulate(vr.begin(),vr.end(),0.0,price);
}

// prefer funct objects if
// they need to store a value between calls or
// they are so short that inlining can make a difference


//21.5.3 inner product

template<typename ln, typename ln2, typename T>
    //requires input_iterator<ln> && input_iterator<ln2>
    // && number<T>()(19.3.3)

T inner_product(ln first, ln last, ln2 first2, T init)
        //this is the way we multiply two vectors(yielding a scalar)
{
    while(first!=last)
    {
        init=init+(*first)*(*first2);       //multiply pairs of elems
        ++first;
        ++first2;
    }
}

//calc the dow jones ind index;
vector<double> dow_price={              //share price of each company
    81.86,34.69,54.45
    //....
};


list<double> dow_weight={           //weight index for each company
    5.8549,2.4808,3.8940,
    //....
}

double dji_index=inner_product(         //multiply(weight,value) pairs and add
    dow_price.begin(),dor_price.end(),
    dow_weight.begin(),
    0.0
);

//two seq need not be of the same type nor do they need to have same elem
// types

//21.5.4 generalizing inner_product()

// to generalize inner_product, we need an extra two arguments
// one to combine the accumulator with the new value
// one for combining the elems value pairs

template<typename ln, typename ln2, typename T, typename BinOp,
        typename BinOp2>
                //requires input_iterator<ln> && input_iterator<ln2>
                //&&number<T>
                // && Binary_operation<BinOp, T, Value_type<ln>>()
                // && Binary_operation<BinOp2, T, Value_type<ln2>>()

T inner_product(ln first, ln last, ln2 first2, T init, BinOp op, BinOp2 op2)
{
    while(first!=last)
    {
        init=op(init,op2(*first,*first2));
        ++first;
        ++first2;
    }
    return init;
}


// finally map.

// 21.6 associative containers

// a map is an ordered seq of (key,value) pairs in which you can look
// up a value based on a key;

//map and unordered_map known under names such as 
// associative arrays, hash tables, red_black trees

int main()
{
    map<string,int> words;      //keep (word,freq) pairs

    for(string s; cin>>s;)
        ++words[s]          //words is subscripted by a string

    for (const auto& p:words)
        cout<<p.first<<":"<<p.second<<"\n";
}

//the elems of a map<string,int> are of type pair<string,int>
// the first member of a pair is called first and second member second

for( const auto& p:words)
    cout<<p.first<<":"<<p.second<<"\n";