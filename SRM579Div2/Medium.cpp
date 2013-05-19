#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>

using namespace std;

class UndoHistory
{
public:
	int minPresses(vector <string> lines)
	{
		set<string> list;
		string buff = "";
		int cnt = -2;
		int posHist,posBuff;

		for (int lp=0; lp<lines.size(); ++lp) {
			++cnt; //to enter

			if (buff == lines.at(lp))
				continue;

			posHist = 0;
			for (int sp=1; sp<=lines.at(lp).size(); ++sp) {
				if (list.count(lines.at(lp).substr(0,sp))) {
					posHist = sp;
				}
				else {
					break;
				}
			}

			posBuff = -3;
			if ((buff.size() <= lines.at(lp).size() && buff == lines.at(lp).substr(0,buff.size())) && lp != 0) {
				posBuff = static_cast<int>(buff.size());
			}

			cnt += static_cast<int>(lines.at(lp).size()) - max(posBuff,posHist-2);

			// insert word
			buff = lines.at(lp);
			for (int bp=1; bp<=buff.size(); ++bp) {
				list.insert(buff.substr(0,bp));
			}
		}

		return cnt;
	}
};