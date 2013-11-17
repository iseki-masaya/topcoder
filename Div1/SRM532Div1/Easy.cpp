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

#define INF (1<<30)
#define LINF (1e17)

using namespace std;

class DengklekMakingChains {
	
public:
	int maxBeauty(vector <string> chains) {
		int N = (int)chains.size();
		vector<int> prefix(2,0),suffix(2,0);
		int single = 0;
		int ans = 0;
		
		for (int i=0; i<N; ++i) {
			for (int j=0;j<3;++j)
				if (chains[i][j] != '.')
					single = max(single, chains[i][j]-'0');
			
			int sum = 0;
			bool f = true;
			for (int j=0; j<3; ++j) {
				f = f && chains[i][j] != '.';
				if (!f) break;
				sum += chains[i][j] - '0';
			}
			if (f) {
				ans += sum;
				continue;
			}
			prefix.push_back(sum);
			
			sum = 0;
			for (int j=2; j>=0; --j) {
				if (chains[i][j] == '.') break;
				sum += chains[i][j] - '0';
			}
			suffix.push_back(sum);
		}
		
		int M = (int)prefix.size();
		for (int i=0;i<M;++i)
			for (int j=0;j<M;++j) if (i!=j)
				single = max(single,ans+prefix[i]+suffix[j]);
		
		return single;
	}
	
	
	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".15", "7..", "402", "..3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(0, Arg1, maxBeauty(Arg0)); }
	void test_case_1() { string Arr0[] = {"..1", "7..", "567", "24.", "8..", "234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; verify_case(1, Arg1, maxBeauty(Arg0)); }
	void test_case_2() { string Arr0[] = {"...", "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, maxBeauty(Arg0)); }
	void test_case_3() { string Arr0[] = {"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(3, Arg1, maxBeauty(Arg0)); }
	void test_case_4() { string Arr0[] = {"..1", "3..", "2..", ".7."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, maxBeauty(Arg0)); }
	void test_case_5() { string Arr0[] = {"..1", "9.8", "567", "24.", "8.6", ".42"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 34; verify_case(5, Arg1, maxBeauty(Arg0)); }
	
	// END CUT HERE
	
	
};



// BEGIN CUT HERE

int main() {
	
	DengklekMakingChains ___test;
	
	___test.run_test(-1);
	
}

// END CUT HERE
