#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <sstream>
#include <set>

#define INF (1<<20)
#define MAX 101

using namespace std;

class FortunateNumbers {
public:
  int getFortunate(vector <int> a, vector <int> b, vector <int> c)
	{
		set<string> strset;
		stringstream ss;
		int work;
		string str;
		for (int i=0; i<a.size(); ++i) {
			for (int j=0; j<b.size(); ++j) {
				for (int k=0; k<c.size(); ++k) {
					work = a[i] + b[j] + c[k];
					ss << work;
					ss >> str;
					bool isFortune = true;
					for (int i=0; i<str.size(); ++i) {
						if (str[i] != '5' && str[i] != '8') {
							isFortune = false;
							break;
						}
					}
					if (isFortune) {
						strset.insert(str);
					}
					ss.clear();
				}
			}
		}

		return static_cast<int>(strset.size());
	}
};