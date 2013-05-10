#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

long long int salary[51][51];

class CorporationSalary
{
public:
	void initSalary()
	{
		for (int i=0; i<51; ++i) {
			for (int j=0; j<51; ++j) {
				salary[i][j] = 1;
			}
		}
	}
	
	long long totalSalary(vector <string> relations)
	{
		initSalary();
		int size = (int)relations.size();
		long long int work = 0;
		for (int k=1; k<size+1; ++k) {
			for (int i=0; i<size; ++i) {
				for (int j=0; j<size; ++j) {
					if(relations.at(i).at(j) == 'Y'){
						work += salary[k-1][j];
					}
				}
				if(work > 0)
					salary[k][i] = work;
				work = 0;
			}
		}
		long long int result = 0;
		for (int i=0; i<size; ++i) {
			result += salary[size][i];
		}
		return result;
	}
};