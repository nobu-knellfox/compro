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
#define inf  99999999
#define div 1000000007
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

const int N = 10001;

bool prime[N+100];

bool dp[N];

signed main()
{
	QUICK_CIN;
	//fstream cin("debug.txt");
	//ofstream cout("result.txt");


	int n;
	cin >> n;


	prime[0] = prime[1] = true;

	for (int i = 2; i*i < N+100; ++i) {
		int j = i * 2;
		for (; j < N+100; j += i) {
			prime[j] = true;
		}
	}

	vector<int> pri;

	REP(i, N+100) {
		if (!prime[i]) {
			pri.push_back(i);
		}
	}

	//false‚ÌŽž‚É•‰‚¯‚é
	dp[0] = dp[1] = true;

	for (int i = 0; i < N; ++i) {
		int x = 0;
		while (pri[x] <= i) {
			dp[i] |= !dp[i - pri[x++]];
			if (dp[i])break;
		}
	}

	if (dp[n]) {
		cout << "Win" << endl;
	}
	else {
		cout << "Lose" << endl;
	}
}
