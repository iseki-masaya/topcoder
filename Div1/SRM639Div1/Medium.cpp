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
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <cstdio>
//#include <cstdlib>
#include <cstring>
#include <numeric>
#include <bitset>
#include <deque>
#include <memory>

const long long LINF = (5e17);
const int INF = 1000000000;
#define EPS 1e-7
const int MOD = 1000000007;

using namespace std;

class BoardFolding {

public:

    int toNumber(char ch) {
        if ('0' <= ch && ch <= '9')
            return ch - '0';
        else if('a' <= ch && ch <= 'z')
            return ch - 'a' + 10;
        else if('A' <= ch && ch <= 'Z')
            return ch - 'A' + 36;
        else if (ch == '#')
            return 62;
        else if (ch == '@')
            return 63;
        cout << ch << endl;
        return -1;
    }

    vector<vector<int> > rotate(const vector<vector<int> > &paper) {
        int w = (int)paper.size();
        int h = (int)paper[0].size();
        vector<vector<int> > res(h, vector<int>(w));
        for (int i=0; i<h; ++i)
            for (int j=0; j<w; ++j)
                res[i][j] = paper[j][i];
        return res;
    }

    vector<vector<int> > flip(vector<vector<int> > paper) {
        int top = 0, bottom = (int)paper.size() - 1;
        while (top < bottom)
            swap(paper[top++], paper[bottom--]);
        return paper;
    }

    vector<bool> countTop(const vector<vector<int> > &paper) {
        int h = (int)paper.size();
        int w = (int)paper[0].size();
        vector<vector<bool> > equalRow(h, vector<bool>(h,true));
        for (int i=0; i<h; ++i)
            for (int j=i+1; j<h; ++j)
                for (int k=0; k<w; ++k)
                    equalRow[i][j] = equalRow[i][j] & (paper[i][k] == paper[j][k]);
        vector<bool> canRemove(h, false);
        canRemove[0] = true;
        for (int base=0; base<h; ++base) {
            if (canRemove[base]) {
                for (int size=1; base + 2*size - 1 < h; ++size) {
                    bool canFold = true;
                    for (int top = base, bottom = base + 2*size -1; top<bottom; ++top, --bottom)
                        if (!equalRow[top][bottom])
                            canFold = false;
                    if (canFold)
                        canRemove[base + size] = true;
                }
            }
        }
        return canRemove;
    }

    int count(const vector<vector<int> > &paper) {
        vector<bool> top(countTop(paper));
        vector<bool> bottom(countTop(flip(paper)));

        int res = 0;
        for (int t=0; t<paper.size(); ++t)
            for (int b=0; t + b < paper.size(); ++b)
                if (top[t] && bottom[b])
                    ++res;

        return res;
    }

    int howMany(int N, int M, vector <string> compressedPaper) {
        vector<vector<int> > paper(N,vector<int>(M));
        for (int i=0; i<N; ++i)
            for (int j=0; j<M; ++j)
                paper[i][j] = ( toNumber(compressedPaper[i][j / 6]) >> (j%6) )%2;

        int resH = count(paper);
        int resW = count(rotate(paper));
        return resW * resH;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 2; int Arg1 = 2; string Arr2[] = {"1", "3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, howMany(Arg0, Arg1, Arg2)); }
    void test_case_1() { int Arg0 = 2; int Arg1 = 7; string Arr2[] = {"@@", "@@"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 84; verify_case(1, Arg3, howMany(Arg0, Arg1, Arg2)); }
    void test_case_2() { int Arg0 = 4; int Arg1 = 4; string Arr2[] = {"6", "9", "9", "6"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 9; verify_case(2, Arg3, howMany(Arg0, Arg1, Arg2)); }
    void test_case_3() { int Arg0 = 6; int Arg1 = 1; string Arr2[] = {"0", "2", "6", "@", "4", "A"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(3, Arg3, howMany(Arg0, Arg1, Arg2)); }
    void test_case_4() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {"0", "2", "0"}
        ; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(4, Arg3, howMany(Arg0, Arg1, Arg2)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    BoardFolding ___test;

    ___test.run_test(-1);

}

// END CUT HERE
