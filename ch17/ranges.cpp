

// 17.4.3 ranges

/* 
double* pd= new double[3];
pd[2]=2.2;
pd[4]=4.4;
pd[-3]=-3.3;

// pointer does not know how many elements it points to
// by definition of pd, pd only have length of 4, pd[4] does not exist
// pd[-3] is the location three doubles before what pd points to

// initialization

double* p0;             //uninitialized;    likely trouble
double* p1= new double;     //get allocate an uninitialized double
double* p2=new double{5.5};     // get a double initialized to 5.5
double* p3=new double[5];       // get allocate 5 unitialized doubles

// memory allocated by new is not intiailized for built in types
// see the p2 initialization, and the use of {}

// specify an initializer list for an array of objects allocated by new

double* p4=new double[5]{0,1,2,3,4};
double* p5=new double[]{0,1,2,3,4};

// p4 points to objects of type double containing the values of 0.0,1.0,
// 2.0,3.0,4.0, so does p5. the number of elements can be left out when
// a set of elements is provided.

// when we define our own types, we have better control of initialization
// if a type X has a default constructor, we get
 
 X* px1=new X;          // one default-initialized X
 X* px2=new X[17];      // 17 default-intialized Xs

// if a type Y is a constructor, but not a default constructor, we have to
// explicitly initialize

Y* py1=new Y;               //error; no default constructor
Y* py2=new Y{13};           // initialized to Y{13}
Y* py3=new Y[17];           // no default constructor
Y* py4=new Y[17]{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

// 17.4.5 Null pointer

// nullptr

double* p0=nullptr;     //the null pointer

// when assigned to a pointer, the value zero is called the null pointer
// test a pointer is valid and whether it is nullptr

if(p0!=nullptr)             //consider p0 valid

if(p0)          //consider p0 valid; equivalent to p0!=nullptr

// 17.4.6 free-store deallocation

// apply delete to a pointer returned by new to free memory

double* calc(int res_size, int max)
    // the caller is responsible for the memory allocated for res
{
    double* p=new double[max];
    double* res=newdouble[res_size];
    //use p to calculate results to be put in res
    delete[] p;         //we dont need that momory anymore free it
    return res;

}

double* r=calc(100,1000);
//use r
delete[] r;         // we dont need that memory anymore, delete it

// delete p frees the memory for an individual object allocated by new
// delete[] p frees the memory for an array of objects allocated by new


//do not delete a object twice 

//destructors

//a vector of doubles

class vector{       
    int sz;                     // the size
    double* elem;               //a pointer to the elements

public:
    vector(int s)              //constructor
        :sz{s},                //initialize sz
        elem{new double[s]}    // initialize elem
        {
            for (int i=0;i<s;++i)   elem[i]=0;  //initialize elements
        }
    int size() const{return sz};            //the current size
    //.....
}


// sz the number of elements, initialized in the constructor
// user of vector can get the number of elements by calling size()

// this vector class leaks memory, we add desturctor 


class vector{       
    int sz;                     // the size
    double* elem;               //a pointer to the elements

public:
    vector(int s)              //constructor
        :sz{s},                //initialize sz
        elem{new double[s]}    // initialize elem
        {
            for (int i=0;i<s;++i)   elem[i]=0;  //initialize elements
        }
    ~vector()                   // destructor
        {delete[] elem;}        // free memory
}


//given that, we can write,

void f3(int n)
{
    double* p=new double[n];            //allocate n doubles
    vector v(n);                        // the vector allocates n doubles
    //use p and v
    delete[]    p;              //delocate p's doubles
}//vector automatically cleans up after v

//17.5.1 generated destructors

// if a member of a class has a desctrutor, then that destructor will be
// called when the object containing the member is destroyed

struct Customer{
    string name;
    vector<string> addresses;
    //..
};

void some_fct()
{
    customer fred;
    // initialized fred
    // use fred
}

// when we exit some_fct(), so that fred goes out of scope, fred is 
// destroyed
// that is destructors for name and addresses are called.


// whatever resouces a class object needs to function, it acquires a
// consturctor
// during the object's lifetime it may release resources and acquire
// new ones
// at the end of the object's lifetime, the destructor realses all resources
// still owned by the object



// 17.6 access to elements


//use set() and get() to write and read from element of a vector
// a very simplified vector of doubles
class vector{
    int sz;                     // the size
    double* elem;               //a pointer to the elments

public:
    vector(int s): sz{s}, elem{new double[s]}{//...}  //constructor
    ~vector(){delete[] elem;}                       //destructor

    int size() const{return sz;}                      // the current size
    double get(int n) const (return elem[n];)         // access: read
    void set(int n, double v) {elem[n]=v;}          //access:write
};

vector v(5);
for (int i=0; i<v.size();++i){
    v.set(i,1.1*i);
    cout<<"v["<<i<<"]=="<<v.get(i)<<'\n';
}

//17.7 pointer to class objects

// we can point to just about anything we can place in memory

vector* f(int s)
{
    vector* p=new vectors(s);           //allocate a vector on free store
    // fill *p
    return p;
}

void ff()
{
    vector* q=f(4);
    //use *q
    delete q;
}

// all classes support the operator .(dot) for accessing members

vector v(4);
int x=v.size();
double d=v.get(3);

// all calsses support the operator ->(arrow) for accessing members,
// given a pointer to an object

vector* p=new vector(4);
int x=p->size();
double d=p->get(3);

// dot and arrow often called member access operators,
// can be used for both data members and function members
*/


