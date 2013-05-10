#include <iostream>
#include <bitset>
#include <vector>
#include <set>
#include <string>
#include <cmath>

#define INF 300000

using namespace std;

set<string> list;

class CuttingBitString
{
public:
	template <class T>
	string toStr(T a)
	{
		string str;
		bool isStart = false;
		for (int i=(int)a.size()-1;i>=0;--i) {
			if (!isStart && a[i])
				isStart = true; 
			if (isStart) {
				if (a[i]) {
					str.push_back('1');
				}
				else {
					str.push_back('0');
				}
			}
		}
		return str;
	}

	template <class T>
	T add(T a,T b)
	{
		bool isCarry = false;
		T result;
		for (int i = 0; i < a.size(); ++i) {
			if(a[i] && b[i] && isCarry) {
				isCarry = true;
				result.set(i);
			}
			else if (a[i] && b[i]) {
				isCarry = true;
				result.reset(i);
			}
			else if (isCarry && (a[i] || b[i])) {
				isCarry = true;
				result.reset(i);
			}
			else if (a[i] || b[i]) {
				isCarry = false;
				result.set(i);
			}
			else if (isCarry) {
				isCarry = false;
				result.set(i);
			}
			else {
				isCarry = false;
				result.reset(i);
			}
		}
		return result;
	}

	void makeList()
	{
		vector<string> tmpList;
		bitset<55> binary,work;
		binary.set(0);
		binary.set(2);
		list.insert(toStr(binary));
		list.insert("1");
		for (int i = 0; i < 23; ++i) {
			work = binary;
			binary = add(binary,work<<=(2));
			list.insert(toStr(binary));
		}	
	}

	int calcMin(string s)
	{
		if(s.size() == 0) return 0;
		int r = INF;
		for (int i=1;i<=s.size();++i) {
			if(list.count(s.substr(0,i)) == 1){
				cout << "sub" << endl;
				r = min(r,1+calcMin(s.substr(i,s.size()-i)));
			}
		}
		return r;
	}
	
	int getmin(string S)
	{
		makeList();
		for (set<string>::iterator it=list.begin();it != list.end();++it) {
			cout << *it << endl;
		}
		int min = calcMin(S);

		return min == INF ? -1 : min;
	}	
};