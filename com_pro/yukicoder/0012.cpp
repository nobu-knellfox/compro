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

template<class T>
bool valid(T x, T w) { return 0 <= x&&x < w; }

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

using namespace std;

//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

bool prime[5000001];
vector<int> pris;


signed main()
{
	QUICK_CIN;
	//fstream cin("debug.txt");
	//ofstream cout("result.txt");

	prime[0] = prime[1] = true;

	for (int i = 2; i*i < 5000001; ++i) {
		int j = 2 * i;
		for (; j < 5000001; j += i) {
			prime[j] = true;
		}
	}

	pris.push_back(0);

	REP(i, 5000001) {
		if (!prime[i]) {
			pris.push_back(i);
		}
	}

	int n;
	cin >> n;
	map<int, bool> a;
	bool dd[10] = { false };

	REP(i, n) {
		int c;
		cin >> c;
		a[c] = true;
		dd[c] = true;
	}


	int max_l = -1;
	int point = 0;

	REP(i, pris.size()) {
		bool ok = true;

		auto p = pris[i];
		bool d[10] = { false };

		while (p) {
			d[p % 10] = true;
			p /= 10;
		}

		REP(i, 10) {
			if (d[i] && !a.count(i)) {
				ok = false;
			}
		}

		if (ok) {
			REP(i, 10) {
				if(d[i])
					dd[i] = false;
			}

			if (i == pris.size() - 1) {
				auto lp = pris[point];
				max_l = max(max_l, 5000000 - lp - 1);
			}
		}
		else {
			bool ook = false;
			REP(i, 10) {
				ook |= dd[i];
			}

			if (!ook) {
				auto rp = pris[i];
				auto lp = pris[point];
				max_l = max(max_l, rp - lp - 2);
			}
			
			for (auto x : a) {
				dd[x.first] = true;
			}

			point = i;
		}
	}
	cout << max_l << endl;
}
