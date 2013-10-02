#include <iostream>
#include <vector>
#include <string>

using namespace std;

class GreatFairyWar
{
public:
	int getSumDps(int pos,int size,vector <int> dps)
	{
		int sumDps = 0;
		for (int i=pos; i<size; ++i) {
			sumDps += dps.at(i);
		}
		return sumDps;
	}
	
	int minHP(vector <int> dps, vector <int> hp)
	{
		int sumHP = 0;
		int size = (int)dps.size();
		for (int i=0; i<size; ++i) {
			sumHP += hp.at(i) * getSumDps(i,size,dps);
		}
		return sumHP;
	}
};