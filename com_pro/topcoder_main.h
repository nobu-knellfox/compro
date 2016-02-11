
#include "topcoder.h"

const int N = 200000;
vi prime;
bool ptable[N];

int counts[2000];

signed main()
{
	QUICK_CIN;
	//debug_input;

	ptable[0] = ptable[1] = true;

	for (int i = 2; i*i < N;++i) {
		for (int j = i*2; j < N; j += i) {
			ptable[j] = true;
		}
	}

	REP(i, N) {
		if (!ptable[i]) {
			prime.push_back(i);
		}
	}

	int a,b,m;

	cin >> a >> b >> m;

	auto low = lower_bound(ALL(prime),a);
	auto high = upper_bound(ALL(prime), b);

	high--;

	while (low <= high) {
		counts[(*low)%m]++;
		++low;
	}

	int maxi = -inf;
	int ii = -inf;

	REP(i, 2000) {
		if (maxi < counts[i]) {
			maxi = max(counts[i], maxi);
			ii = i;
		}
	}

	cout << ii << endl;

	return 0;
}
