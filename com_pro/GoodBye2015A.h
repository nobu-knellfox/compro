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
#define EACH(it,c) for(AUTO(it,(c).begin());it != (c).end();)
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
template<class T>void scan(vector<T>& a, int n, istream& cin) { T c; REP(i, n) { cin >> c; a.push_back(c); } }
using vs = vector<string>; using vi = vector<int>; using pii = pair<int, int>; using psi = pair<string, int>; using vvi = vector<vi>;
template<class T>bool valid(T x, T w) { return 0 <= x&&x < w; }
int dx[4] = { 1, -1, 0, 0 }; int dy[4] = { 0, 0, 1, -1 };
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

vs s;

struct Node {
	int h1, w1, h2, w2;
};

vector<Node> node;

signed main()
{
	QUICK_CIN;
	//debug_input;

	int w, h;
	cin >> h >> w;
	scan(s, h, cin);

	vvi dp(h);
	REP(i, h) {
		dp[i].reserve(w);
	}

	REP(i, h) {
		REP(j, w) {
			dp[i].push_back(0);
		}
	}

	int n; cin >> n;
	REP(i, n) {
		int q, qq, qqq, qqqq;
		cin >> q >> qq >> qqq >> qqqq;
		node.push_back({--q,--qq,--qqq,--qqqq});
	}

	REP(i, h-1) {
		if (s[i][0] == s[i + 1][0] && s[i][0] == '.') {
			dp[i + 1][0] = dp[i][0] + 1;
		}
		else dp[i + 1][0] = dp[i][0];
	}

	REP(i, w - 1) {
		if (s[0][i] == s[0][i + 1] && s[0][i] == '.') {
			dp[0][i + 1] = dp[0][i] + 1;
		}
		else dp[0][i + 1] = dp[0][i];
	}


	REPS(1,i, h) {
		REPS(1,j, w) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
			if (s[i][j] == s[i - 1][j] && s[i][j] == '.') {
				dp[i][j] += 1;
			}
			if (s[i][j] == s[i][j-1] && s[i][j] == '.') {
				dp[i][j] += 1;
			}
		}
	}

	for (auto x : node) {
		int ans = dp[x.h2][x.w2];
		if (0 < x.h1) {
			ans -= dp[x.h1 - 1][x.w2];
			REPS(x.w1, i, x.w2 + 1) {
				if (s[x.h1 - 1][i] == s[x.h1][i] && s[x.h1 - 1][i] == '.') {
					ans--;
				}
			}
		}
		if (0 < x.w1) {
			ans -= dp[x.h2][x.w1 - 1];
			REPS(x.h1, i, x.h2 + 1) {
				if (s[i][x.w1 - 1] == s[i][x.w1] && s[i][x.w1 - 1] == '.') {
					ans--;
				}
			}
		}

		if (0 < x.w1 && 0 < x.h1) {
			ans += dp[x.h1-1][x.w1 - 1];
		}


		cout << ans << endl;
	}
}
