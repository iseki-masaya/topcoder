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

const long long LINF = (5e18);
const int INF = (1<<29);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class OlympicCandles {

public:

    int numberOfNights(vector <int> candles) {
        int ans = 1;
        sort(candles.rbegin(), candles.rend());
        while (true) {
            bool canCelebrate = true;
            if (ans > candles.size())
                break;
            for (int i=0; i<ans; ++i) {
                if (candles[i]>0)
                    candles[i]--;
                else
                    canCelebrate = false;
            }
            if (!canCelebrate)
                break;
            sort(candles.rbegin(), candles.rend());
            ++ans;
        }
        return ans-1;
    }




};





// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
