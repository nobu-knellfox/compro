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

bool prime[200001];
bool syaku[10];

signed main()
{
	QUICK_CIN;
	//fstream cin("debug.txt");
	//ofstream cout("result.txt");
	
	int n, k;
	cin >> n >> k;

	prime[0] = prime[1] = true;

	for (int i = 2; i*i < 200001; ++i) {
		int j = i * 2;
		for (; j < 200001; j += i) {
			prime[j] = true;
		}
	}

	vector<int> pri;

	REP(i, 200001) {
		if (!prime[i]) {
			pri.push_back(i);
		}
	}


	auto f = [](int n) -> int{
		while (n / 10) {
			int temp = n;
			n = 0;
			while (temp) {
				n += temp % 10;
				temp /= 10;
			}
		}
		return n;
	};

	auto left = lower_bound(ALL(pri), n);
	auto right = upper_bound(ALL(pri), k);

	right = right - 1;

	int max_a = -1;
	int max_l = -1;
	int len = 0;

	for (auto i = left, j = left; i <= right;) {
		auto ik = f(*i);
		auto jk = f(*j);

		while (!syaku[ik] && i <= right) {
			syaku[ik] = true;
			++i;
			ik = f(*i);

			++len;
			if (max_l <= len) {
				max_a = *j;
				max_l = len;
			}
		}
		while (syaku[ik] && i <= right){
			syaku[jk] = false;
			++j;
			jk = f(*j);

			--len;
		}
	}

	cout << max_a << endl;

}
