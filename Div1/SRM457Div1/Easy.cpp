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
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <bitset>
#include <deque>

const long long LINF = (1e15);
const int INF = (1<<27);
#define EPS 1e-6
const int MOD = 1000000007;

const int ma = 10000;

using namespace std;

class TheTriangleBothDivs {

public:
    int conv(string s) {
        int res;
        stringstream ss;
        ss << s;
        ss >> res;
        return res;
    }

    string conv(int h) {
        string res = "";
        stringstream ss;
        ss << h;
        ss >> res;
        if (h<10)
            res = "0"+res;

        return res;
    }

    int calc(int hour, int GMT) {
        return (24 + hour - GMT)%24;
    }

    int get_min_hour(string hour, string GMT) {
        int res = 24;
        if (hour[0] == '?') {
            for (int i=0; i<=2; ++i) {
                string nh = hour;
                nh[0] = i+'0';
                if (nh[1] == '?' || conv(nh) < 24) {
                    res = min(res, get_min_hour(nh, GMT));
                }
            }
            return res;
        }

        if (hour[1] == '?') {
            for (int i=0; i<10; ++i) {
                string nh = hour;
                nh[1] = i+'0';
                if (conv(nh) < 24) {
                    res = min(res, get_min_hour(nh, GMT));
                }
            }
            return res;
        }

        if (GMT[0] == '?') {
            GMT[0] = '+';
            res = min(res, get_min_hour(hour, GMT));
            GMT[0] = '-';
            res = min(res, get_min_hour(hour, GMT));
            return res;
        }

        if (GMT[1] == '?') {
            int start = GMT[0] == '-' ? 1 : 0;
            for (int i=start; i<10; ++i) {
                GMT[1] = i+'0';
                res = min(res, get_min_hour(hour, GMT));
            }
            return res;
        }

        int gmt = GMT[1] - '0';
        res = calc(conv(hour), gmt * (GMT[0]=='-'?-1:+1) );

        return res;
    }

    string fix(string time) {
        string hour = time.substr(0,2);
        string GMT = time.substr(9,2);
        string min = time.substr(3,2);

        for (int i=0; i<min.size(); ++i)
            if (min[i] == '?')
                min[i] = '0';

        string h = conv(get_min_hour(hour, GMT));
        return h + ":" + min;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "17:45 GMT-4"; string Arg1 = "21:45"; verify_case(0, Arg1, fix(Arg0)); }
    void test_case_1() { string Arg0 = "16:?? GMT??"; string Arg1 = "00:00"; verify_case(1, Arg1, fix(Arg0)); }
    void test_case_2() { string Arg0 = "?1:34 GMT-9"; string Arg1 = "06:34"; verify_case(2, Arg1, fix(Arg0)); }
    void test_case_3() { string Arg0 = "?4:00 GMT?1"; string Arg1 = "03:00"; verify_case(3, Arg1, fix(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    TheTriangleBothDivs ___test;

    ___test.run_test(3);

}

// END CUT HERE
