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

signed main()
{
	QUICK_CIN;
	//fstream cin("debug.txt");
	//ofstream cout("result.txt");

	vector<int>a, b;
	int c;

	REP(i, 2) {
		int c;
		cin >> c;
		a.push_back(c);
	}
	REP(i, 2) {
		int c;
		cin >> c;
		b.push_back(c);
	}

	cin >> c;
	bool fa(false), fb(false);

	REP(i, 2) {
		if (a[i] == c)fa = true;
		if (b[i] == c)fb = true;
	}

	auto func = [](vector<int> an)
	{
		sort(ALL(an));

		cout << an.size() << endl;

		for (auto x : an) {
			cout << x << endl;
		}
	};

	vector<int> ans;

	if (fa && !fb) {
		ans.push_back(b[0]);
		if (b[0] != b[1]) {
			ans.push_back(b[1]);
		}

		func(ans);

		return 0;
	}
	if (!fa && fb) {
		ans.push_back(a[0]);
		if (a[0] != a[1]) {
			ans.push_back(a[1]);
		}

		func(ans);

		return 0;
	}

	if (fa && fb) {
		vector<int> ans = { a[0] , a[1] , b[0] , b[1] };
		sort(ALL(ans));
		ans.erase(unique(ALL(ans)), ans.end());
		func(ans);
		return 0;
	}



	return 0;
}
