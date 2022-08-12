
//18.7

// a palindorme is a word that is splled the same from both ends
// two ways of determining whether a word is a palindrome

// make a copy of the letters in reverse order and compare that copy
// to the original

// see if the first letter is the same as the last, then see if the
// second is the same as the second to last, and keep going


//18.7.1 palindromes using string

bool is_palindrome(const string&s)
{
    int first=0;        // index of first letter
    int last=s.length()-1;      //index of last letter
    while(first<last){          //we haven't reached the middle
        if(s[first]!=s[last]) return false;
        ++first;            //move forward
        --last;             //move backward
    }
    return true
}


int main(){
    for (string s; cin>>s;){
        cout<<s<<"is";
        if(!is_palindrome(s)) cout<<"not";
        cout<<"a palindrome\n";
    }
}

// had we wanted to test is_palindrome() with strings containing white spaces
// we could have read using getline()

// palindromes using arrays

bool is_palindrome(const char s[],int n)
// s points to the first char of an array of n chars

{
    int first=0;        //index of first letter
    int last=n-1;       //index of last letter
    while(first<last){      //we havent reached the middle
        if(s[first]!=s[last]) return false;
        ++first;
        --last;

    }
    return true;
}

// to exercise is_palindrome(), we first have to get chars read into the
// array

istream& read_word(istream& is, char* buffer, int max)
//read at most max-1 chars from is into buffer
{
    is.width(max);          //read at most max-1 chars in the next>>
    is>>buffer;     //read whitespace terminated word
                    //add zero after the last char read into buffer
    return is;
}

//using read_word() we can write

int main(){
    constexpr int max=128;
    for (char s[max]; read_word(cin,s,max);){
        cout<<s<<"is";
        if(!is_palindrome(s,strlen(s))) cout<<"not";
        cout<<"a palindrome";
    }
}

// the strlen(s) call returns the number of chars in the array after the call
// of read_word() and cout<<s outputs the chrs in the array up to the terminating 0

//18.7.3 palindromes using pointers

bool is_palindrome(const char* first, const char* last)
        //first points to the first letter, last to the last letter
{
    while(first<last){      //we haven't reached the middle
        if(*first!=*last) return false;
        ++first;
        --last;

    }
    return true;
}

int main(){
    const int max=128;
    for (char s[max]; read_word(cin,s,max);){
        cout<<s<<"is";
        if(!is_palindrome(&s[0],&s[strlen(s)-1]))cout<<"not";
        cout<<"a palindrome\n";
    }
}

// can rewrite is_palindrome()

bool is_palindrome(const char* first, const char* last)
{
    if(first<last){
        if(*first!=*last) return false;
        return is_palindrome(first+1,last-1);
    }
    return true;
}