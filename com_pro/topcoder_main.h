
#include "topcoder.h"

signed main()
{
	QUICK_CIN;
	debug_input;

	int n, m, k, h;
	cin >> n >> m >> k >> h;

	for (int i = max(1, h - (k - 1)); i <= min(n, h + (k - 1)); i += (2 - (k == 2))) {
		miho[i] = true;
	}


	for (int i = max(1, m - (k - 1)); i <= min(n, m + (k - 1)); i += (2 - (k == 2))) {
		if (i == h) {
			cout << "Romeo" << endl;
			return 0;
		}
	}

	bool f = true;

	for (int i = max(1, m - (k - 1)); i <= min(n, m + (k - 1)); i += (2 - (k == 2))) {

		f &= miho[i];

	}
	if (f) {
		cout << "Strangelet" << endl;
		return 0;
	}


	cout << "Draw" << endl;

	return 0;
}
