#include <vector>
#include <iostream>
#include <memory>

using namespace std;

class BinaryPolynomialDivTwo {
public:
	int countRoots(vector <int> a)
	{
		int ans = 0;
		if(a.at(0) == 0) ++ans;

		int cnt = 0;
		for(int i=0;i<a.size();++i)
			if(a.at(i)==1)
				++cnt;

		if(cnt%2==0)
			++ans;
		return ans;
	}
};