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
#define REVERSE(i,n) for(int (i) = n-1;(i) >= 0 ; --i)
#if defined(_MSC_VER)||__cplusplus > 199711L
#define AUTO(r,v) auto r = (v)
#else
#define AUTO(r,v) typeof(v) r = (v)
#endif
#define ALL(c) (c).begin() , (c).end()
#define EACH(it,c) for(AUTO(it,(c).begin());it != (c).end();)
#define LL long long
#define int LL
#define inf  (1LL << 50)
#define mod 1000000007
#define QUICK_CIN ios::sync_with_stdio(false); cin.tie(0);
#define lowb lower_bound
#define upb upper_bound
#define ZERO(c,n) memset(&c[0],0,sizeof(int)*n)
#define ZERO2(c,n) memset(&c[0][0],0,sizeof(int)*n
#ifdef _DEBUG
#define debug_io fstream cin("input.txt");ofstream cout("output.txt");
#else
#define debug_io ;
#endif
#define debug_input debug_io
#define pb(a) push_back(a)
template<class T>void scan(vector<T>& a, int n, istream& cin) { T c; REP(i, n) { cin >> c; a.push_back(c); } }
using vs = vector<string>; using vi = vector<int>; using pii = pair<int, int>; using psi = pair<string, int>; using vvi = vector<vi>;
template<class T>bool valid(T x, T w) { return 0 <= x&&x < w; }
int dx[4] = { 1, -1, 0, 0 }; int dy[4] = { 0, 0, 1, -1 };
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------


struct P {
	int v;
	int w;
};

int n, w;

int dp[1001 * 201];

vector<P> a;

vector<P> aa;
vector<P> bb;

int f(int i, int vv, int ww, int b)
{
	if (i == b) {
		aa.push_back({ vv,ww });
		return 0;
	}

	if (ww + a[i].w <= w)
		return max(f(i + 1, vv, ww, b), f(i + 1, vv + a[i].v, ww + a[i].w, b));

	return f(i + 1, vv, ww, b);
}

int f2(int i, int vv, int ww, int b)
{
	if (i == b) {
		bb.push_back({ vv,ww });
		return 0;
	}

	if (ww + a[i].w <= w)
		return max(f2(i + 1, vv, ww, b), f2(i + 1, vv + a[i].v, ww + a[i].w, b));

	return f2(i + 1, vv, ww, b);
}

signed main()
{
	QUICK_CIN;
	debug_input;


	cin >> n >> w;


	int fl = 2;

	REP(i, n) {
		int c, d;
		cin >> c >> d;

		a.push_back({ c,d });
	}


	int ans = 0;

	int sumV = 0;
	int sumW = 0;
	for (auto x : a) {
		sumV += x.v;
		sumW += x.w;
	}


	if (sumV < 201 * 1001) {
		fl = 1;
	}
	else if (sumW < 201 * 1001) {
		fl = 2;
	}
	else {
		fl = 0;
	}

	if (fl == 0) {
		f(0, 0, 0, n / 2);
		f2(n / 2, 0, 0, n);

		sort(ALL(aa), [](P a, P b)
		{
			return a.v > b.v;
		});

		for (auto x : bb) {
			REP(j, aa.size()) {
				if (x.w + aa[j].w <= w) {
					ans = max(x.v + aa[j].v, ans);
					break;
				}
			}
		}
	}


	else if (fl == 1) {
		REP(i, 1001 * 201) {
			dp[i] = inf;
		}

		dp[0] = 0;

		REP(i, n) {
			for (int j = sumV; j >= a[i].v; --j) {
				dp[j] = min(dp[j], dp[j - a[i].v] + a[i].w);
			}
		}

		REP(i, sumV + 1) {
			if (dp[i] <= w)
				ans = max(i, ans);
		}
	}


	else if (fl == 2) {
		REP(i, 1001 * 201) {
			dp[i] = -inf;
		}

		dp[0] = 0;

		REP(i, n) {
			for (int j = sumW; j >= a[i].w; --j) {
				dp[j] = max(dp[j], dp[j - a[i].w] + a[i].v);
			}
		}
		REP(i, sumW + 1) {
			if (i <= w)
				ans = max(ans, dp[i]);
		}
	}

	cout << ans << endl;
}