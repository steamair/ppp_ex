

/*
//remove unwated char


ps.whitespace(";:,.");          //treat semicolon.colon,comma,and dot as whitespace
for (string word; ps>>word;)
    vs.push_back(word);

*/


/* 

// allow uses to specify additional "whitespace" chars

punct_stream:
    class punct_stream{     //like an istream, but the user can add to
                            // the set of whitespace chars
    public:
        punct_stream(istream& is)
            : source{is}, sensitive{true} {}
        void whitespace(const string& s)            //make s the whitespace set
            {white=s;}
        void add_white(char c){white +=c;}          // add to the whitespace set
        bool is_whitespace(char c);                 // is c in the whitespace set?
        void case_sensitive(bool b){sensitive=b;}
        bool is_case_sensitive(){return sensitive;}
        punct_stream& operator>>(string& s);
        operator bool();
    private:
        istream& source;                //char source
        istringstream buffer;           // we let buffer do our formatting
        string white;                   // chars considered whitespace;
        bool sensitive;                 // is the stream case-sensitive?

    }

//we can make a punct_stream that reads from cin regarding simicolon,colon
//and dot as whitespace

punct_stream ps{cin};       //ps reads from cin
ps.whitespace(";:.");       // semicolon,colon,and dot are also whitespace
ps.case_sensitive(false);   // non case-sensitive


// try reading from the buffer and try to fill it only when we find it
// empty

punct_stream& punct_stream::operator>>(string& s)
{
    while(!(buffer>>s)){            //try to read from buffer
        if (buffer.bad() || !source.good()) return *this;
        buffer.clear();

        string line;
        getline(source,line);       //get a line from source

        //do char replacement as needed

        for (char& ch : line)
            if(is_whitespace(ch))
                ch='';      //to space
            else if(!sensitive)
                ch=tolower(ch);     //to lower case
        buffer.str(line);           // put string into stream

        return *this;

    }
}


// the while(!(buffer>>s)) means that if there are chars in the 
// istringstream called buffer, the read buffer>>s will work
// and s will receive a whitespace separated word
// then there is nothing more to do
// that will happen if there are chars in buffer for us to read
// however, when buffer>>s fails, if !(buffer>>s) we must
// replenish buffer from source. note that buffer>>s read is in a loop
// after we have tried to replenish buffer, we need to try another read
// so we get


while(!(buffer>>s)){            //try to read from buffer
    if(buffer.bad()||!source.good()) return *this;
    buffer.clear;

    //replenish buffer statement
}

//if buffer is bad(), or the source has a problem, we give up
// o.w. we clear buffer and try again. We need to clear buffer
// because we get into that "replenish loop" only if a read failed,
// typically because we hit eof() for buffer.

string line;
getline(source,line);           //get a line from source

//do char replacement as needed;

for(char& ch:line)
    if(is_whitespace(ch))
        ch='';          //to space
    else if(!sensitive)
        ch= tolower(ch);        //to lower case

buffer.str(line);           //put string into stream


// we read a line into line. then we look at each char of tha tline
// to see if we need to change it. the is_whitespace() is a member of 
// punct_stream, which we will define later. the tolower() is a std
// lib function

// once we have a properly processed line, we need to get it into our istringstream
// that is what buffer.str(line) does. it can be read as "set the istringstream"
// buffer's string to line"
// at the end, we return a reference to the stream itself, *this,
// as the result of >>. see 17.10

//tesing whitespace

bool punct_stream::is_whitespace(char c)
{
    for (char w:white)
        if (c==w) return ture;
    return false
}

punct_stream::operator bool()
{
    return !(source.fail()||source.bad() && buffer.good());

}

//the conventional use of an istream is to test the result of >>. i.e.,
// while(ps>>s) {//..//}


// punct_stream' operator bool() implicitly turns a punct_stream into
// a bool. it returns true if the operation on the punct_stream succeeded

int main()
    //given text input, produce a sorted list of all words in that text
    // ignore punctuation and case differences
    // eliminate duplicates from the output
{

    punct_stream ps{cin};
    ps.whitespace(";:,.?!()\"{}<>&@#%^*|~");     //note \ "means " in string
    ps.case_sensitive(false);
    cout<<"please enter words\n";
    vector<string> vs;
    for (string word; ps>>word;)
        vs.push_back(word);     //read words
    sort(vs.begin(),vs.end());  //sort in lexicographical order
    for (int i =0; i<vs.size();++i)     //write dict
        if(i==0 || vs[i]!=vs[i-1]) cout<<vs[i]<<'\n';
}
*/


