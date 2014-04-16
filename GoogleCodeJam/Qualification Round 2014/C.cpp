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

vector<string> calc(int R, int C, int M) {
    int mn = min(R, C);
    int mx = max(R, C);
    int safe = R*C - M;
    if (mn != 1 && (safe == 2 || safe == 3 || safe == 5 || safe == 7) ) {
    return vector<string>();
    }
    if (mn == 2 && safe != 1 && safe&1) {
    return vector<string>();
    }

    vector<string> ans(R, string(C,'*'));
    int len = 1;
    while (len * min(mn, len) < safe) {
    ++len;
    }
    ans[0][0] = 'c';
    --safe;
    for (int x=0; x<min(len,C) && safe > 0; ++x) {
    for (int y=0; y<min(len,R) && safe > 0; ++y) {
            if (x == 0 && y == 0)
                continue;
            ans[y][x] = '.';
            --safe;
            if (mn > 2 && safe == 0 && y == 0) {
                ans[y+1][x] = '.';
                ans[min(len,R)-1][x-1] = '*';
            }
        }
    }
    return ans;
}

int main() {
    ifstream ifs("/GoogleCodeJam/dat.txt");
    int Number;
    ifs >> Number;
    for (int i=1; i<=Number; ++i) {
    int R,C,M;
        ifs >> R >> C >> M;
        vector<string> ans(calc(R, C, M));
        printf("Case #%d:\n", i);
        if (!ans.empty()) {
            for (string str : ans)
                cout << str << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}