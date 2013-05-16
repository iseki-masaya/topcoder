#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <vector>

using namespace std;

class StockHistory
{
public:
	int maximumEarnings(int initialInvestment, int monthlyContribution, vector <string> stockPrices)
	{
		int money = initialInvestment;
		int month = static_cast<int>(stockPrices.size());
		int corp = 1;
		char *s = (char*)(stockPrices[0].c_str());
		while(*s++) if(*s == ' ') ++corp;
		
		int prices[50][1000];
		double profit = 0,max = 0;
		bool buy[50] = {false};
		double proportion[50] = {0};
		for (int i =0; i < month ; ++i) {
			string s = stockPrices.at(i);
			for (int j=0; j<corp; ++j) {
				int pos=static_cast<int>(s.find(" "));
				if (pos == string::npos) {
					prices[i][j] = atoi(s.c_str());
				}
				else {
					prices[i][j] = atoi(s.c_str());
					s = s.substr(pos+1,s.size()).c_str();
				}
			}
		}
		
		for (int i = month - 2; i >= 0; --i) {
			for (int j=0; j<corp; ++j) {
				double p = 1.0*prices[month-1][j]/prices[i][j] - 1;
				if (0 < p && max < p) {
					buy[i] = true;
					max = p;
					proportion[i] = p;
				}
			}
		}
		
		for (int i=0; i<month; ++i) {
			if (buy[i]) {
				profit += money * proportion[i];
				money = 0;
			}
			money += monthlyContribution;
		}
		
		return static_cast<int>(round(profit));
	}
};