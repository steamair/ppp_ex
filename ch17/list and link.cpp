


// 17.9.3 lists

// doubly linked list, nodes are linked to their predecessor and successor
// singly linked list, nodes can only find their successor

// we use doubly linked lists when we want to make it easy to remove an
// element

struct Link{
    string value;
    Link* prev;
    Link* succ;
    Link(const string& v, Link* p=nullptr, Link* s= nullptr)
        : value{v}, prev{p}, succ{s}{}          //DEFUALT CONSTRUCTOR
}

// given a link, we can get to its successor using the succ pointer
// and to its predecessor using the prev pointer
// use nullptr to indicate the nodes which do not have predecessor
// or successor

Link* norse_gods=new Link{"Thor", nullptr, nullptr};
norse_gods=new Link{"Odin", nullptr,norse_gods};
norse_gods->succ->=norse_gods;
norse_gods=new Link{"Freia", nullptr, norse_gods};
norse_gods->succ->prev=norse_gods;

// first thor, then ordin as predecessor of thor, freia as precessor of odin
// each succ and prev points to the right god.

// code is obscure because we didnt explicitly define and name an insert operation

Link* insert(Link* p, Link* n)        //insert n before p(incomplete)
{
    n->succ=p;      //p comes after n
    p->prev->succ=n;    //n comes after waht used to be p's predecessor
    n->prev=p->prev;    // p's predecessor becomes n's predecessor
    p->prev=n;      // n becomes p's predecessor
    return n;
}
x
// to handle the case where n,p or p->prev is nullptr

Link* insert(Link* p, Link* n)  //insert n before p, return n
{
    if(n==nullptr) return p;
    if(p==nullptr) return n;
    n->succ=p;      // p comes after n
    if (p->prev) p->prev->succ=n;
    n->prev=p->prev;        //p's predecessor becomes n's predecessor
    p->prev=n;          // n becomes p's predecessor
    return n;
}

// now, to create the same list
Link* norse_gods=new Link{"thor"};
norse_gods=insert(norse_gods, new Link{"ordin"});
norse_gods=insert(norse_gods, new Link{"freia"});


//17.9 list operations

// operations recommended for a list

/* 
the constructor
insert:insert before an element
add: insert after an element
erase: remove an element
find: find a link with a given value
advance: get the nth successor

*/

Link* add(Link* p, Link* n) //insert n after p; return n
{
    //much like insert , excercise 11
}

Link* erase(Link* p)    //remove *p from list, return p's successor
{
    if(p==nullptr) return nullptr;
    if(p->succ) p->succ->prev=p->prev;
    if (p->prev) p->prev->succ=p->succ;
    return p->succ;
}

Link* find(Link* p, const string& s)        //find s in list;
                                            // return nullptr for "not found"
{
    while(p){
        if(p->value==s) return p;
        p=p->succ;

    }
    return nullptr;
}

Link* advance(Link* p, int n)       //moveo n positions in list
                                    // return nullptr for "not found"
                                    //positive n moves forward, negative backward
{
    if (p==nullptr) return nullptr;
    if(0<n){
        while(n--){
            if(p->succ==nullptr) return nullptr;
            p=p->succ;
        }    
    }
    else if(n<0){
        while(n++){
            if(p->prev==nullptr) return nullptr;
            p=p->prev;
        }
    }
    return p;
}

// 17.9.5 list use

Link* norse_gods=new Link{'thor'};
norse_gods=insert(norse_gods,new Link{"ordin"});
norse_gods=insert(norse_gods, new Link{"zeus"});
norse_gods=insert(norse_gods,new Link{'freia'});

Link* greek_gods=new Link{"hera"};
greek_gods=insert(greek_gods,new Link{'athena'});
greek_gods=insert(greek_gods,new Link{"mars"});
greek_gods=insert(greek_gods,new Link{'poseidon'});

//there is some mistake, we can correct it by doing

Link* p=find(greek_gods,"mars");
if(p) p->value='ares'

