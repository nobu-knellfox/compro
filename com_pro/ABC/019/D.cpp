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
{ T c; REP(i, n) { cin >> c; a.push_back(c); } }
using vs = vector<string>; using vi = vector<int>; using pii = pair<int, int>; 
using psi = pair<string, int>; using vvi = vector<vi>; using pss = pair<string, string>;
template<class T>bool valid(T x, T w) { return 0 <= x&&x < w; }
int dx[4] = { 1, -1, 0, 0 }; int dy[4] = { 0, 0, 1, -1 };
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

int d[55];

signed main()
{
	QUICK_CIN;
	//debug_input;

	int n;

	cin >> n;

	REP(i, n-1) {
		int c;

		cout << "? " <<  1 << " " << i + 2 << endl;
		cin >> c;

		d[i + 1] = c;
	}

	int maxi = -inf;
	int it = -1;

	REP(i, n) {
		if (maxi < d[i]) {
			maxi = d[i];
			it = i;
		}
	}

	REP(i, 55) {
		d[i] = 0;
	}

	REP(i, n) {
		int c;
		if (it != i) {
			cout << "? " << it + 1 << " " << i + 1 << endl;
			cin >> c;

			d[i] = c;
		}
	}

	maxi = -inf;
	REP(i, 55) {
		maxi = max(maxi, d[i]);
	}

	cout << "! " << maxi << endl;
}



