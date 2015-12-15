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


#define REP(i,n) for(int (i) = 0;(i) < (n) ; ++(i))
#define REPS(a,i,n) for(int (i) = (a) ; (i) < (n) ; ++(i))
#if defined(_MSC_VER)||__cplusplus > 199711L
#define AUTO(r,v) auto r = (v)
#else
#define AUTO(r,v) typeof(v) r = (v)
#endif
#define ALL(c) (c).begin() , (c).end()
#define EACH(it,c) for(AUTO(it,(c).begin());it != (c).end();++it)
#define LL long long
#define int LL
#define inf  ((int)1 << 54)
#define DIV 1000000007
#define QUICK_CIN ios::sync_with_stdio(false); cin.tie(0);
#define InitArr1(c,n) memset(&c[0],0,sizeof(int)*n)
#define InitArr2(c,n) memset(&c[0][0],0,sizeof(int)*n)
#define vscan(a) int _c_; cin >> _c_; (a).push_back(_c_);
#define debug_input fstream cin("input.txt");ofstream cout("output.txt");

template<class T>
bool valid(T x, T w) { return 0 <= x&&x < w; }

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

using namespace std;

//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

vector<pair<int, int>>a, c;

void f()
{
	sort(ALL(a));
	sort(ALL(c));

	for (auto i = a.begin(); i != a.end();) {
		if (*i < c[0]) {
			i = a.erase(i);
		}
		else {
			break;
		}
	}

	for (auto i = c.rbegin(); i != c.rend();) {
		if (*i > a[a.size()-1]) {
			i++;
			c.pop_back();
		}
		else {
			break;
		}
	}

	sort(ALL(a), [](pair<int, int> a, pair<int, int> b) {return a.second <= b.second; });
	sort(ALL(c), [](pair<int, int> a, pair<int, int> b) {return a.second <= b.second; });

	for (auto i = c.begin(); i != c.end();) {
		if (*i < a[0]) {
			i = c.erase(i);
		}
		else {
			break;
		}
	}

	for (auto i = a.rbegin(); i != a.rend();) {
		if (*i > c[a.size() - 1]) {
			i++;
			a.pop_back();
		}
		else {
			break;
		}
	}
}

signed main()
{
	QUICK_CIN;
	//debug_input;

	int n, m;

	cin >> n >> m;



	REP(i, n) {
		int x, y;
		cin >> x >> y;
		a.push_back({x,y});
	}

	REP(i, m) {
		int x, y;
		cin >> x >> y;
		c.push_back({y, x});
	}

	f();

	cout << min(a.size() , c.size()) << endl;

	return 0;
}
