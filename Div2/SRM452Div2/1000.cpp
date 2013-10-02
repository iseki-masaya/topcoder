#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool path[50] = {false};

class HamiltonPath
{
public:
	bool isBranch(const vector <string> &roads)
	{
		for (vector<string>::const_iterator it = roads.begin(),end = roads.end();
				 it != end; ++it) {
			int cnt = 0;
			for (int i=0; i<(*it).size(); ++i) {
				if ((*it).at(i) == 'Y') {
					++cnt;
				}
				if (cnt > 2) {
					return true;
				}
			}
		}
		
		return false;
	}
	
	void traceRoute(const vector <string> &roads,int record,int nowRec)
	{
		int sizeCur = static_cast<int>(roads.at(0).size());
		path[record] = true;
		
		int cnt = 0;
		int targetRec = -1;
		for (int cur=0; cur<sizeCur; ++cur) {
			if (roads.at(record).at(cur) == 'Y') {
				++cnt;
				if (cur != nowRec) {
					targetRec = cur; // if it is not target, it will discard by cnt check
				}
			}
		}
		
		if (cnt == 2) {
			traceRoute(roads, targetRec, record);
		}
		else if (cnt == 0) {
			return;
		}
		return;
	}
	
	long long int factorial(int n)
	{
		long long int sum = 1;
		for (int i = n; i>=1; --i) {
			sum *= i;
		}
		return sum;
	}
	
	int getPath(vector <string> roads)
	{
		int sizeRec = static_cast<int>(roads.size());
		int sizeCur = static_cast<int>(roads.at(0).size());
		int nodeNum = 0;
		int freeNodeNum = 0;
		
		int targetRec = -1;
		for (int record=0;record<sizeRec;++record) {
			int cnt = 0;
			for (int cur=0; cur<sizeCur; ++cur) {
				if (roads.at(record).at(cur) == 'Y') {
					targetRec = cur;
					++cnt;
				}
			}
			if (cnt == 0) {
				++freeNodeNum;
				path[record] = true;
			}
			else if (cnt == 1 && !path[record]) {
				path[record] = true;
				traceRoute(roads, targetRec, record);
				++nodeNum;
			}
		}
		
		for (int record=0; record<sizeRec; ++record) {
			if (!path[record]) {
				return -1; //there is cycle
			}
		}
		
		long long int sum = 1;
		for (int i=freeNodeNum+nodeNum; i>1; --i) {
			sum = (sum * i) % 1000000007;
		}
		for (int i=0; i<nodeNum; ++i) {
			sum = (sum * 2) % 1000000007;
		}
		
		return static_cast<int>(sum);
	}
	
	int countPaths(vector <string> roads)
	{
		if(isBranch(roads)) {
			return 0;
		}
		
		int ret = getPath(roads);
		if (ret == -1) {
			return 0;
		}
		
		return ret;
	}
};