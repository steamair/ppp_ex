

/* 
read a file from begining until end of file.
ppp 10.10

*/

/* 
for (My_type var; ist>>var;)        //read until end of file
{   // maybe check that var is valid
    // do something with var

}

//we can rarely recover from bad; don't try unless you really have to;
if (ist.bad()) error("bad input stream")
if (ist.fail()){
    //was it an acceptable terminator?
}
//carry on

// somewhere: make ist throw an exception if it goes bad

ist.exceptions(ist.exceptions()|ios_base::badbit);


// if we want designate a character as terminator
for (My_type var; ist>>var;){       //read until end of faile
    //

if (ist.fail()){                //use "|" as terminator and/ or separator
    ist.clear();
    char ch;
    if(!(ist>>ch &&ch=='|')) error ("bad terminator of input");
}
}

*/

/*  

write a function for terminator test

// somewhere : make ist throw if it goes bad:

ist.exceptions(ist.exceptions()| ios_base::badbit);

void end_of_loop(istream& ist, char term, const string& message)
{
    if(ist.fail()){                     //use term as terminator and or separator 
        ist.clear();
        char ch;
        if (ist>>ch && ch==term)    return;     //all is fine
        error(message);
    }
}
*/