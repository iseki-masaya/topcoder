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

// sort:O(N log N) search:O(N)
int deceitfulWar(vector<int> Naomi, vector<int> Ken) {
    sort(Naomi.begin(), Naomi.end(), greater<int>());
    sort(Ken.begin(), Ken.end(), greater<int>());
    int N = (int)Naomi.size();
    int res = 0;
    int n = N;
    int j = 0;
    for (int i=0; i<n && j<N; ++i,++j) {
    if (Naomi[i] > Ken[j])
            ++res;
        else
            --i, --n;
    }
    return res;
}

// sort:O(N log N) search:O(N)
int war(vector<int> Naomi, vector<int> Ken) {
    sort(Naomi.begin(), Naomi.end());
    sort(Ken.begin(), Ken.end());
    int N = (int)Naomi.size();
    int res = 0;
    int j = 0;
    for (int i=0; i<N && j<N; ++i,++j) {
        while (j < N && Naomi[i] > Ken[j]) {
            ++res;
            ++j;
        }
    }
    return res;
}

pair<int, int> calc(vector<int> &Naomi, vector<int> &Ken) {
    return pair<int, int>( deceitfulWar(Naomi, Ken), war(Naomi, Ken) );
}

int main() {
    ifstream ifs("/GoogleCodeJam/dat.txt");
    int Number;
    ifs >> Number;
    const int SIZE = 1000000;
    for (int i=1; i<=Number; ++i) {
        int N;
        ifs >> N;
        vector<int> Naomi(N),Ken(N);
        double v;
        for (int i=0; i<N; ++i) {
            ifs >> v;
            Naomi[i] = SIZE*v;
        }
        for (int i=0; i<N; ++i) {
            ifs >> v;
            Ken[i] = SIZE*v;
        }
        pair<int, int> p = calc(Naomi, Ken);
        printf("Case #%d: %d %d\n",i, p.first, p.second);
    }
    return 0;
}