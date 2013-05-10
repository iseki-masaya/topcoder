#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BadNeighbors
{
public:
	int max;
	bool isFirst;
	vector<int> elem;
	
	void getSome(int pos,int sum)
	{
		//terminate condition
		if(pos >= elem.size() || (pos == elem.size()-1 && isFirst)){
			if(max < sum){
				max = sum;
			}
			return;
		}

		//
		sum += elem.at(pos);
		
		getSome(pos+2,sum);
		getSome(pos+3,sum);
	}
	
	int maxDonations(vector <int> donations)
	{
		elem = donations;
		max = 0;
		isFirst = true;
		getSome(0, 0);
		isFirst = false;
		getSome(1, 0);
		getSome(2, 0);
		int ret = max;
		return ret;
	}
};