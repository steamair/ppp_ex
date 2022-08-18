
#include <stdlib.h>
#include <vector>
#include <fstream>          //open a file for writing
#include <list>
#include <map>
#include <iostream>


// drill 1 define the struct 
struct Item{
    std::string name;
    int iid;
    double value;
    Item():name(),iid(0),value(0)    //default constructor
    { }
    Item(std::string n,int i, double v)  //constructor
        :name(n),iid(i),value(v)
    { }
};


//----------------------------



// overwrite operator<< (global)

//<< output
std::ostream& operator<<(std::ostream& os, const Item& it)
{
    return os<<it.name<<"\t"
            <<it.iid<<"\t"
            <<it.value<<"\n";
}

// overwrite operator >> (global)
// >> input

std::istream& operator>>(std::istream& is, Item& it)
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
    bool operator()(const Item& a, const Item& b)
    {
        return a.name<b.name;
    }
};

//sort by iid

struct Cmp_by_id{   
    bool operator()(const Item& a, const Item& b)
    {
        return a.iid<b.iid;
    }
};

//sort by value by decreasing order

struct Cmp_by_value{   
    bool operator()(const Item& a, const Item& b)
    {
        return a.value>b.value;
    }
};

//function object for erase

class find_by_Name{
    std::string name;
public:
    find_by_Name(const std::string& s):name(s){}
    bool operator()(const Item& it) const
    {
        return it.name==name;
    }
};

class find_by_iid{
    int iid;
public:
    find_by_iid(const int id):iid(id){}
    bool operator()(const Item& it)const{
        return it.iid==iid;
    }
};



//-----

//print

template<typename P>
void print_out(const P& p)
{
    for (const auto& a: p)
        std::cout<<a<<'\n';
}

//------ vector<item>-----

/*
int main(){
    std::vector<Item> item;
    
    const std::string file_name {"/Users/haoyang/Documents/drill_1_1.txt"};
    
    std::ifstream ifs {file_name};
    if(!ifs ) throw std::runtime_error("could not read from the file:"+ file_name);
    
    //try push_back() to add elem into the vector
    for (Item i; ifs>>i;)
    {
        item.push_back(i);
    }

    //print_out(item);
    // sort item by name
    //std::vector<Item> item_sorted_1;
    std::sort(item.begin(),item.end(),Cmp_by_Name());

    // sort item by id
    std::sort(item.begin(),item.end(),Cmp_by_id());

    

    // sort by value desecending
    std::sort(item.begin(),item.end(),Cmp_by_value());
    //print_out(item);
    

    //insert items
    
    Item hosre_shoe {"horse shoe",99,12.34};
    Item canon {"canon_s400",9988,499.95};

    item.insert(item.end(),hosre_shoe);
    item.insert(item.end(),canon);

    //remove items by name;
    item.erase(find_if(item.begin(),item.end(),find_by_Name("Shirt")));
    item.erase(find_if(item.begin(),item.end(),find_by_Name("horse shoe")));
    //remove items by id;
    item.erase(find_if(item.begin(),item.end(),find_by_iid(2)));
    item.erase(find_if(item.begin(),item.end(),find_by_iid(3)));

    print_out(item);
    return 0;

}

*/
// working with list
/*
int main(){
    std::list<Item> vi;
    Item i;
    const std::string file_name {"/Users/haoyang/Documents/drill_1_1.txt"};
    std::ifstream ifs {file_name.c_str()};
    if (!ifs) throw std::runtime_error("could not read the file name"+file_name);
    while (ifs>>i){
        vi.insert(vi.end(),i);
    }

    // sort by name
    vi.sort(Cmp_by_Name());
    
    // sort by id
    vi.sort(Cmp_by_id());

    //sort by value descending
    vi.sort(Cmp_by_value());

    //insert items
    Item horse_shoe {"horse_shoe",99,12.34};
    Item canon {"canon_s400",9988,499.95};

    vi.insert(vi.end(),horse_shoe);
    vi.insert(vi.end(),canon);
    // erase items
    
    //vi.erase(find_if(vi.begin(),vi.end(),find_by_Name("horse_shoe")));

    //use iterator

    std::list<Item>::iterator vi_it=find_if(vi.begin(),vi.end(),find_by_Name("horse_shoe"));
    vi.erase(vi_it);
    print_out(vi);

    return 0;
    }
//-- play with map----

/*

int accu_value(std::map<std::string,int> a)
{
    int accu=0;
    for (auto i: a)
        accu+=i.second;
    return accu;
}

void read_pairs(std::map<std::string,int>& a){
    std::string key;
    int value;
    std::cin>>key>>value;
    a[key]=value;
}

void swap_map(std::map<std::string,int> a, std::map<int, std::string>& b)
{   std::map<std::string,int>::iterator p=a.begin();
    for (p=a.begin();p!=a.end();++p)
        b[p->second]=p->first;
}

int main(){
    std::map<std::string,int> msi;
    std::map<int,std::string> mis;
    std::map<std::string,int>::iterator it;
    int accu=0;
    //add values into a map;
    msi["ui"]=100;
    msi["baba"]=200;
    msi["cup"]=231;
    msi["key"]=12;
    msi["gum"]=5;


    // erase by keys;
    msi.erase("ui");

    // erase by iterator;
    it=msi.find("key");
    msi.erase(it);
    // erase by range;
    msi.erase(msi.begin(),msi.end());       //erase everything in a map container
    

    //read inputs
    std::cout<<"please enter a name and a value"<<"\n";
    for (int i =0;i<10;++i)
        read_pairs(msi);

    // print out map
    for (const auto& elem:msi)
    {
        std::cout<<elem.first<<'\t'<<elem.second<<"\n";
    }

    // out put the sum of the integer
    accu=accu_value(msi);
    std::cout<<"sum of the value is "<<accu<<"\n";

    //swap map values
    swap_map(msi,mis);

    // initiate map iterator
    //std::map<std::string,int>::iterator it=msi.begin();
    
    for (const auto& elem:mis)
    {
        std::cout<<elem.first<<'\t'<<elem.second<<"\n";
    }

    std::cout<<"size of the map "<<msi.size()<<'\n';

    return 0;
}*/

