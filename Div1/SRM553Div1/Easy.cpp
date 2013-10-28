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

#define INF (1<<30)
#define EPS 1e-8
#define MOD 100000000

using namespace std;

class Suminator {

public:
    long long
    simulate(vector<int> &p)
    {
        stack<long long> st;
        st.push(0);
        st.push(0);
        int N = (int)p.size();
        for (int i=0; i<N; ++i) {
            if (p[i] == 0) {
                long long a = st.top();
                if (st.size() != 1) st.pop();
                long long b = st.top();
                if (st.size() != 1) st.pop();
                st.push(a+b);
            }
            else {
                st.push(p[i]);
            }
        }
        return st.top();
    }

    int
    findMissing(vector <int> program, int wantedResult)
    {
        int N = (int)program.size();
        int p = 0;
        for (int i=0;i<N;++i)
            if (program[i] == -1)
                p = i;
        program[p] = 0;
        if (simulate(program) == wantedResult) {
            return 0;
        }

        int lb = 0 , ub = INF;
        while (ub - lb > 1) {
            int mid = (ub+lb)/2;
            program[p] = mid;
            if (simulate(program) - wantedResult > 0) {
                ub = mid;
            }
            else {
                lb = mid;
            }
        }
        if (lb == 0 || ub == INF) {
            return -1;
        }
        return lb;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {7,-1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 3; verify_case(0, Arg2, findMissing(Arg0, Arg1)); }
    void test_case_1() { int Arr0[] = {100, 200, 300, 0, 100, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 600; int Arg2 = 0; verify_case(1, Arg2, findMissing(Arg0, Arg1)); }
    void test_case_2() { int Arr0[] = {-1, 7, 3, 0, 1, 2, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; int Arg2 = 0; verify_case(2, Arg2, findMissing(Arg0, Arg1)); }
    void test_case_3() { int Arr0[] = {-1, 8, 4, 0, 1, 2, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; int Arg2 = -1; verify_case(3, Arg2, findMissing(Arg0, Arg1)); }
    void test_case_4() { int Arr0[] = {1000000000, 1000000000, 1000000000,  1000000000, -1, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; int Arg2 = -1; verify_case(4, Arg2, findMissing(Arg0, Arg1)); }
    void test_case_5() { int Arr0[] = {7, -1, 3, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = -1; verify_case(5, Arg2, findMissing(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    Suminator ___test;

    ___test.run_test(-1);

}

// END CUT HERE
