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

using P = pair<int, int>;

signed main()
{
	QUICK_CIN;
	//fstream cin("debug.txt");
	//ofstream cout("result.txt");

	int n;
	cin >> n;
	vector<int> a, b;

	REP(i, n) {
		int c;
		cin >> c;
		a.push_back(c);
	}

	REP(i, n) {
		int c;
		cin >> c;
		b.push_back(c / 2);
	}

	auto comp = [](P a, P b)
	{
		if (a.first > b.first) {
			return true;
		}
		else if (a.first == b.first) {
			return a.second >= b.second;
		}
		return false;
	};

	int min_n = inf;

	//first = ���x�� , second = �퓬��
	priority_queue<P, vector<P>, decltype(comp)> que(comp);


	for (int it = 0; it < n; ++it) {
		for (int i = 0; i < a.size(); ++i) {
			que.emplace(a[i], 0);
		}

		for (int ii = it,i = 0; i < b.size(); ++i,++ii) {
			ii %= b.size();

			auto now = que.top();
			que.pop();

			now.first += b[ii];
			now.second++;

			que.push(now);
		}

		int max_n = -1;
		while (!que.empty()) {
			auto x = que.top();
			que.pop();

			max_n = max(max_n, x.second);
		}

		min_n = min(min_n, max_n);

	}

	cout << min_n << endl;
}
