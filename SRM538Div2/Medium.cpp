#include <string>
#include <iostream>
#include <vector>

using namespace std;

class EvenRoute
{
private:
public:
	string isItPossible(vector <int> x, vector <int> y, int wantedParity)
	{
		int size = static_cast<int>(x.size());
		for (int i=0; i<size; ++i) {
			if (abs(x.at(i)+abs(y.at(i)))%2 == wantedParity) {
				return "CAN";
			}
		}
		return "CANNOT";
	}
};