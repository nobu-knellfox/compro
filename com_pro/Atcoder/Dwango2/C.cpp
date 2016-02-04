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
#define REVERSE(i,n) for(int (i) = n-1;(i) >= 0 ; --i)
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
	int to, cost, sum, endi;
};

vector<edge> graph[30000];

bool ed[30000];
bool ed1[30000];

int tcost[30000];

signed main()
{
	QUICK_CIN;
	debug_input;

	int n;
	cin >> n;

	int m;
	cin >> m;

	int s, g;
	cin >> s >> g;


	REP(i, m) {
		int h;
		cin >> h;

		int s1, g1, c1;

		vi s, w;

		scan(s, h, cin);
		scan(w, h - 1, cin);

		int sum = 0;

		REVERSE(i, h - 1) {
			sum += w[i];
			graph[s[i]].push_back({ s[i + 1],w[i],sum,s[h - 1] });
		}

		sum = 0;
		REP(i, h - 1) {
			sum += w[i];
			graph[s[i + 1]].push_back({ s[i],w[i],sum,s[0] });
		}
	}

	auto comp = [](edge a, edge b)
	{
		return a.sum > b.sum;
	};

	auto comp1 = [](edge a, edge b)
	{
		return a.cost > b.cost;
	};

	priority_queue<edge, vector<edge>, decltype(comp1)> que1(comp1);

	que1.push({ g,0,0 });

	while (!que1.empty()) {
		auto now = que1.top();
		que1.pop();

		if (!ed1[now.to])
			tcost[now.to] = now.cost;

		ed1[now.to] = true;

		for (auto x : graph[now.to]) {
			if (!ed1[x.to]) {
				que1.push({ x.to, now.cost + x.cost });
			}
		}
	}

	priority_queue<edge, vector<edge>, decltype(comp)> que(comp);

	que.push({ s,0,0 });

	int ans = inf;

	while (!que.empty()) {
		auto now = que.top();
		que.pop();

		if (now.to != g) {
			ed[now.to] = true;
		}
		else {
			ans = min(ans, now.sum);
		}

		for (auto x : graph[now.to]) {
			if (!ed[x.to]) {
				que.push({ x.to, now.cost + x.cost ,max(now.sum,now.cost + x.sum + tcost[x.endi]) });
			}
		}
	}

	cout << ans << endl;
}
