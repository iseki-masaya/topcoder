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

const long long LINF = (1e11);
const int INF = (1<<28);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class RotatedClock {

public:

    bool is_possible(int h_ang,int m_ang) {
        int ht = (2 * h_ang)%360;
        if (m_ang % 6 != 0)
            return false;
        int mt = m_ang/6;

        if (ht%60 == mt) {
            return true;
        }
        return false;
    }

    string disp(int h,int m) {
        stringstream ss;

        string hour;
        ss << (h/30);
        ss >> hour;
        if ( (h/30) < 10) {
            char tmp = hour[0];
            hour = '0';
            hour += tmp;
        }
        ss.clear();

        string minute;
        ss << m/6;
        ss >> minute;
        if ( (m/6) < 10) {
            char tmp = minute[0];
            minute = '0';
            minute += tmp;
        }

        return hour + ':' + minute;
    }

    string getEarliest(int hourHand, int minuteHand) {
        for (int i=0; i <= 360; i += 30) {
            int h = (hourHand + i + 360)%360;
            int m = (minuteHand + i + 360)%360;
            if (is_possible(h,m)) {
                return disp(h,m);
            }
        }

        return "";
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 70; int Arg1 = 300; string Arg2 = "08:20"; verify_case(0, Arg2, getEarliest(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 90; int Arg1 = 120; string Arg2 = "11:00"; verify_case(1, Arg2, getEarliest(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 240; int Arg1 = 36; string Arg2 = ""; verify_case(2, Arg2, getEarliest(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 19; int Arg1 = 19; string Arg2 = ""; verify_case(3, Arg2, getEarliest(Arg0, Arg1)); }
    void test_case_4() { int Arg0 = 1; int Arg1 = 12; string Arg2 = "00:02"; verify_case(4, Arg2, getEarliest(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    RotatedClock ___test;

    ___test.run_test(-1);

}

// END CUT HERE
