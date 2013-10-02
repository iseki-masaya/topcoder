#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class CasketOfStarEasy {
public:
	int maxEnergy(vector <int> weight)
	{
		int n = static_cast<int>(weight.size());
		vector<int> p;
		for(int i=1;i<n-1;++i)
			p.push_back(i);

		int mx = 0;
		bool memo[10] = {false};
		do {

			int res = 0;
			for (int i=0; i<p.size(); ++i) {

				memo[p.at(i)] = true;
				int left = 0;
				for (int l=p.at(i)-1; l>0; --l) {
					if (!memo[l]) {
						left = l;
						break;
					}
				}
				int right = n-1;
				for (int r=p.at(i)+1; r<n; ++r) {
					if (!memo[r]) {
						right = r;
						break;
					}
				}
				res += weight[left]*weight[right];
			}

			mx = max(mx,res);
			for(int i=0;i<n;++i)
				memo[i] = false;
		} while (next_permutation(p.begin(), p.end()));

		return mx;
	}
};