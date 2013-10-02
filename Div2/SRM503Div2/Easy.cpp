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

class ToastXRaspberry {
public:
  int apply(int upper_limit, int layer_count)
	{
		return (layer_count/upper_limit) + (layer_count%upper_limit==0?0:1);
	}
};