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

#define INF (1<<20)
#define PI 3.14159265

class ToastXToast {
public:
	int
	bake(vector <int> undertoasted, vector <int> overtoasted)
	{
		sort(undertoasted.begin(), undertoasted.end());
		sort(overtoasted.begin(), overtoasted.end());
		int n = undertoasted.size() , m = overtoasted.size();
		if (undertoasted[0] > overtoasted[0] || undertoasted[n-1] > overtoasted[m-1] ) return -1;
		if (undertoasted[n-1] < overtoasted[0] ) return 1;
		return 2;
	}
};