#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class PlatypusPaternity{
public:
	int maxFamily(vector <string> femaleCompatibility, vector <string> maleCompatibility, vector <string> siblingGroups)
	{
		int ret = 0;
		int cnt = 0;
		string ssg,sfm,sml;
		for (int sg = 0; sg<siblingGroups.size(); ++sg) {
			ssg = siblingGroups.at(sg);
			for (int fm = 0; fm<femaleCompatibility.size(); ++fm) {
				sfm = femaleCompatibility.at(fm);
				for (int ml = 0; ml<maleCompatibility.size(); ++ml) {
					sml = maleCompatibility.at(ml);
					cnt = 0;
					for (int i=0; i<ssg.size(); ++i) {
						if (ssg.at(i) == 'Y') {
							if (sfm.at(i) == 'Y' && sml.at(i) == 'Y') {
								++cnt;
							}
							else {
								cnt = 0;
								break;
							}
						}
					}
					if (cnt > 0) {
						ret = max(ret,cnt+2);
					}
				}
			}
		}

		return ret;
	}
};