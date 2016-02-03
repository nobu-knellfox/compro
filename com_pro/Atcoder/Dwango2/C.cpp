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
#define RREP(i,n) for(int (i) = n-1;(i) >= 0 ; --i)
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
	int to, cost,sum;
};

vector<edge> graph[30000];

bool ed[30000];

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

	queue<int> endi;

	REP(i, m) {
		int h;
		cin >> h;

		int s1, g1, c1;

		vi s, w;

		scan(s, h, cin);
		scan(w, h - 1, cin);

		int sum = 0;

		RREP(i, h-1) {
			graph[s[i]].push_back({ s[i + 1],w[i],sum*2 });
			graph[s[i + 1]].push_back({ s[i],w[i],sum*2 });
			sum += w[i];

			if (i == h - 2) {
				endi.push(s[i+1]);
			}
		}
	}

	auto comp = [](edge a, edge b)
	{
		return a.sum + a.cost > b.sum + b.cost;
	};


	priority_queue<edge, vector<edge>, decltype(comp)> que(comp);


	int ans = 0;

	while (endi.size()) {
		auto xx = endi.front();
		endi.pop();
		
		que.push({ xx,0,0 });
		while (!que.empty()) {
			auto now = que.top();
			que.pop();
			ed[now.to] = true;

			if (now.to == g) {
				tcost[xx] 
				break;
			}

			for (auto x : graph[now.to]) {
				if (!ed[x.to]) {
					que.push({ x.to, now.cost + x.cost ,max(now.sum,x.sum) });
				}
			}
		}
	}








	priority_queue<edge, vector<edge>, decltype(comp)> que(comp);

	que.push({ s,0,0 });

	int ans = 0;

	while (!que.empty()) {
		auto now = que.top();
		que.pop();
		ed[now.to] = true;

		if (now.to == g) {
			ans = now.sum + now.cost;
			break;
		}

		for (auto x : graph[now.to]) {
			if (!ed[x.to]) {
				que.push({x.to, now.cost + x.cost ,max(now.sum,x.sum) });
			}
		}
	}

	cout << ans << endl;
}

;
