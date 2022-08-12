


// array is a homogeneous sequence of objects allocated in contiguous
// memory; all elements of an array have the same type and there are no
// gaps between the objects of the sequence. the elements of an array are
// numbered from 0 upward. in a decalration an array is indicated
// by "sqaure brackets"

const int max=100;
int gai[max];           //a global array(of 100 ints);'lives forever'

void f(int n)
{
    char lac[20];           //local array; "live" until the end of scope
    int lai[60];            
    double lad[n];          //error: array size not a constant
    //....
}

// the number of elem of a named array must be known at compile time

//if you want the number of elem to be a variable, you must put it on the free
//store and access it through a pointer. thats what vector does with its array
// of elem.

// we access named arrray using the subscript and dereference operators []
// and *

void f2()
{
    char lac[20];       //local array; "lives" until the end of scope

    lac[7]='a';
    *lac='b';           //equivalent to lac[0]='b'

    lac[-2]='b';        //???
    lac[200]='c';       //error
}

//18.6.1 pointers to array elem

// a pointer can point to an elem of an array

double ad[10];
double* p=&ad[5];           //point to ad[5]

//we now have a pointer p to the double known as ad[5];

// we can subscipt and dereference that pointer

*p=7;
p[2]=6;
p[-3]=9;

// now the array is something like x x 9 x x 7 x 6 x x x;
// p is the "benchmark".

// we can subcript both positive and negative numbers if the resulting
// element is in range

// once a pointer points into an array, addition and subscription
// can be used to make it point to another element of the array

p+=2;       // move p 2 elem to the right

p-=5;       // move p 5 element to the left

// using +,-,+=,-= to move pointers aournd is called pointer arithmetic
// need to be sure reulst is in range

// the most common use of pointer arithmetic is incrementing a pointer
// (using ++) to point to the next elem and decrementing a pointer
// (using --) to point to the previous elem
// for example, we could print the value of ad's elem like this

for (double* p=&ad[0]; p<&ad[10];++p) cout<<*p<<'\n';

// or backward
for (double* p=&ad[9];p>=&ad[0];--p) cout<<*p<<'\n';

//18.6.2 pointers and arrays

// copy an array
for (int i =0;i<100;++i) x[i]=y[i];     //copy 100 ints
memcpy(x,y,100*sizeof(int));        //copy 100*sizeof(int) bytes
copy(y,y+100,x);            //copy 100 ints

// copy an vector, use vector lib

vector<int> x(100);
vector<int> y(100);
//...
x=y;        //copy 100 ints

// array initialization

// an array of chars can be initialized with a string literal.

char ac[]='beorn';      //array of 6 chars


// ac: "b""e""o""r""n"0
// there are 5 chars in beron but compiler adds a terminating zero char at
// the end of a string literal

// therefore need n+1 chars to store n char in C-style string

//other array initialization

int ai[]={1,2,3,4,5,6}; 
int ai2[100]={0,1,2,3,4,5,6,7,8,9}      // the last 90 elem are assigned to 0
double ad[100]={};          //all elements intied to 0
char chars[]={'a','b','c'};       //no terminating 0

// the add a 0 at the end rule is for literal char strings only.
// if an array isnt given a size, that size is deduced from the ini list
