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
#include <stack>
#include <queue>
#include <stdio.h>
#include <string.h>

using namespace std;

class FoxSequence {
public:
	string
	isValid(vector <int> seq)
	{
		int b=0,c=0,d=0,e=0;
		int prev=seq[1]-seq[0];
		if (prev <= 0) {
			return "NO";
		}
		for (int i=2; i<seq.size(); ++i) {
			if (seq[i]-seq[i-1]<0) {
				b = i;
				break;
			}
			else if (prev != seq[i]-seq[i-1]) {
				return "NO";
			}
		}
		if (b==0) {
			return "NO";
		}
		prev = seq[b]-seq[b-1];
		for (int i=b+1; i<seq.size(); ++i) {
			if (seq[i]-seq[i-1]>=0) {
				c = i;
				break;
			}
			else if (prev != seq[i]-seq[i-1]) {
				return "NO";
			}
		}
		if (c==0) {
			return "NO";
		}
		prev = seq[c]-seq[c-1];
		for (int i=c; i<seq.size(); ++i) {
			if (seq[i]-seq[i-1]>0 && (prev==0||prev==seq[i]-seq[i-1])) {
				d = i;
				break;
			}
			else if (prev != seq[i]-seq[i-1]) {
				return "NO";
			}
		}
		if (d==0) {
			return "NO";
		}
		prev = seq[d]-seq[d-1];
		for (int i=d+1; i<seq.size(); ++i) {
			if (seq[i]-seq[i-1]<0 && (prev>0||prev==seq[i]-seq[i-1])) {
				e = i;
				break;
			}
			else if (prev != seq[i]-seq[i-1]) {
				return "NO";
			}
		}
		if (e==0) {
			return "NO";
		}
		prev = seq[e]-seq[e-1];
		for (int i=e+1; i<seq.size(); ++i) {
			if (prev != seq[i]-seq[i-1]) {
				return "NO";
			}
		}
		return "YES";
	}
};

int main()
{
	FoxSequence fs;
	vector<int> s =
	{{9, 9, 6, 9, 6}}
	;
	cout << fs.isValid(s);
}