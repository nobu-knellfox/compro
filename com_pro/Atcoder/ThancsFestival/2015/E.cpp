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


vector<char> ch;

void f()
{
	string s, t;
	cin >> s >> t;
	REP(k, 26) {
		REP(i, (int)s.size() - (int)t.size() + 1) {
			bool ok = true;
			REP(j, t.size()) {
				if (s[i + j] != t[j]) {
					ok = false;
				}
			}
			if (ok) {
				cout << "YES" << endl;
				return;
			}
		}

		string ts = "";
		for_each(ALL(s), [&](char x) {
			if (x != ch[k]) {
				ts += x;
			}
		});

		int y(0);
		REP(w, ts.size()) {
			if (ts[w] == t[y])++y;

			if (y == t.size()) {
				s = ts;
				break;
			}
		}
	}


	REP(i, (int)s.size() - (int)t.size() + 1) {
		bool ok = true;
		REP(j, t.size()) {
			if (s[i + j] != t[j]) {
				ok = false;
			}
		}
		if (ok) {
			cout << "YES" << endl;
			return;
		}
	}

	cout << "NO" << endl;
	return;
}

signed main()
{
	QUICK_CIN;
	//debug_input;

	REP(i, 26) {
		ch.push_back((char)('a' + i));
	}

	int q;
	cin >> q;

	REP(i, q) {
		f();
	}

	return 0;
}
