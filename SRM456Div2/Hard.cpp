#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>

using namespace std;

class CutSticks
{
public:
	double maxKth(vector <int> sticks, int C, int K)
	{
		double mid,left=0,right=1e9;
		long int cnt = 0;
		int count = 0;
		long int work;

		for (int i=0; i<100; ++i) {
			cnt = 0;
			count = 0;
			mid = (left+right)/2.0;

			for (int j=0; j<sticks.size(); ++j) {
				if (C==count && static_cast<double>(sticks.at(j)) >= mid) {
					++cnt;
				}
				else {
					if (static_cast<int>((sticks.at(j)/mid)-1) <= C-count) {
						work = static_cast<long int>(sticks.at(j)/mid);
						cnt += work;
						--work;
					}
					else {
						work = static_cast<long int>(C-count);
						cnt += work+1;
					}

					if (work >= 1)
						count += static_cast<int>(work);
				}
			}

			if (cnt >= K) {
				left = mid;
			}
			else {
				right = mid;
			}
		}

		return right;
	}
};