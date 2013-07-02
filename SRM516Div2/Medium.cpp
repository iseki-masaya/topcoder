#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <set>
#include <bitset>

#define FILE

using namespace std;

#define MAX 51

class NetworkXOneTimePad {
	string
	Xor(string lhs,string rhs)
	{
		string ans;
		for (int i=0; i<lhs.size(); ++i) {
			ans += lhs[i] == rhs[i] ? '0' : '1';
		}
		return ans;
	}

public:
	int crack(vector <string> plaintexts, vector <string> ciphertexts)
	{
		set<string> ret;
		for (int i=0; i<plaintexts.size(); ++i) {
			for (int j=0; j<ciphertexts.size(); ++j) {
				ret.insert(Xor(plaintexts[i], ciphertexts[j]));
			}
		}

		int ans = 0;
		for	(set<string>::iterator it=ret.begin(),ed=ret.end();
				 it != ed ; ++it) {
			set<string> mul;
			bool isOk = true;
			for (int i=0; i<plaintexts.size(); ++i) {
				mul.insert(Xor(*it, plaintexts[i]));
			}
			for (int i=0; i<ciphertexts.size(); ++i) {
				if (mul.find(ciphertexts[i]) == mul.end()) {
					isOk = false;
					break;
				}
			}
			if (isOk) {
				++ans;
			}
			mul.clear();
		}

		return ans;
	}
};