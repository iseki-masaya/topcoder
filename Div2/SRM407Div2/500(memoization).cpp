#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

long long int salaryMemo[51];

class CorporationSalary
{
public:
	long long int getSalary(vector <string> relations,int pos)
	{
		if (salaryMemo[pos] == 0) {
			string str = relations.at(pos);
			long long int result = 0;
			for (int i=0; i<str.size(); ++i) {
				if(str.at(i) == 'Y')
					result += getSalary(relations, i);
			}
			if(result == 0)
				result = 1;
			salaryMemo[pos] = result;
		}
		return salaryMemo[pos];
	}
	
	long long totalSalary(vector <string> relations)
	{
		long long int ret = 0;
		for(int i=0;i<relations.size();++i){
			ret += getSalary(relations,i);
		}
		return ret;
	}
};