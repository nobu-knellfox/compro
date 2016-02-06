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
#define inf  1145141919
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

vi a;
vs ans;

int k, n;

vi av;
vs aw;

bool ed = false;

bool check()
{
	if (ed)
		return false;

	REP(i, av.size()) {
		auto x = av[i];
		int num = 0;
		while (x) {
			num += a[(x % 10) - 1];
			x /= 10;
		}
		if (num != aw[i].size()) {
			return false;
		}
	}

	ed = true;

	REP(i, aw.size()) {
		auto x = aw[i];
		reverse(ALL(x));

		auto y = av[i];

		while (y) {
			ans[(y % 10) - 1] = x.substr(0, a[(y % 10) - 1]);
			reverse(ALL(ans[(y % 10) - 1]));
			x.erase(x.begin(), x.begin() + a[(y % 10) - 1]);
			y /= 10;
		}
	}
}

void f(int i, int k)
{
	if (i == n) {
		check();
		return;
	}
	a[i] = k;
	f(i + 1, 1);
	f(i + 1, 2);
	f(i + 1, 3);
}

signed main()
{
	QUICK_CIN;

	debug_input;
	cin >> n >> k;


	a.resize(n);
	ans.resize(n);

	REP(i, k) {
		int c;
		string s;

		cin >> c >> s;
		av.push_back(c);
		aw.push_back(s);

	}

	f(0, 1);
	f(0, 2);
	f(0, 3);

	for (auto x : ans) {
		cout << x << endl;
	}
}