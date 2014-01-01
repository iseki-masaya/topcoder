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

const long long LINF = (1e15);
const int INF = (1<<28);
#define EPS 1e-6
const int MOD = 1000000009;

using namespace std;

class TheAlmostLuckyNumbersDivOne {

public:
    long long a,b,total;

    void rec(long long x,bool uAdded) {
        if (x <= b) {
            if (x >= a)
                ++total;

            if (!uAdded) {
                for (int d=1; d<10; ++d)
                    if (d != 4 && d != 7)
                        rec(x*10+d, true);
                if (x != 0)
                    rec(x*10, true);
            }

            rec(x*10 + 7, uAdded);
            rec(x*10 + 4, uAdded);
        }
    }

    long long find(long long a, long long b) {
        this->a = a;
        this->b = b;
        this->total = 0;
        rec(0, false);

        return total;
    }




};





// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
