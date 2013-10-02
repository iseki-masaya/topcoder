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

#define INF (1<<20)
#define MAX 101

using namespace std;

class MarbleDecoration {
public:
  int maxLength(int R, int G, int B)
	{
		vector<int> color(3);
		color[0] = R; color[1] = G; color[2]=B;
		sort(color.begin(), color.end());
		if (color[1] == color[2]) {
			return 2 * color[1];
		}
		else {
			return 2*color[1]+1;
		}
	}
};