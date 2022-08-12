


// we have used set() and get(), but want to use v[i] to get access  to a
// vector's ele,
// try

class vector{
    int sz;             // the size
    double* elem;       //a pointer to the elements
public:
    //....
    double operator[](int n){return elem[n];}       //return element
}

vector(10);
double x=v[2];      //fine
v[3]=x;     //error

// our operator [] can only read but cant write. v[i] is interpreted 
// as a call v.operator[](i) and returns the value of v's element number i

// next try to let operator[] return a pointer to the appropriate element

class vector{
    int sz;             //size
    double* elem;       //a pointer to the elements;
public:
    //....
    double* operator[](int n){return &elem[n];}     //return pointer
}

//given that definition, we can write

vector v(10);
for(int i=0;i<v.size();++i){
    *v[i]=i;
    cout<<*v[i];
}

//here v[i] is interpred as a call v.operator[](i), and that call returns
// a pointer to v's element number i. the problem is that we have to write
//* to dereference that pointer to get to the element. thats almost as bad
// as having to write set() and get()
// to solve this problem:

class vector{
    //....
    double& operator[](int n){return elem[n];}      //return reference
}

vector v(10);
for (int i=0;i<v.size();++i){       //works
    v[i]=i;     //v[i] returns a reference element i
    cout<<v[i];

}


//overloading on const vector

// the operator[] defined so far has a problem: it cannot be invoked for a const
// vec.

void f(const vector& cv)
{
    double d=cv[1];         //error but should be fine
    cv[1]=2.0;      //error (as it should be)
}

// the reason is that our vector::operator[]() could potentially change
// a vector. The solution is to provide a version that is a const member
// fucntion

class vector{
    //....
    double& operator[](int n);      //for non-const vectors
    double operator[](int n) const;     //for const vectors
}

void ff(const vector& cv, vector& v)
{
    double d=cv[1];     //fine(uses the const [])
    cv[1]=2.0;      //error (uses the const[])
    double d=v[1];          //fine (uses the non-const[])
    v[1]=2.0;       //fine (uses the non-const[])
}

// since vectors are often passed by const reference, this const version
// of operator[]() is an essential addition
