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

using namespace std;

int calc(int l1, vector<vector<int> > &a, int l2, vector<vector<int> > &b ) {
    vector<int> c,d;
    for (int i=0; i<4; ++i) {
    c.push_back(a[l1][i]);
        d.push_back(b[l2][i]);
    }
    int ans = -1;
    for (int i=0; i<4; ++i) {
        vector<int>::iterator p;
    if ( ( p = find(d.begin(), d.end(), c[i]) ) != d.end()) {
            if (ans != -1) {
                return -2;
            }
            ans = *p;
        }
    }
    return ans;
}

int main() {
    ifstream ifs("/GoogleCodeJam/dat.txt");
    int Number;
    ifs >> Number;
    for (int i=1; i<=Number; ++i) {
        int l1,l2;
        vector<vector<int> > a(4,vector<int>(4)), b(4,vector<int>(4));
        for (int i=0; i<2; ++i) {
            ifs >> (i ? l1 : l2);
            vector<vector<int> > &c = i ? a : b;
            for (int j=0; j<4; ++j) {
                for (int k=0; k<4; ++k) {
                    ifs >> c[j][k];
                }
            }
        }
        int ans = calc(l1-1, a, l2-1, b);
        if (ans == -2)
            printf("Case #%d: Bad magician!\n", i);
        else if (ans == -1)
            printf("Case #%d: Volunteer cheated!\n", i);
        else
            printf("Case #%d: %d\n", i, ans);
    }
    return 0;
}