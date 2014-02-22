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

class Starport {

public:
    int gcd(int a, int b) {
        if (a < b) swap(a, b);
        while (b > 0) {
            int c = b;
            b = a%b;
            a = c;
        }
        return a;
    }

    double getExpectedTime(int N, int M) {
        int x = (N - (M%N))%N;
        int y = gcd(N, x);
        return (N - y) / 2.0;
    }




};





// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
