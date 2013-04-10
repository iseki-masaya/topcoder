#include <vector>
#include <string>
#include <map>

using namespace std;

class CityMap
{
public:
	string getAllStr(vector<string> cityMap)
	{
		string str = "";
		string tmpStr;
		for (vector<string>::iterator cit = cityMap.begin() ; cit != cityMap.end(); ++cit) {
			tmpStr = *cit;
			for (int i=0; i<tmpStr.size(); ++i) {
				if (str.find(tmpStr[i]) == string::npos) {
					str += tmpStr[i];
				}
			}
		}
		return str;
	}
	
	void initial(map<char, int>& list,string allStr)
	{
		for (int i=0; i<allStr.size(); ++i) {
			list[allStr[i]] = 0;
		}
	}
	
	int getCount(vector<string> cityMap,char key)
	{
		int count=0;
		string tmpStr;
		for (vector<string>::iterator cit = cityMap.begin() ; cit != cityMap.end(); ++cit) {
			tmpStr = *cit;
			for (int i=0; i<tmpStr.size(); ++i) {
				if (tmpStr[i] == key) {
					++count;
				}
			}
		}
		return count;
	}
	
	string getLegend(vector<string> cityMap, vector<int> POIs)
	{
		string legend = "";
		string allStr = getAllStr(cityMap);
		map<char, int> list;
		initial(list,allStr);
		for (int i=0; i<allStr.size(); ++i) {
			list[allStr[i]] = getCount(cityMap, allStr[i]);
		}
		for (vector<int>::iterator itPOIs = POIs.begin(); itPOIs != POIs.end(); ++itPOIs) {
			for (map<char, int>::iterator itList = list.begin(); itList != list.end(); ++itList) {
				if ((*itList).second == *itPOIs) {
					legend += (*itList).first;
				}
			}
		}
		
		return legend;
	}
};