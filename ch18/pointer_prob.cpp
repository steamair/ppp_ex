

// access through the null pointer
// access through an uninitialized pointer
// access of the end of an array
// access of the end of an array
// access to a deallocated object
// access to an object that has gone out of scope

// test null pointer before use

int* p=fct_that_return_a_nullptr();

if (p==nullptr){
    //do something
}
else {
    //use p
    *p=7;
}

void fct_that_return_a_nullptr(int* p){
    if (p==nullptr){
        // do something
    }
    else {
        // use p
        *p=7;
    }
}

// using reference and using exceptions to signal errors are the main tools
// for avoiding null pointers

//do not return a pointer to a local variable

int* f()
{
    int x=7;
    //....
    return &x;
}
//....
int* p=f();

//....
*p=15;