#include <vector>
#include <algorithm>

using namespace std;

class TheSwapsDivTwo
{
public:
	int permination(int start,int end)
	{
		int sum=1;
		for (int i=start; i>end; --i) {
			sum *= i;
		}
		return sum;
	}
	int selectSmallR(int large,int small)
	{
		int ret;
		ret = large - small;
		if(ret < large/2)
		{
			ret = large - ret;
		}
		return ret;
	}
	int find(vector<int> sequence)
	{
		int ret;
		int n = (int)sequence.size();
		
		ret = permination(n, n-2)/2;
		
		sort(sequence.begin(), sequence.end());
		sequence.erase(unique(sequence.begin(), sequence.end()),sequence.end());
		int r = (int)sequence.size();
		if(r != 1) {
			r = n - r;
		}
		else{
			ret = 1;
		}
	
		if (r > 1) {
			ret -= r;
		}

		return ret;
	}
};