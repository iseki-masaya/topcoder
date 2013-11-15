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
#include <numeric>
#include <stdio.h>
#include <string.h>

#define INF (1<<28)
#define LINF (1e17)

using namespace std;

class EllysCheckers {

public:

    string getWinner(string board) {
        int N = (int)board.size();
        int sum = 0;
        for (int i=0; i<N; ++i) {
            if (board[i] == 'o') {
                sum += N-(i+1);
            }
        }
        return sum&1 ? "YES" : "NO";
    }




};





// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
