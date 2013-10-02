#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <sstream>
#include <set>

#define INF (1<<20)
#define MAX 101

using namespace std;

class RotatedClock {
public:
	string getEarliest(int hourHand, int minuteHand)
	{
		string ans;
		for (int mark = 0; mark < 360; mark+=30) {
			int hour = (hourHand+mark)%360;
			int minute = (hour*12)%360;
			if (minute == (minuteHand+mark)%360) {
				hour /= 30;
				minute /= 6;
				char a[] = "00:00";
				sprintf(a, "%.2d:%.2d",hour,minute);
				ans = static_cast<string>(a);
				break;
			}
		}
		return ans;
	}
};