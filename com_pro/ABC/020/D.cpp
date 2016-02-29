
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
#include <complex>
using namespace std;
#define REP(i,n) for(int (i) = 0;(i) < (n) ; ++(i))
#define REPS(a,i,n) for(int (i) = (a) ; (i) < (n) ; ++(i))
#define REVERSE(i,n) for(int (i) = n-1;(i) >= 0 ; --i)
#define ALL(c) (c).begin() , (c).end()
#define EACH(it,c) for(auto(it,(c).begin());it != (c).end();)
#define cx real()
#define cy imag()
#define px first
#define py second
#define LL long long
#define int LL
#define inf  (1LL << 60)
#define mod 1000000007
#define QUICK_CIN ios::sync_with_stdio(false); cin.tie(0);
#define lower lower_bound
#define upper upper_bound
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
template<class T>void scan(vector<T>& a, int n, istream& cin)
{
	T c; REP(i, n) { cin >> c; a.push_back(c); }
}
using vs = vector<string>; using vi = vector<int>; using pii = pair<int, int>;
using psi = pair<string, int>; using vvi = vector<vi>; using pss = pair<string, string>;
template<class T>bool valid(T x, T w) { return 0 <= x&&x < w; }
int dx[4] = { 1, -1, 0, 0 }; int dy[4] = { 0, 0, 1, -1 };
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

int gcd(int a, int b)
{
	if (a < b) {
		swap(a, b);
	}

	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}

int lcm(int a, int b)
{
	return (int)a * (int)b / gcd(a, b);
}

int kk[110];

signed main()
{
	QUICK_CIN;
	debug_input;

	int n, k;

	cin >> n >> k;

	if (k > 101) {
		return 0;
	}

	REP(i, min(n, k)) {
		kk[i + 1] = gcd(i + 1, k);
		kk[i + 1] %= mod;
	}

	int sum = 0;

	REPS(1, i, min(n, k) + 1) {
		int an = n - (n % k) - k + i;
		if (i <= n % k) {
			an += k;
		}
		int num = an/k + (an % k != 0);
		int kkk = (i + an)*num / 2;
		sum += kkk*k / kk[i];
		sum %= mod;
	}

	cout << sum << endl;
}


