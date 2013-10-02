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

#define MAX_S 60000000000
#define INF (1<<30)

using namespace std;

class PerfectSequences {
public:
	string
	fixIt(vector <int> seq)
	{
		if (seq.size()==1) {
			return "Yes";
		}

		long long max = 0;
		for (int i=0; i<seq.size(); ++i) {
			max += 2000000000;
		}

		sort(seq.begin(), seq.end());
		if (seq[1] < 0) {
			return "No";
		}
		for (int del=0; del<seq.size(); ++del) {
			if (seq[0] < 0 && del!= 0) {
				continue;
			}

			long long p = 1;
			for (int i=0; i<seq.size(); ++i) {
				if (del != i) {
					p = (p*seq[i])<max ? p*seq[i] : -1;
				}
			}

			long long S = 0;
			for (int i=0; i<seq.size(); ++i) {
				if (del != i) {
					S += seq[i];
				}
			}

			if (p >= 0 && p != 1 && S%(p-1)==0) {
				if (S/(p-1) == seq[del] || (p==0&&S!=0)) {
					continue;
				}
				return "Yes";
			}
		}
		return "No";
	}
};