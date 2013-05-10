#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class InterestingDigits
{
	struct value{
		int one;
		int ten;
		int hundred;
	};
	
public:
	vector <int> digits(int base)
	{
		vector<int> list;
		value v;
		v.one = 0; v.ten = 0; v.hundred = 0;
		int sum;
		int tmp;
		bool isBase = false;
		for (int i=2; i<base; ++i) {
			for (int j=0; j<1000; ++j) {
			  if(v.one == base){
					v.one = 0;
					++v.ten;
				}
				if(v.ten == base){
					v.ten = 0;
					++v.hundred;
				}
				tmp = (v.hundred)*(base*base) + (v.ten)*base + v.one;
				if (tmp%i == 0) {
					sum = v.hundred + v.ten + v.one;
					if (sum%i == 0) {
						isBase = true;
					} else {
						isBase = false;
						break;
					}
				}
				++v.one;
			}
			if (isBase) {
				list.push_back(i);
				isBase = false;
			}
		}
		return list;
	}
};