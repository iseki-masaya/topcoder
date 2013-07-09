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

#define MAX_V (10000001)
#define MAX_N (100001)
#define MOD 1000000007
#define INF (1<<30)

using namespace std;

class SentenceCapitalizerInator {
public:
  string fixCaps(string paragraph)
	{
		bool isInitial = true;
		for (int i=0; i<paragraph.size(); ++i) {
			if (isInitial && islower(paragraph[i])) {
				paragraph[i] = toupper(paragraph[i]);
				isInitial = false;
			}
			else if (paragraph[i] == '.') {
				isInitial = true;
			}
		}
		return paragraph;
	}
};