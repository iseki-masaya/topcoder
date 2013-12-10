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

class NetworkXOneTimePad {

public:
    long long conv(string bit) {
        int N = (int)bit.size();

        long long res = 0;
        for (int i=0; i<N; ++i)
            res += bit[i] == '1' ? (1LL<<i) : 0;

        return res;
    }

    bool is_ok(vector<long long> &p, vector<long long> &c, long long key) {
        int M = (int)c.size();

        for (int i=0; i<M; ++i) {
            long long decrypt = c[i] ^ key;
            if (find(p.begin(), p.end(), decrypt) == p.end()) {
                return false;
            }
        }

        return true;
    }

    int crack(vector <string> plaintexts, vector <string> ciphertexts) {
        int N = (int)plaintexts.size();
        int M = (int)ciphertexts.size();

        vector<long long> p,c;
        for (int i=0; i<N; ++i) {
            p.push_back(conv(plaintexts[i]));
        }
        for (int i=0; i<M; ++i) {
            c.push_back(conv(ciphertexts[i]));
        }

        set<long long> ans;
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                long long key = p[i] ^ c[j];
                if (is_ok(p, c, key))
                    ans.insert(key);
            }
        }

        return (int)ans.size();
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"110", "001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"101", "010"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, crack(Arg0, Arg1)); }
    void test_case_1() { string Arr0[] = {"00", "01", "10", "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00", "01", "10", "11"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, crack(Arg0, Arg1)); }
    void test_case_2() { string Arr0[] = {"01", "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, crack(Arg0, Arg1)); }
    void test_case_3() { string Arr0[] = {"11111111111111111111111111111111111111111111111111", "11111111111111111111111111111111111111110111111111", "11111111111111111111111110111111111111111111011111", "11111111111111111111110111111111111111111110111011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"11111111111111111111111011111111111111111011111111"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(3, Arg2, crack(Arg0, Arg1)); }
    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    NetworkXOneTimePad ___test;

    ___test.run_test(3);

}

// END CUT HERE
