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
#define debug_input fstream cin("input.txt");ofstream cout("output.txt");

template<class T>
bool valid(T x, T w) { return 0 <= x&&x < w; }

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

using namespace std;

//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

bool ed[101][101];
int w, h;
int m[101][101];

bool dfs(int x, int y)
{
	auto num = m[x][y];
	bool led[101][101] = {false};

	if (ed[x][y])return false;

	stack<pair<pair<int,int>, pair<int,int>>> que;
	que.push({ { x,y },{-1,-1} });

	while (que.size()) {
		auto now = que.top();
		que.pop();

		if (led[now.first.first][now.first.second])
			return true;

		led[now.first.first][now.first.second] = true;
		ed[now.first.first][now.first.second] = true;

		REP(i, 4) {
			auto nx = now.first.first + dx[i];
			auto ny = now.first.second + dy[i];

			if (nx == now.second.first && ny == now.second.second)
				continue;

			if (valid(nx, h) && valid(ny, w) && num == m[nx][ny]) {
				que.push({ { nx,ny }, {now.first.first , now.first.second } });
			}
		}
	}
	return false;
}

signed main()
{
	QUICK_CIN;
	//debug_input;

	cin >> w >> h;

	REP(i, h) {
		REP(j, w) {
			cin >> m[i][j];
		}
	}
	REP(i, h) {
		REP(j, w) {
			if (dfs(i, j)) {
				cout << "possible" << endl;
				return 0;
			}
		}
	}
	cout << "impossible" << endl;
}
