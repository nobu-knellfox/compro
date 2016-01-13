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

using P = pair<int, pair<int, int>>;

struct Node {
	int to, cost, time;
};

signed main()
{
	QUICK_CIN;
	//fstream cin("debug.txt");
	//ofstream cout("result.txt");
	
	int n, c, v;

	cin >> n >> c >> v;

	vector<int> s, t, y, m;
	vector<Node> to[51];

	REP(i, v) {
		int c;
		cin >> c;
		s.push_back(c);
	}

	REP(i, v) {
		int c;
		cin >> c;
		t.push_back(c);
	}

	REP(i, v) {
		int c;
		cin >> c;
		y.push_back(c);
	}

	REP(i, v) {
		int c;
		cin >> c;
		m.push_back(c);
	}

	REP(i, v) {
		to[s[i]].push_back({ t[i],y[i],m[i] });
	}


	priority_queue<P,vector<P>,greater<P>> que;

	P p(0,pair<int,int>(1,0));
	que.push(p);

	while (!que.empty()) {
		auto now = que.top();
		que.pop();

		if (now.second.first == n) {
			cout << now.first << endl;
			return 0;
		}

		for (auto x : to[now.second.first]) {
			if (now.second.second + x.cost <= c) {
				que.push(P(now.first + x.time, pair<int,int>(x.to,now.second.second + x.cost)));
			}
		}
	}
	cout << -1 << endl;

}
