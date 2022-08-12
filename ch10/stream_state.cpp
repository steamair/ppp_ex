

/* read a sequence of integers that may be terminated by the character * or
"end of file" (ctrl+z on windows and ctrl+d on unix) into a vector

1 2 3 4 5 *

this could be done using a function like this

*/

/*

void fill_vector(istream& ist, vector<int>& v, char terminator)
//read integers from ist into v until we reach eof() or terminator

{
    for (int i; ist>>i;) v.pushback(i);
    if(ist.eof()) return;               // we found the end of file

    if(ist.bad() error("ist is bad"));      //stream corrupted
    if(ist.fail()){                     //clean up the mess as best we can
                                        //report the problem
        ist.clear()                     //clear stream state,
                                        // so that we can look for terminator
        char c;
        ist>>c;                         //read a character, hopefully terminator
        if (c!=terminator){             // unexpected character
            ist.unget()                            // put that character back
            ist.clear(ios_base::failbit);       //set the state of fail()

        }

    }
}
*/