#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>

#define FILE

using namespace std;

char m[] = {'o','x'};

class NetworkXZeroOne {
public:
  string reconstruct(string message)
	{
		string ans1,ans2;
		for (int i=0; i<message.size(); ++i) {
			ans1 += m[i&1];
			ans2 += m[(i+1)&1];
		}
		for (int i=0; i<message.size(); ++i) {
			if (message[i] != '?') {
				if (message[i] != ans1[i]) {
					return ans2;
				}
				if (message[i] != ans2[i]) {
					return ans1;
				}
			}
		}
		return "No";
	}
};