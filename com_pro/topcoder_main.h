
#include "topcoder.h"

map<char, int> ma;
using qq = queue<char>;

vector<qq> ques;

signed main()
{
	QUICK_CIN;
	//debug_input;

	string cand = "Z";
	vs ballots = { "Z" };

	for (auto x : cand) {
		ma[x] = 0;
	}

	for (auto x : ballots) {
		qq now;
		for (auto y : x) {
			now.push(y);
		}
		ques.push_back(now);
	}

	for (auto x : ques) {
		ma[x.front()]++;
	}

	int num = ballots.size();

	while (!ma.empty()) {
		int mini = inf;
		for (auto x : ma) {
			if (num / 2 < x.second) {
				cout << x.first << endl;
				return 0;
			}
			mini = min(x.second, mini);
		}

		EACH(it, ma) {
			if (it->second == mini) {
				it = ma.erase(it);
			}
			else {
				++it;
			}
		}

		for (auto& x : ques) {
			if (x.size()) {
				if (ma.find(x.front()) == ma.end()) {
					while (x.size() && ma.find(x.front()) == ma.end()) {
						x.pop();
					}
					if (x.size()) {
						ma[x.front()]++;
					}
				}
			}
		}
	}
	cout << "" << endl;

	return 0;
}
