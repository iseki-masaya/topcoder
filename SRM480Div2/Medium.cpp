#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class InternetSecurity {
	int countDword(string keyword,vector <string> &dangerous,vector<string> &candidate)
	{
		string str;
		size_t pos = keyword.find(" ");
		int cnt = 0;
		while (pos != string::npos) {
			str = keyword.substr(0,pos);
			if (find(dangerous.begin(), dangerous.end(), str) != dangerous.end()) {
				++cnt;
			}
			else {
				candidate.push_back(str);
			}

			keyword = keyword.substr(pos+1,keyword.size());
			pos = keyword.find(" ");
		}
		if (find(dangerous.begin(), dangerous.end(), keyword) != dangerous.end()) {
			++cnt;
		}
		else {
			candidate.push_back(keyword);
		}

		return cnt;
	}
public:
	vector <string> determineWebsite(vector <string> address, vector <string> keyword, vector <string> dangerous, int threshold)
	{
		vector<string> ans;
		int dnum = 0;

		bool isChanged = true;
		while (isChanged) {
			isChanged = false;
			for (int i=0; i<address.size(); ++i) {
				vector<string> candidate;
				dnum = countDword(keyword.at(i), dangerous,candidate);
				if (dnum >= threshold) {
					for (int j=0; j<candidate.size(); ++j) {
						isChanged = true;
						dangerous.push_back(candidate.at(j));
					}
				}
			}
		}

		for (int i=0; i<address.size(); ++i) {
			vector<string> candidate;
			dnum = countDword(keyword.at(i), dangerous,candidate);
			if (dnum >= threshold) {
				ans.push_back(address.at(i));
			}
		}

		if (ans.empty()) {
			return vector<string>();
		}

		return ans;
	}
};