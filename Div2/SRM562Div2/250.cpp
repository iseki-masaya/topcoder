#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CucumberMarket
{
public:
	vector<int> gPrice;
	int gBudget;
	int gReqNum;
	int size;
	
	bool checkBuy(int pos,int sum,int depth)
	{
		//terminate condition
		if(sum > gBudget)
			return false;
		if(depth >= gReqNum)
			return true;
		if(pos >= size)
			return true;
		
		sum += gPrice.at(pos);
		
		for(int i=pos+1;i<size+1;++i) {
			if(!checkBuy(i, sum, depth+1))
				return false;
		}
		
		return true;
	}
	
	string check(vector <int> price, int budget, int k)
	{
		gPrice = price;
		gBudget = budget;
		gReqNum = k;
		size = (int)price.size();
		
		for (int i=0; i<price.size(); ++i) {
			if(!checkBuy(i,0,0))
				return "NO";
		}
		
		return "YES";
	}
};