#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstdio>

using namespace std;

int dp[52] = {0};

class P8XGraphBuilder {
public:
	int solve(vector <int> scores)
	{
		int node = static_cast<int>(scores.size())+1;

		for (int i=0;i<=node;++i)
			dp[1+(i+1)] = scores[i] + scores[0]*(i+1);

		for (int i=2; i<=node; ++i) {
			for (int j=0; j<scores.size(); ++j) {
				int k=i+j;
				if(k>node) break;
				dp[k] =  max(dp[k],dp[i]+scores[j]+(j-1)*scores[0]);
			}
		}

		return dp[node];
	}
};