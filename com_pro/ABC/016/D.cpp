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
#if defined(_MSC_VER)||__cplusplus > 199711L
#define AUTO(r,v) auto r = (v)
#else
#define AUTO(r,v) typeof(v) r = (v)
#endif
#define ALL(c) (c).begin() , (c).end()
#define EACH(it,c) for(AUTO(it,(c).begin());it != (c).end();)
#define LL long long
#define int LL
#define inf  (int)(1LL << 50)
#define mod 1000000007
#define QUICK_CIN ios::sync_with_stdio(false); cin.tie(0);
#define lowb lower_bound
#define upb upper_bound
#define ZERO(c,n) memset(&c[0],0,sizeof(int)*n)
#define ZERO2(c,n) memset(&c[0][0],0,sizeof(int)*n
#define pl(a) cout << ""#a": " << a << endl;
#define cx() real()
#define cy() imag()
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

using cd = complex<double>;

double area_triangle(cd a, cd b, cd c)
{
	cd ab = b - a;
	cd ac = c - a;

	return (ab*conj(ac)).cy();
}

bool Intersection(cd a, cd b, cd c, cd d)
{
	bool s = area_triangle(a, b, c)*area_triangle(a, b, d) < 0;
	bool t = area_triangle(c, d, a)*area_triangle(c, d, b) < 0;

	return s&&t;
}


signed main()
{
	QUICK_CIN;
	debug_input;

	double ax, ay, bx, by;
	int n;
	
	cin >> ax >> ay >> bx >> by >> n;

	int count = 0;

	cd a(ax, ay);
	cd b(bx, by);

	double cx, cy,dx,dy;
	cin >> cx >> cy >> dx >> dy;

	cd c(cx,cy), d(dx,dy);
	count += Intersection(a,b,c,d) ? 1 : 0;

	cd temp = c;

	REP(i, n-2) {
		c = d;
		cin >> dx >> dy;
		d = cd(dx,dy);
		count += Intersection(a, b, c, d) ? 1 : 0;
	}

	count += Intersection(a, b, d, temp) ? 1 : 0;

	cout << count / 2 + 1 << endl;
}
