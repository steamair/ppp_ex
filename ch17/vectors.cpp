


/*
ppp 17.2

vector<double> age(4);      //a vector with 4 elements of type double
age[0]=0.33;
age[1]=22.0;
age[2]=27.2;
age[3]=54.2;


//design a fixed data structure;

class vector{
    int size, age0,age1,age2,age3;
    //.....
}

// a data type that can hold an addres is called a pointer and is syntactically
// distinguished by the suffix *.
// so that double* means "pointer to double"

//first  version of vector class

class vector{
private:
    int sz;                 //the size
    double* elem;           // pointer to the first element(of type double)
public:
    vector(int s);          // constructor:allocate s doubles,
                            // let elem point to them
                            // store s in sz
    int size() const{return sz;}    // the current size
}

// int var=17;
// this will set aside an "int-size" piece of memory for var somwhere
// and put the value 17 into that memory.
// we can alos store and manipulate addresses. an object
// that holds an address value is called a pointer.


// the type needed to hold the address of an int is called a "pointer to int"
// or an "int pointer"  and the notation is int*

//int* ptr=&var;            //ptr holds the address of var

// int x=17;
// int* pi=&x;          //pointer to int variable x
// double e=2.71828;
// double* pd=&e;           //pointer to the double variable e

// if we want to see the value of the object pointed to,
// we can do that using the "contents of" operator, unary*

// cout<<"pi=="<<pi<<";contents of pi=="<<*pi<<"\n";
// cout<<"pd=="<<pd<<";contents of pd=="<<*pd<<"\n";

// the output of *pi is 17, and *pd is 2.71828;
// the output of pi and pd will vary depending on where the compiler
// allocated our variables x and e in memeory.

// the contents of operator (often called the dereference operator)

// *pi=27;              //assign 27 to the int pointed to by pi
// *pd=3.14159;         // assign 3.14159 to the double pointed to by pd
// *pd=*pi;             // assign an int(*pi) to double(*pd)

// int i = pi;          //can't assign an int* to an int
                        //remember pi was created as a variable of int*

// pi=7;            // cant assign an int to an int*;

// char*pc =pi;         // can't assign an int* to a char*

//pi=pc;                //error:can't assign a char* to an int*
                        // why is it an error?
                        // because char is usually smaller than int
//consider

// char ch1='a';
// char ch2='b';
// char ch3='c';
// char ch4='d';
// int* pi=&ch3;            //point to ch3, a char-size piece of memory
                            //error: cannot assign a char* to an int*
                            //but lets pretend we could

//*pi=12345;
//*pi=67890;

// sizeof operator

// can be used to see how much memory of, for example, int take up

// void sizes(char ch, int i , int* p)
{
    cout<<"the size of char is "<<sizeof(char)<<""<<sizeof(ch)<<'\n';
    cout<<"the size of int is "<<sizeof(int)<<""<<sizeof(i)<<'\n';
    cout<<"the size of int* is "<<sizeof(int*)<<""<<sizeof(p)<<'\n';

}

// sizeof can be appiled either to a type name or to an expression
// for a type, sizeof gives the size of an object of that type
// for an expression, gives the size of type of the result
// the result of sizeof is a positive int
// char is stored in a byte, so sizeof reports the number of bytes

// how much memory is used by a vector?

// vector<int> v(1000);
// cout<<"the size of vector<int>(1000) is "<<sizeof(v)<<"\n";

// the output will be something like
// the size of vector<int>(1000) is 20
// so sizeof is not counting the elements.

*/


/*
//free store and pointers
// C++ compiler sets aside memoery for code (code store or text store)
// global variable(static store)

// complier also sets aside memeory to be used when you call functions
// they need space for their arguments and local variables
// called stack storage or automatic storage

//the rest of the computer's memory is potentially available for
//other uses; it is "free". 

// the c++ makes this "free store" (also called the heap) available through
// an operator called new. for example

// double* p=new double[4];     //allocate 4 doubles on the free store
// this asks the c++ runtime system to allocate four doubles on the free
// store and return a pointer to the first double to us. we use that pointer
// to initialize our pointer variable p.

// the new operator returns a pointer to the object it creates.
// if it created several objects(an array), it returns a pointer to the first
// of those objects
// if that object is of type X, the pointer returned by new is of X*.
// for example

// char* q=new double[4];                   //double* assigned to char*

// that new returns a pointer to a double and a double isnt a char, so
// there goes the error.

// free-store allocation


// we request memory to be allocated on the free store by the new operator

// the new operator returns a pointer to the allocated memory
// a pointer value is the address of the first byte of the memory
// a pointer points to an object of a specifed type
// a pointer does not know how many elements it points to

// the new operator allocates individual elements or seq(arrays) of 
// elements. for example

// int* pi= new int;            //allocate one int
// int* qi=new int[4];          // allocate 4 ints(an array of 4 ints)

// double* pd=new double;       //allocate one double
// double* qd=new double[n]     //allocate n doubles(an array of n doubles)

// pointers to objects of different types are different types.
// allowing assignments of pointers to different types would allow type errors

// access through pointers

// in addition to using the dereference operator * on a pointer,
// we can use the subscript operator[]

// double* p=new double[4];         //allocate 4 doubles on the free store
// double x = *p;                   // read the first object pointed to by p
// double y=p[2];                   // read the 3rd object pointed to by p

// the subscript operator counts from 0 like vector's subscrip operator

// *p=7.7;                  // write to the first object pointed to by p
// p[2]=9.9;                // write to the 3rd object pointed to by p

// a pointer points to an object in memory. the 'contents of'   operator
// also called the dereference operator allow us to read and write the object
// pointed to by a point

// double x=*p;         //read the object pointed to by p
// *p=8.8;              // write to the object pointed to by p

// when appiled to a pointer, the [] operator treats memory as a seq of objects
// of the type specified by the pointer declaration with the first one pointed
// by a pointer p:

// double x=p[3];               //read the 4th object pointed to by p;
// p[3]=4.4;                    //write to the 4th object pointed to by p;
// double y=p[0];               // p[0] is the same as *p

 */