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

bool table[501][501];

signed main()
{
	QUICK_CIN;
	//debug_input;

	int x, y, x0, y0;
	cin >> x >> y >> x0 >> y0;
	x--; y--; x0--; y0--;


	string s;
	cin >> s;

	cout << 1 << " ";
	table[x0][y0] = true;

	REP(i, s.length() - 1) {
		switch (s[i])
		{
		case 'U':
			if (x0 == 0) {
				cout << 0 << " ";
				break;
			}
			x0--;
			if (!table[x0][y0]) {
				table[x0][y0] = true;
				cout << 1 << " ";
			}
			else {
				cout << 0 << " ";
			}

			break;

		case 'D':
			if (x0 == x) {
				cout << 0 << " ";
				break;
			}
			x0++;
			if (!table[x0][y0]) {
				table[x0][y0] = true;
				cout << 1 << " ";
			}
			else {
				cout << 0 << " ";
			}
			break;
		case 'R':
			if (y0 == y) {
				cout << 0 << " ";
				break;
			}
			y0++;
			if (!table[x0][y0]) {
				table[x0][y0] = true;
				cout << 1 << " ";
			}
			else {
				cout << 0 << " ";
			}
			break;

		case 'L':
			if (y0 == 0) {
				cout << 0 << " ";
				break;
			}
			y0--;
			if (!table[x0][y0]) {
				table[x0][y0] = true;
				cout << 1 << " ";
			}
			else {
				cout << 0 << " ";
			}
			break;

		default:
			break;
		}
	}

	int sum = 0;

	REP(i, 501) {
		REP(j, 501) {
			if (table[i][j]) {
				sum++;
			}
		}
	}

	cout << (x + 1)*(y + 1) - sum << endl;

	return 0;
}
