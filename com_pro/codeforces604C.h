
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

int score[5] = { (int)(500 * 0.3),(int)(1000 * 0.3),(int)(1500 * 0.3),(int)(2000 * 0.3),(int)(2500 * 0.3) };
int divscore[5] = { 2,4,6,8,10 };


bool f(deque<int> bells, int nbox, int size)
{
	nbox--;

	while (!bells.empty()) {
		if (nbox < 0) {
			return false;
		}

		auto x = bells.front();
		bells.pop_front();

		if (bells.size() > 0) {
			auto y = bells.back();

			if (x + y <= size) {
				bells.pop_back();
			}
			nbox--;
			continue;
		}
	}
	return true;
}

signed main()
{
	QUICK_CIN;
	//fstream cin("input.txt");
	//ofstream cout("result.txt");

	int n, k;
	deque<int> s;
	cin >> n >> k;

	REP(i, n) {
		int c;
		cin >> c;
		s.push_front(c);
	}

	int left, right, middle;
	left = s[0] - 1; right = s[0] * 2 + 1;

	while (right - left > 1) {
		middle = (left + right) / 2;
		(f(s, k, middle) ? right : left) = middle;
	}

	cout << right << endl;
}
