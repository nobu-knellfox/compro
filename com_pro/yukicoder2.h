#pragma once
#pragma once

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
#define INF  99999999
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

int n;
bool dp[111][11001];

signed main()
{
	QUICK_CIN;
	fstream cin("debug.txt");
	ofstream cout("result.txt");

	while (cin >> n) {
		REP(i, 101) {
			REP(j, 10001)
				dp[i][j] = false;
		}

		dp[0][0] = true;

		vector<int> v(n);

		REP(i, n) {
			int c;
			cin >> c;
			v[i] = c;
		}

		sort(ALL(v));



		REP(i, n) {
			REP(j, n * 101) {
				dp[i + 1][j] = dp[i][j] || dp[i + 1][j];
				dp[i + 1][j + v[i]] = dp[i][j] || dp[i + 1][j + v[i]];

			}
		}

		int sum = accumulate(ALL(v), 0);



		if (sum % 2) {
			cout << "impossible" << endl;
			continue;
		}
		if (dp[n][sum / 2]) {
			cout << "possible" << endl;
		}
		else {
			cout << "impossible" << endl;
		}
	}
}
