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
#define lint LL
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


signed main()
{
	QUICK_CIN;
	debug_input;

	int t;

	cin >> t;

	REP(i, t) {
		vi a;
		
		int n;
		cin >> n;
		scan(a, n+1, cin);

		vi result(a.size(),0);
		vi po(a.size(), 0);
		vi sums(a.size(), 0);

		int len = a.size();

		int k = 1;
		po[0] = 1;
		REP(i, len-1) {
			po[i + 1] = k;
			k *= 2;
			k %= mod;
		}

		sums[0] = 0;
		REP(i, len-1) {
			sums[i + 1] = sums[i] + po[i] * a[i];
		}

		result[0] = a[0];

		REP(i, len-1) {
			result[i + 1] = 2 * (result[i] + a[i + 1] * sums[i]);
		}

		cout << result.back() << endl;
	}
}
