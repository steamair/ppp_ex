
#include <stdlib>
#include <vector>
#include <fstream>          //open a file for writing
#include <list>
#include <map>


// drill 1 define the struct 
struct Item{
    std::string name;
    int iid;
    double value;
    Item():name(""),iid(0),value(0)    //default constructor
    {                                     

    }
    Item(std:string n,int i, double v)  //constructor
        :name(n),int(i),value(v)
    {

    }
    ~Item()
};


//----------------------------



// overwrite operator<< (global)

//<< output
std::ostream& operator<<(std::ostream& os, const item& it)
{
    return os<<it.name<<"\t"
            <<it.iid<<"\t"
            <<it.value<<"\n";
}

// overwrite operator >> (global)
// >> input

std::isotream& operator>>(std::istream& is, Item& it)
{
    std::string name;
    int id;
    double value;
    is>>name>>id>>value;
    if(!is) return is;
    it=Item{name,id,value};
    return is;
}


//---------------

//sort by name
struct Cmp_by_Name{         //sort by name
    bool operator()(const item& a, const item& b)
    {return a.name<b.name ;}
};

//sort by iid

struct Cmp_by_id{   
    bool operator(){const item& a, const item& b}
    {
        return a.iid<b.iid
    }
}

//sort by value by decreasing order

struct Cmp_by_value{   
    bool operator(){const item& a, const item& b}
    {
        return a.value>b.value
    }
}

//insert?



//-----

//print

template<typename P>

void print_out(const P& p)
{
    for (const auto& a: p)
        std::cout<<a<<'\t';
    
}

