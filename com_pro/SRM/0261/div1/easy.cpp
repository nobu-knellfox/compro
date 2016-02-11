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
#define lint LL
#define inf  (int)(1 << 30)
#define mod 1000000007
#define QUICK_CIN ios::sync_with_stdio(false); cin.tie(0);
#define lowb lower_bound
#define upb upper_bound
#define ZERO(c,n) memset(&c[0],0,sizeof(int)*n)
#define ZERO2(c,n) memset(&c[0][0],0,sizeof(int)*n
#define pl(a) cout << ""#a": " << a << endl;
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

const int N = 200000;
vi prime;
bool ptable[N];

int counts[2000];

class PrimeStatistics {
public:
	int mostCommonRemainder(int lowerBound, int upperBound, int modulo)
	{
		ptable[0] = ptable[1] = true;

		for (int i = 2; i*i < N; ++i) {
			for (int j = i * 2; j < N; j += i) {
				ptable[j] = true;
			}
		}

		REP(i, N) {
			if (!ptable[i]) {
				prime.push_back(i);
			}
		}

		int a, b, m;

		a = lowerBound;
		b = upperBound;
		m = modulo;

		auto low = lower_bound(ALL(prime), a);
		auto high = upper_bound(ALL(prime), b);

		high--;

		while (low <= high) {
			counts[(*low) % m]++;
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

		return ii;

	}
};
