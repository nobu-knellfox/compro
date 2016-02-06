
#include "topcoder.h"

signed main()
{
	QUICK_CIN;
	debug_input;

	int wait, walk, late, best, worst;

	cin >> wait >> walk >> late >> best >> worst;

	int sum = 0;

	REPS(best+1 - (int)(worst == best), i, worst+1) {
		int k = i % (wait + walk);
		
		if (k <= wait) {
			continue;
		}

		k = (wait+walk) - k;
		if (late <= k) {
			++sum;
		}
	}

	if (worst == best) {
		cout << (double)sum << endl;
	}

	cout << (double)sum / (worst - best) << endl;

	return 0;
}
