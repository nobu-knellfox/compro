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
//int dx[4] = { 1, -1, 0, 0 }; int dy[4] = { 0, 0, 1, -1 };
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------


int ext[13];
bool draw;

bool f(string x,string y)
{
	int xnum = 0;
	int ynum = 0;

	int xs = 0;
	int ys = 0;

	for (auto s : x) {
		if (s == '!') {
			xnum++;
		}
	}

	for (auto s : y) {
		if (s == '!') {
			ynum++;
		}
	}

	xs = x.size() - xnum;
	ys = y.size() - ynum;

	int xn = stoi(x.substr(0, xs));
	int yn = stoi(y.substr(0, ys));

	while (true) {
		if (xn > 12 && yn > 12) {
			if (xnum == ynum) {
				draw = xn == yn;
				return xn > yn;
			}
			draw = xnum == ynum;
			return xnum > ynum;
		}

		if (xnum == 0 && ynum == 0) {
			draw = xn == yn;
			return xn > yn;
		}

		if (xn < 13 && xnum > 0) {
			xn = ext[xn];
			xnum--;
		}

		if (yn < 13 && ynum > 0) {
			yn = ext[yn];
			ynum--;
		}
	}

}

class ExtraordinarilyLarge {
public:
	string compare(string x, string y)
	{

		ext[0] = 1;

		REP(i, 12) {
			ext[i + 1] = (i + 1)*ext[i];
		}



		bool ff = f(x, y);

		if (draw) {
			return "x=y";
		}
		if (ff) {
			return "x>y";
		}
		else {
			return "x<y";
		}

	}
};
