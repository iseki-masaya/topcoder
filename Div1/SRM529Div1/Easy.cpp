#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <sstream>
#include <set>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <stdio.h>
#include <string.h>
#include <iomanip>

#define INF (1<<30)
#define LINF (5e18)

const double EPS = 1.0e-8;

using namespace std;

typedef pair<string, int> P;

class KingSort {

public:
    static string find_name(const string &str) {
        int e = (int)str.find(" ");
        return str.substr(0,e);
    }

    static string find_val(const string &str) {
        int e = (int)str.find(" ");
        return str.substr(e+1,str.size()-e);
    }

    static int calc_val(const string &str) {
        string tens[] = {"","X","XX","XXX","XL","L"};
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        for (int n=1; n<=50; ++n) if (str == (tens[n/10] + ones[n%10]) ) return n;
    }

    static bool comp(const string &lhs,const string &rhs) {
        string ln = find_name(lhs) , rn = find_name(rhs);
        if (ln != rn)
            return ln < rn;
        string lv = find_val(lhs) , rv = find_val(rhs);
        return calc_val(lv) < calc_val(rv);
    }

    vector <string> getSortedList(vector <string> kings) {
        sort(kings.begin(), kings.end(), comp);
        return kings;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
    void test_case_0() { string Arr0[] = {"Louis II", "Louis I"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Louis I", "Louis II" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getSortedList(Arg0)); }
    void test_case_1() { string Arr0[] = {"Louis IX", "Philippe II"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Louis IX", "Philippe II" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getSortedList(Arg0)); }
    void test_case_2() { string Arr0[] = {"Richard III", "Richard I", "Richard II"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Richard I", "Richard II", "Richard III" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getSortedList(Arg0)); }
    void test_case_3() { string Arr0[] = {"John X", "John I", "John L", "John V"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"John I", "John V", "John X", "John L" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getSortedList(Arg0)); }
    void test_case_4() { string Arr0[] = {"Philippe VI", "Jean II", "Charles V", "Charles VI", "Charles VII", "Louis XI"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Charles V", "Charles VI", "Charles VII", "Jean II", "Louis XI", "Philippe VI" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getSortedList(Arg0)); }
    void test_case_5() { string Arr0[] = {"Carlos XXI", "Carlos IX", "Carlos XLIX", "Carlos XLIV", "Carlos XXXV", "Carlos XXIX", "Carlos XXXIII", "Carlos XXVI", "Carlos XIII", "Carlos XLVIII", "Carlos XL", "Carlos XXXVIII", "Carlos XI", "Carlos XXIII", "Carlos XXXVII", "Carlos XXVIII", "Carlos XXV", "Carlos XXX", "Carlos XLII", "Carlos XVIII", "Carlos III", "Carlos XV", "Carlos VIII", "Carlos XXIV", "Carlos XLVI", "Carlos II", "Carlos XIV", "Carlos VI", "Carlos L", "Carlos I", "Carlos XXXIX", "Carlos XLVII", "Carlos XXXVI", "Carlos XXVII", "Carlos XX", "Carlos XXII", "Carlos XIX", "Carlos XII", "Carlos XXXIV", "Carlos XVII", "Carlos XVI", "Carlos XXXII", "Carlos X", "Carlos V", "Carlos XXXI", "Carlos IV", "Carlos XLIII", "Carlos XLI", "Carlos XLV", "Carlos VII"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Carlos I", "Carlos II", "Carlos III", "Carlos IV", "Carlos V", "Carlos VI", "Carlos VII", "Carlos VIII", "Carlos IX", "Carlos X", "Carlos XI", "Carlos XII", "Carlos XIII", "Carlos XIV", "Carlos XV", "Carlos XVI", "Carlos XVII", "Carlos XVIII", "Carlos XIX", "Carlos XX", "Carlos XXI", "Carlos XXII", "Carlos XXIII", "Carlos XXIV", "Carlos XXV", "Carlos XXVI", "Carlos XXVII", "Carlos XXVIII", "Carlos XXIX", "Carlos XXX", "Carlos XXXI", "Carlos XXXII", "Carlos XXXIII", "Carlos XXXIV", "Carlos XXXV", "Carlos XXXVI", "Carlos XXXVII", "Carlos XXXVIII", "Carlos XXXIX", "Carlos XL", "Carlos XLI", "Carlos XLII", "Carlos XLIII", "Carlos XLIV", "Carlos XLV", "Carlos XLVI", "Carlos XLVII", "Carlos XLVIII", "Carlos XLIX", "Carlos L"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, getSortedList(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    KingSort ___test;

    ___test.run_test(-1);

}

// END CUT HERE
