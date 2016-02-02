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
using namespace std;
#define REP(i,n) for(int (i) = 0;(i) < (n) ; ++(i))
#define REPS(a,i,n) for(int (i) = (a) ; (i) < (n) ; ++(i))
#if defined(_MSC_VER)||__cplusplus > 199711L
#define AUTO(r,v) auto r = (v)
#else
#define AUTO(r,v) typeof(v) r = (v)
#endif
#define ALL(c) (c).begin() , (c).end()
#define EACH(it,c) for(AUTO(it,(c).begin());it != (c).end();)
#define LL long long
#define int LL
#define inf  ((int)1 << 54)
#define mod 1000000007
#define QUICK_CIN ios::sync_with_stdio(false); cin.tie(0);
#define lowb lower_bound
#define upb upper_bound
#define ZERO(c,n) memset(&c[0],0,sizeof(int)*n)
#define ZERO2(c,n) memset(&c[0][0],0,sizeof(int)*n)
#define debug_input fstream cin("input.txt");ofstream cout("output.txt");
#define pb(a) push_back(a)
template<class T>void scan(vector<T>& a, int n, istream& cin) { T c; REP(i, n) { cin >> c; a.push_back(c); } }
using vs = vector<string>; using vi = vector<int>; using pii = pair<int, int>; using psi = pair<string, int>; using vvi = vector<vi>;
template<class T>bool valid(T x, T w) { return 0 <= x&&x < w; }
int dx[4] = { 1, -1, 0, 0 }; int dy[4] = { 0, 0, 1, -1 };
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

struct edge {
	int to, cost;
};

map<int, vector<edge>> majidesuno;

bool ed[100000];

int mdist[1000][1000];
int dist[1000][1000];

signed main()
{
	QUICK_CIN;
	//	debug_input;

	int n;
	cin >> n;
	vector<vector<edge>> gra(n);

	int m;
	cin >> m;

	int s, g;
	cin >> s >> g;

	REP(i, 1000) {
		REP(j, 1000) {
			mdist[i][j] = inf;
			dist[i][j] = inf;
			if (i == j) {
				dist[i][j] = 0;
			}
		}
	}

	REP(i, m) {
		int h;
		cin >> h;

		int s1, g1, c1;

		vi s, w;

		scan(s, h, cin);
		scan(w, h - 1, cin);

		int sum = 0;

		REP(i, h - 1) {
			gra[s[i]].push_back({ s[i + 1],w[i] });
			gra[s[i + 1]].push_back({ s[i],w[i] });

			dist[s[i]][s[i + 1]] = dist[s[i + 1]][s[i]] = w[i];
			sum += w[i];
		}

		majidesuno[s[0]].push_back({ s[h - 1],sum });
	}

	REP(k, n) {
		REP(i, n) {
			REP(j, n) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	queue<edge> que;

	que.push({ s,0 });

	int ans = 0;

	while (!que.empty()) {
		auto now = que.front();
		que.pop();
		ed[now.to] = true;

		if (now.to == g) {
			break;
		}

		if (majidesuno.find(now.to) != majidesuno.end()) {
			int temp = inf;
			for (auto x : majidesuno[now.to]) {
				temp = min(dist[x.to][g] + x.cost + now.cost, temp);
			}
			ans = max(temp, ans);
		}

		for (auto x : gra[now.to]) {
			if (!ed[x.to]) {
				que.push({ x.to, now.cost + x.cost});
			}
		}
	}

	cout << ans << endl;
}

