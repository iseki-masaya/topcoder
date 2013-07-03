#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <sstream>
#include <set>
#include <cmath>
#include <map>

#define I_INF (1<<20)
#define F_INF 1e7
#define MAX 101

using namespace std;

class GameOfLifeDivTwo {
public:
  string theSimulation(string init, int T)
	{
		for (int t=0; t<T; ++t) {
			string work;
			for (int i=0; i<init.size(); ++i) {
				int l = i-1>=0 ? i-1 : (int)init.size()-1;
				int r = i+1<init.size() ? i+1 : 0;
				vector<int> pos;
				pos.push_back(l);
				pos.push_back(r);
				pos.push_back(i);
				int st = 0;
				for (int j=0; j<pos.size(); ++j) {
					st += init[pos[j]]=='0'?1:-1;
				}
				if (st > 0) {
					work.push_back('0');
				}
				else {
					work.push_back('1');
				}
			}
			init = work;
		}
		return init;
	}
};