//--------------------------

//17.8

// void* means "pointer to some memory that the compiler doesnt know the
// type of " we use void* when we want to transmit an address between pieces
// of code that really dont know each other's types.

// use void to mean "no value returned"

// a pointer to any object can be assigned to a void*

void* pv1=new int;          // int* converts to void*
void* pv2=new double[10];    // double* converts to void*


// since the compiler doesn't know what a void* points to, we must tell it:

void f(void* pv){
    void* pv2=pv;           //copying is ok(copying is what void* are for)
    double* pd=pv;          // error, cannot convert void* to double*
    *pv=7;                  // error cannot dereference a void*
                            // (we dont know what type of object it points to)
    pv[2]=9;                // error cannot subscript a void*
    int* pi=static_cast<int*>(pv);          //ok, explicit conversion
    //..
}


// a static_cast can be used to explicitly convert between related pointer
// types, such as void* and double*.


// 17.9 pointers and references

// you can think of a reference as an automatically dereferenced immutable
// pointer or as an alternative name for an object. Pointers and references
// differ in these ways

// assignment to a pointer changes the pointer's value( not the pointed to value)
// to get a pointer you generally need to use new or &
// to access an object pointed by a pointer you use * or []
// assignment to a reference changes the value of the object referred to
// (not the reference itselt)
// you cannot make a reference refer to a different object after
// initialization
// assignment of references does deep copy( assigns to the referred-to object)
// assignment of pointers does not assigns to the pointer object itself
// beware of null pointers

// for example

int x=10;
int* p=&x;          //you need & to get a pointer
*p=7;               //use * to assign x through p
int x2=*p;          // read x through p;
int* p2=&x2;         // p2 and p both point to x
p=&x2;              // make p point to another object

// the corresponding example for references is

int y=10;
int& r=y;               //the & is in the type, not in the initializer
r=7;                    //assign to y through r(no * needed)
int y2=r;               //read y through r(no * needed)
int& r2=y2;             // get a reference to another int
r2=r;                   // the value of y is assigned to y2
r=&y2;                  // error: you cant change the value of a reference
                        // no assignment of an int* to an int&


int inct_v(int x){return x+1;}      // compute a new value and return it
void incr_p(int* p){++*p;}          // pass a pointer
                                    // dereference it and increment the result

void incr_r(int& r){++r;}           // pass a reference

int x=2;
x=incr_v(x);        // copy x to incr_v(); then copy the result out and assign it

// using a pointer argument alerts the programmer that something might be
// changed.

int x=7;
incr_p(&x);         // argument of incr_p is pointer int* p, & is needed
incr_r(x);

// the need to use & in incr_p(&x) alters the user that x might be changed
// in contrast, incr_r(x) 'looks innocent'

// function needs to know pointer argument to be assigned is not nullptr
// o.w. it will crash

incr_p(nullptr);        //crash: incr_p() will try to dereference the null pointer
int* p=nullptr;       
incr_p(p);              //crash:incr_p() will try to dereference the null pointer

// changes in incr_p() to avoid this problem

void incr_p(int* p)
{
    if(p==nullptr) error("null pointer argument in incr_p");
    ++*p;           //dereference the pointer and increment the object point to 


}

// a X* object can be implicitly converted to a Y* because Y is a public base
// of X. For example

void rotate(shape* s,int n);            //shape is a public base of circle

shape* p=new circle{point(100,100),40};
circle c{point{200,200},50};
rotate(p,35);
rotate(&c, 45);

