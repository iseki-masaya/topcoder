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

class RowAndCoins {

public:

    string getWinner(string cells) {
        int alice = 0 , bob = 0;

        int idx = 0;
        int N = (int)cells.size();
        while (idx < N) {
            char current = cells[idx];
            while (idx < N && current == cells[idx]) ++idx;
            current == 'A' ? ++alice : ++bob;
        }

        return alice >= bob ? "Alice" : "Bob";
    }




};