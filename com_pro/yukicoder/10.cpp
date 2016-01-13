#pragma once
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

const int Total = 100001;

int dp[51][Total];

signed main()
{
	QUICK_CIN;
	//fstream cin("debug.txt");
	//ofstream cout("result.txt");
	
	int n, t;
	cin >> n;
	cin >> t;

	vector<int> a;
	REP(i, n) {
		int c;
		cin >> c;
		a.push_back(c);
	}


	REP(i, 51) {
		REP(j, Total) {
			dp[i][j] = inf;
		}
	}

	dp[0][a[0]] = 0;

	REP(i, n-1) {
		REP(j, Total) {
			if (dp[i][j] != inf) {
				if (j + a[i+1] < Total)
					dp[i + 1][j + a[i+1]] = min(dp[i + 1][j + a[i+1]], dp[i][j] + ((int)0 << (n - i - 2)));

				if (j * a[i+1] < Total)
					dp[i + 1][j * a[i+1]] = min(dp[i + 1][j * a[i+1]], dp[i][j] + ((int)1 << (n - i - 2)));
			}
		}
	}

	auto ans = dp[n - 1][t];

	int count = 0;
	string an = "";

	while (ans) {
		count++;
		if (ans % 2) {
			an += "*";
		}
		else {
			an +=  "+";
		}
		ans >>= 1;
	}	

	auto dif = n - count - 1;
	
	while (dif-- > 0) {
		an +=  "+";
	}
	std::reverse(ALL(an));

	cout << an << endl;
}
