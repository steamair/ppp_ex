


#include "../std_lib_facilities.h"

class Name_pairs{

public:

Name_pairs() {};                //consturctor?
void read_names();
void read_ages();
void print();
void sort();

private:

vector<string> names;
vector<double> ages;
};

Name_pairs::print(vector<string> names; vector<double> ages;){
    for (int i =0; i<names.size(); ++i){
        cout<<"name: "<<names[i]<<" Age:"<<ages[i]<<endl;
    }
}

Name_pairs::sort(vector<string>& names; vector<double>& ages;)
{
    vector<string> temp_names=names;
    vecotr<double> temp_ages
    sort(names.begin(),names.end());
    for (int i=0;i<names.size();++i){
        for (int j=0; j<names.size();++j){
            if (temp_names[j]==names[i])
                temp_ages[j]=ages[i]; 
        }
    }
    ages=temp_ages;
}