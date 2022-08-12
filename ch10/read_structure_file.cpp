/*
ppp 10.11
*/


/*
const int not_a_reading=-7777; //less than abs zero;

const int not_a_month=-1;



struct Day{                 //data sturcture day, with 24 records,
                            // each initialized to not_a_reading
    vector<double> hour {vector<double>(24,not_a_reading)};
                        // a day has 24 hours, each is initialized to
                        // not_a_reading
    };
struct Month{               // a month of temperature readings
        int month{not_a_month};      //[0:11] jan is 0
        vector<Day> day{32};        //[1:31] one vector of reading per day
                                    //we waste day[0] to keep the code simple
}


struct Year{                // a year of temperature readings, organized by month
    int year;               // positive ==A.D.
    vector<Month>month {12};    //[0:11] jan is 0
}



// The reading class will be used only for reading input

struct Reading{
    int day;
    int hour;
    double temperature
};

istream& operator>>(istream& is, Reading& r)
// read a temperature reading from is into r
// format:(3 4 9.7)
// checkformat, but don't bother with data validaity
{
    char ch1;
    if (is>>ch1&& ch1!='('){
        is.unget();             //put input back
        is.clear(ios_base::failbit);
        return is;
    }
    char ch2;
    int d;
    int h;
    double t;
    is >> d >> h >> t >> ch2;
    if(!is||ch2!=')') error("bad reading");           //messed-up reading
    r.day=d;
    r.hour=h;
    r.temperature=t;
    return is;
}


// the Month input operation is much the same, except that is had to read
// and arbitrary number of Readings rather than a fixed set of values
// (as Reading's >> did)

istream& operator>>(istream& is, Month& m)
// read a month from is into m
// format: {month feb ....}
{
    char ch=0;
    if(is>>ch && ch!='{'){
        is.unget();
        is.clear(ios_base::failbit);            //we failed to read a month
        return is;
            }
    string month_marker;
    string mm;
    is>>month_marker>>mm;
    if(!is||month_marker!="month") error("bad start of month");
    m.month=month_to_int(mm);
    int duplicates =0;
    int invalids =0;
    for (Readings r; is>>r;){
        if (is_valid(r)){
            if(m.day[r.day].hour[r.hour]!=not_a_reading)
                ++duplicatges;
            m.day[r.day].hour[r.hour]=r.temperature;
        }
    else
        ++invalids;
    }

    if(invalids) error("invalid readings in month",invalids);
    if(duplicates) error('duplicate reading in month", duplicates)
    end_of_loop(is,'}',"bad end of month");
    return is;
}

constexpr int implausible_min=-200;
constexpr int implausible_max=200;

bool is_valid(const Reading& r)
//a rough test
{
    if(r.day<1||31<r.day) return false;
    if(r.hour<0||23<r.hour) return false;
    if(r.temperature<implausible_min||implausible_max<r.temperature)
        return false;
    return true;

// read Years

istream& operator>>(istream& is, Year& y)
//read a year from is into y
//format: {year 1972  ....}

{
char ch;
is >> ch;
if(ch!='{'){
    is.unget();
    is.clear(ios::failbit);
    return is;
}

string year_marker;
int yy;
is >> year_marker >> yy;
if (!is||year_marker!="year") error("bad start of year");
y.year=yy;

while(true){
    Month m;            //get a clean m each time around
    if(!(is>>m)) break;
    y.month[m.month] = m;    
}

end_of_loop{is,'}',"bad end of year");
return is;


}
}
*/


//lets try to use it

/* 
//open an input file:
cout<<"please enter input file name\n";
string iname;
cin>>iname;
istream ifs{iname};
if(!ifs) error("cant open input file",iname);

ifs.exceptions(ifs.exceptions()|ios_base::badbit);      //throw for bad()

//open an output file;

cout<<"please enter output file name\n";
string oname;
cin>>oname;
ostream ofs{oname};
if(!ofs) error("cant open output file",oname);

//read an arbitrary number of years;
vector<Year> ys;

while(true){
    Year y;         //get a fresh initialized Year each time around
    if (!(ifs>>y)) break;
    ys.push_back(y);
}
cout<<"read"<<ys.size()<<"years of readings \n";
for (Year& y :ys) print_year(ofs,y);

*/


/* to get Month's >> to work, we need to provide a way of reading
symbolic representations of the month
*/

/* 
if (s=='jan)
    m=1;
else if(s=='feb')
    m=2;
//....

//this is tedious
//we rather using a vector

//i.e.,
vector<string> month_input_tbl={
    "jan","feb","mar","apr","may","jun","july","aug","sep","oct","nov","dem"
}

int month_to_int(string s)
// is s the name of a month? if so return its index[0:11] o.w. -1
{
    for (int i=0;i<12;++i)
        if(month_input_tbl[i]==s) return i;
    return -1
}
*/

/*
//produce output, in this case we have an int representation that wants to find
//a suitable symbolic representation to be printed.
//insteand of using a table to go from string to int, we use one to go from int
//to string
 
 vector<string> month_print_tbl={
    "january","february","march","april","may","june","july","aug","sep",
    "oct","nov","dec"
 };

 string int_to_month(int i)
 //month [0:11]
 {
    if(i<0 || 12<=i) error("bad month index");
    return month_print_tbl[i];
 }
 
 
 
 */
