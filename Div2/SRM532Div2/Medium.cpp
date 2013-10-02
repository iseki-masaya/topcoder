#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cstring>

using namespace std;

#define eprintf printf
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

class DengklekMakingChains {
public:
  int maxBeauty(vector <string> chains) {
    int ans = 0;
    vi sufs(2, 0), prefs(2, 0);
    int bres = 0;

    for (int i = 0; i < sz(chains); i++) {
      for (int i2 = 0; i2 < 3; i2++)
        if (chains[i][i2] != '.')
          bres = max(bres, chains[i][i2] - '0');

      bool g = true;
      int sum = 0;
      for (int i2 = 0; i2 < 3; i2++) { //111 or 11. 1.. 1.1
        g = g && chains[i][i2] != '.';
        if (!g) break;
        sum += chains[i][i2] - '0';
      }
      if (g) { ans += sum; continue; }
      prefs.pb(sum);

      sum = 0;
      for (int i2 = 2; i2 >= 0; i2--) { //1.1 .11 ..1
        if (chains[i][i2] == '.') break;
        sum += chains[i][i2] - '0';
      }
      sufs.pb(sum);
    }
    for (int a = 0; a < sz(sufs); a++)
			for (int b = 0; b < sz(prefs); b++) if (a != b)
				bres = max(bres, sufs[a] + prefs[b] + ans);
    return bres;
  }
};