Link* p=find(norse_gods,"zeus");
if(p){
    erase(p);
    insert(greek_gods,p);
}

//be caution here, if the link we erase() is the one pointed by norse_gods,
// there could be problem,

Link* p=find(norse_gods,"zeus");
if(p)
{
    if(p==norse_gods) norse_gods=p->succ;
    erase(p);
    greek_gods=insert(greek_gods,p);

}

//print lists
void print_all(Link* p)
{
    cout<<"{";
    while(p){
        cout<<p->value;
        if(p=p->succ) cout<<",";

    }
    cout<<"}";
}
print_all(norse_gods);

//17.10 the this pointer

// simply link by makring the operations members, make the pointers private
// so that only the member functions have access to them

class Link{
public:
    string value;

    Link(const string& v, Link* p=nullptr, Link* s= nullptr)
        :value{v}, prev{p}, succ{s}{}
    Link* insert(Link* n);          //insert n before this object
    Link* add(Link* n);     //insert n after this object
    Link* erase();      //remove object from the list
    Link* find(const string& s);        //find s in list
    const Link* find(const string& s) const;    // find s in const list

    Link* advance(int n) const;     //move n position in list
    Link* next() const {return succ;}
    Link* previous() const {return prev;}
private:
    Link* prev;
    Link* succ;
};

Link* Link::insert(Link* n)     //insert n before p; return n
{
    Link* p=this;   //pointer to this object
    if(n==nullptr) return p;    //nothing to insert
    if(p==nullptr) return n;    //nothing to insert into
    n->succ=p;      //p comes after n
    if(p->prev) p->prev-succ=n;
    n->prev=p->prev; //p's predecessor becomes n's predecessor
    p->prev=n;  //n becomes p's predecessor
    return n;
}

// the identifier this is a pointer that points to the object for which
// the member function was called, alternatively, we could simply use this
// instead of p

Link* Link::insert(Link* n) //insert n before this object; return n
{
    if(n==nullptr) return this;
    if(this==nullptr) return n;
    n->succ=this;       //this object comes after n
    if(this->prev) this-> prev->succ=n;
    n->prev=this->prev;     // this object's predecessor
                            // becomes n's predecessor
    this->prev=n;           //n becomes this object's predecessor
    return n;
}

//but we dont need to mention this to access a member

Link* Link::insert(Link* n) //insert n before this object return n
{
    if(n==nullptr) return this;
    if(this==nullptr) return n;
    n->succ=this;   //this object comes after n
    if(prev) prev->succ=n;
    n->prev=prev;       //this object's predecessor becomes n's predecessor
    prev=n;     // n becomes this object's predecessor

}

// have been using the this pointer, the pointer to the current object
// implicitly every time we accessed a member. it is only when we need to 
// refer to the whole object that we need to mention it explicitly


// note: this has a special meaning, it points to the object for which a member
// function is called. it does not point to any old object. the compiler
// ensures that we do not change the value of this in a member function

struct S{
    //....
    void mutate(S* p)
    {
        this=p;     //error,  this is immutable
    }
}


// 17.10.1  More link use

Link* norse_gods=new Link{"thor"};
norse_gods=norse_gods->insert(new Link{"odin"});
norse_gods=norse_gods->insert(new Link{"zeus"});
norse_gods=norse_gods->insert(new Link{'freia'});

Link* greek_gods=new Link{'hera'};

greek_gods=greek_gods->insert(new Link{'athena'});
greek_gods=greek_gods->insert(new Link{'mars'});
greek_gods=greek_gods->insert(new Link{"poseidon"});

// now correct the name of the god of war

Link* P=greek_gods->find("mars");
if(p) p->value='ares';

// move zeus into his correct pantheon;

Link* p2=norse_gods->find("zeus");
if(p2){
    if(p2==norse_gods) norse_gods=p2->next();
    p2->erase();
    greek_gods=greek_gods->insert(p2);
}

void print_all(Link* p)
{
    cout<<"{";
    while(p){
        cout<<p->value;
        if(p=p->next()) cout<<',';

    }
    cout<<"}";
}

