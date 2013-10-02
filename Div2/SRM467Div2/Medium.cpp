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
#include <stdio.h>
#include <string.h>
#include <numeric>

#define INF (1<<28)

using namespace std;

class LateProfessor {

public:

    double
    getProbability(int waitTime, int walkTime, int lateTime, int bestArrival, int worstArrival)
    {
        int lateEnd = walkTime - lateTime;
        int t = waitTime;
        if (worstArrival == bestArrival) {
            while (t <= worstArrival) {
                for (int i=1; i<=lateEnd; ++i) {
                    if (t+i == bestArrival) {
                        return 1.0;
                    }
                }
                t = t + waitTime + walkTime;
            }
            return 0.0;
        }
        else {
            int s = 0;
            while (t < worstArrival) {
                for (int i=0; i<lateEnd; ++i) {
                    if (t+i >= bestArrival && t+i <worstArrival) {
                        s++;
                    }
                }
                t = t + waitTime + walkTime;
            }
            return (double)s/(worstArrival-bestArrival);
        }
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 20; int Arg1 = 30; int Arg2 = 10; int Arg3 = 0; int Arg4 = 50; double Arg5 = 0.4; verify_case(0, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_1() { int Arg0 = 20; int Arg1 = 30; int Arg2 = 10; int Arg3 = 30; int Arg4 = 100; double Arg5 = 0.42857142857142855; verify_case(1, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_2() { int Arg0 = 20; int Arg1 = 40; int Arg2 = 50; int Arg3 = 0; int Arg4 = 300; double Arg5 = 0.0; verify_case(2, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_3() { int Arg0 = 101; int Arg1 = 230; int Arg2 = 10; int Arg3 = 654; int Arg4 = 17890; double Arg5 = 0.6637270828498492; verify_case(3, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_4() { int Arg0 = 20; int Arg1 = 30; int Arg2 = 10; int Arg3 = 90; int Arg4 = 90; double Arg5 = 1.0; verify_case(4, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_5() { int Arg0 = 20; int Arg1 = 30; int Arg2 = 10; int Arg3 = 91; int Arg4 = 91; double Arg5 = 0.0; verify_case(5, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    LateProfessor ___test;

    ___test.run_test(-1);

}

// END CUT HERE
