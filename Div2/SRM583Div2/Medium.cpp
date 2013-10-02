#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <sstream>

using namespace std;

int daya[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int ldaya[] = {31,29,31,30,31,30,31,31,30,31,30,31};

class IDNumberVerification {
	bool isLeap(int y)
	{
		if (y%400==0) {
			return true;
		}
		if (y%100==0) {
			return false;
		}
		if (y%4==0) {
			return true;
		}
		return false;
	}

	bool isValidSequentialCode(string str) {
		return str!="000";
	}

	bool isValidRegionCode(string str,vector<string> &regionCodes){
		return find(regionCodes.begin(), regionCodes.end(), str) != regionCodes.end();
	}

	bool isValidBirthDay(string id) {
		int y = atoi(id.substr(6,4).data());
		int m = atoi(id.substr(10,2).data());
		int d = atoi(id.substr(12,2).data());
		if (y<1900 ||  2011<y)
			return false;

		if (m > 12 || m < 1)
			return false;

		if (d < 1) {
			return false;
		}

		if (isLeap(y)){
			if (d > ldaya[m-1] || d < 1) {
				return false;
			}
		}
		else {
			if (d > daya[m-1] || d < 1) {
				return false;
			}
		}

		return true;
	}

	bool isValidCode(string id)
	{
		long long code;
		if (id[17]=='X') {
			code = 10;
		}
		else {
			code = (id[17]-'0');
		}

		for (int i=0; i<id.size()-1; ++i) {
			code += ((int)(id[i]-'0'))*(1<<(17-i));
			code = code%11;
		}
		if (code != 1) {
			return false;
		}
		return true;
	}

	int calcGender(int i)
	{
		if (i%2==0) {
			return 1;
		}
		else {
			return -1;
		}
	}
public:
	string verify(string id, vector <string> regionCodes)
	{
		int ans = 1;
		ans &= isValidSequentialCode(id.substr(14,3));
		ans &= isValidRegionCode(id.substr(0,6), regionCodes);
		ans &= isValidBirthDay(id);
		ans &= isValidCode(id);
		ans *= calcGender(id[16]-'0');

		if (ans == 1) {
			return "Female";
		}
		else if (ans == -1) {
			return "Male";
		}
		else {
			return "Invalid";
		}
	}
};