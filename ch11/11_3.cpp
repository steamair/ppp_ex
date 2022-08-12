/* example code for section 11.3*/


/* 

int main(){
    //open an istream for binary input from a file
    cout<<"please enter input file name\n";
    string name;
    cin>>inanme;
    istream ifs {iname,ios_base::binary}            //note: stream mode
    //binary tells the stream not to try anything clever with the bytes
    if(!ifs) error("cant open input file",name);

    //open an ostream for binary output to a file

    cout<<"please enter a file name\n";
    string oname;
    cin>>oname;
    ostream ofs{oname,ios_base::binary};            //note:stream mode
        // binary tells the stream not try anything clever with the bytes
    if(!ofs) error("cant open output file",oname);

    vector<int> v;

    //read from binary file

    for(int x; ifs.read(as_bytes(x),sizeof(int);))      //reading bytes
        v.push_back(x);
    
    //do something with v

    //write to binary file:
    for (int x:v)
        ofs.write(as_bytes(x),sizeof(int));     //write bytes

    return o;
}


*/