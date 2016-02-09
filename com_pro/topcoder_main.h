
#include "topcoder.h"

//int table[70][70];


signed main()
{
	QUICK_CIN;
	//debug_input;

	vs a = { "9 2 3", "4 8 7" };

	int i = 0;
	int h, w;

	for (auto x : a) {
		stringstream ss(x);
		string temp;
		int j = 0;
		while (ss >> temp) {
			table[i][j] = stoi(temp);
			++j;
		}
		++i;
		w = j;
	}
	h = i;

	
	int maxmin = -inf;
	REP(i, h) {
		int maxi = inf;
		REP(j, w) {
			maxi = min(table[i][j],maxi);
		}
		maxmin = max(maxmin,maxi);
	}

	int minmax = inf;
	REP(j, w) {
		int mini = -inf;
		REP(i, h) {
			mini = max(table[i][j], mini);
		}
		minmax = min(minmax, mini);
	}

	//return vector<int>({maxmin,minmax});

	vi aa;
	aa.push_back(maxmin);
	aa.push_back(minmax);

	for (auto x : aa) {
		cout << x << endl;
	}
	return 0;
}
