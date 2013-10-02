#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class FoxAndVacation
{
public:
	int maxCities(int total, vector <int> d)
	{
		sort(d.begin(), d.end());
		int cnt = 0,sum = 0,pos = 0;
		int size = (int)d.size();
		while(sum < total){
			if(pos == size)
				break;
			sum += d.at(pos);
			++pos;
			++cnt;
		}
		
		if(sum > total)
			--cnt;
		
		return cnt;
	}
};