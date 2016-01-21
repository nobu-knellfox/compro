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
#define mod 1000000007
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

int memo[10001];
set<int> s[10001];
vi aa[10001];

signed main()
{
	QUICK_CIN;
	//debug_input;

	vi a;
	int n;
	cin >> n;
	REP(i, n) {
		int c;
		cin >> c;
		memo[c]++;
		a.push_back(c);
	}
	REP(i, n) {
		for (int x = 1; x*x <= a[i]; ++x) {
			if (a[i] % x == 0) {
				s[a[i] / x].insert(x);
				s[x].insert(a[i] / x);
				aa[a[i]].push_back(a[i] / x);
				aa[a[i]].push_back(x);
			}
		}
	}

	int now = a[0];
	cout << now << " ";
	memo[now]--;
	while (true) {
		int min_co = inf;
		int min_t = inf;
		for (auto x : aa[now]) {
			auto it = s[x].begin();
			while (it != s[x].end() && memo[x*(*it)] == 0) {
				it = s[x].erase(it);
			}
			if (it == s[x].end()) {
				continue;
			}
			if (now*(*it) < min_co || (now*(*it) == min_co && x*(*it) < min_t)) {
				min_co = now*(*it);
				min_t = x*(*it);
			}
		}
		if (min_t == inf) {
			break;
		}
		memo[min_t]--;
		cout << min_t << " ";
		now = min_t;
	}
	cout << endl;
}
