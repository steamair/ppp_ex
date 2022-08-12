

#include "../std_lib_facilities.h"


struct Reading {
    int hour;
    double temp;

};


int main(){
    cout<<"please enter input file name";
    string iname;
    cin >> iname;

    ifstream ist{iname};
    if(!ist) error("cant open input file", iname);

    string oname;
    cout<<"please enter name of output file";
    cin>> oname;
    ofstream ost{oname};

    if(!ost) error("cant open output file", oname);

    vector<Reading> temps;
    int hour;
    double temp;
    while (ist>>hour>>temp){
        if(hour<0||23<hour) error("hour outof range");
        temps.push_back(Reading{hour,temp});

    }

    for (int i =0;i<temps.size();++i)
    {
        ost<<"("<<temps[i].hour<<','
            <<temps[i].temp<<endl;
    }
}