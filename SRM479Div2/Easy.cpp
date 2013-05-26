#include <vector>
#include <iostream>
#include <memory>

using namespace std;

class TheAirTripDivTwo {
public:
	int find(vector <int> flights, int fuel)
	{
		int cnt = 0;
		for (int i=0; i<flights.size(); ++i) {
			if (fuel-flights.at(i)>=0) {
				++cnt;
				fuel -= flights.at(i);
			}
			else {
				break;
			}
		}
		return cnt;
	}
};