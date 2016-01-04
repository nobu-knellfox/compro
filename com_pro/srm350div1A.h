#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <stack>
#include <array>
#include <fstream>
#include <deque>
#include <bitset>
using namespace std;
#define REP(i,n) for(int (i) = 0;(i) < (n) ; ++(i))
#define REPS(a,i,n) for(int (i) = (a) ; (i) < (n) ; ++(i))
#if defined(_MSC_VER)||__cplusplus > 199711L
#define AUTO(r,v) auto r = (v)
#else
#define AUTO(r,v) typeof(v) r = (v)
#endif
#define ALL(c) (c).begin() , (c).end()
#define EACH(it,c) for(AUTO(it,(c).begin());it != (c).end();++it)
#define LL long long
#define int LL
#define inf  ((int)1 << 54)
#define DIV 1000000007
#define QUICK_CIN ios::sync_with_stdio(false); cin.tie(0);
#define lowb lower_bound
#define upb upper_bound
#define ZERO(c,n) memset(&c[0],0,sizeof(int)*n)
#define ZERO2(c,n) memset(&c[0][0],0,sizeof(int)*n)
#define debug_input fstream cin("input.txt");ofstream cout("output.txt");
#define pb(a) push_back(a)
template<class T>void scan(vector<T> a,int n){T c;REP(i, n){cin >> c;a.push_back(c);}}
using vi = vector<int>;using pii = pair<int, int>;using psi = pair<string, int>;using vvi = vector<vi>;
template<class T>bool valid(T x, T w) { return 0 <= x&&x < w; }
int dx[4] = { 1, -1, 0, 0 };int dy[4] = { 0, 0, 1, -1 };
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

vi a;
vi aa;
bool b[5000001];
bool bb[5000001];

class SumsOfPerfectPowers {
public:
	int howMany(int lowerBound, int upperBound)
	{
		int s, t;
		s = lowerBound;
		t = upperBound;


		a.pb(0);
		a.pb(1);

		REPS(2, i, 5000001) {
			int k = i*i;
			if (k < t + 1 && !b[k]) {
				while (k < t + 1) {
					b[k] = true;
					a.pb(k);
					k *= i;
				}
			}
		}

		for (auto x : a) {
			for (auto y : a) {
				if (x + y < t + 1 && !bb[x + y]) {
					aa.push_back(x + y);
					bb[x + y] = true;
				}
			}
		}

		sort(ALL(aa));

		int ans = distance(lowb(ALL(aa), s), upb(ALL(aa), t));

		return ans;
	}
};

signed main()
{
	QUICK_CIN;
	//debug_input;

	int s, t;
	cin >> s >> t;

	a.pb(0);
	a.pb(1);

	REPS(2,i, 5000001) {
		int k = i*i;
		if (k < t+1 && !b[k]) {
			while (k < t + 1) {
				b[k] = true;
				a.pb(k);
				k *= i;
			}
		}
	}

	for (auto x : a) {
		for (auto y : a) {
			if (x+y < t+1 && !bb[x + y]) {
				aa.push_back(x + y);
				bb[x + y] = true;
			}
		}
	}

	sort(ALL(aa));

	int ans = distance(lowb(ALL(aa),s),upb(ALL(aa),t));


	cout << ans << endl;
}
