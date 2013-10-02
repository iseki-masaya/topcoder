#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class EllysDirectoryListing {
public:
	vector <string> getFiles(vector <string> files)
	{
		bool isSwap = false;
		string tmp;

		if ((files.at(files.size()-1)=="."&&files.at(files.size()-2)=="..")
				||(files.at(files.size()-1)==".."&&files.at(files.size()-2)==".")) {
			return files;
		}

		for (int i=0; i<files.size()-2; ++i) {
			if (files.at(i) == "." || files.at(i) == "..") {
				if (isSwap) {
					tmp = files.at(files.size()-2);
					files.at(files.size()-2) = files.at(i);
					files.at(i) = tmp;
					break;
				}
				else {
					tmp = files.at(files.size()-1);
					files.at(files.size()-1) = files.at(i);
					files.at(i) = tmp;
					--i;
					isSwap = true;
				}
			}
		}

		return files;
	}
};