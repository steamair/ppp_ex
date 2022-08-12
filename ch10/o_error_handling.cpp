

/*

int i=0;
cin>> i;

if (!cin ){ //we get here(only) if an input operation failed
//!cin read as "cin is not good"
    if(cin.bad()) error("cin is bad");  //stream corrupted: letws get out of here!
    if (cin.eof()){
        //no more input
        //this is often how we want a sequence of input operations to end
    }
    if(cin.fail()){     //stream encountered something unexpected
        cin.clear();    //make ready for more input
        //somehow recover
    }

}

*/