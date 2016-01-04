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
#define DIV 1000000007
#define QUICK_CIN ios::sync_with_stdio(false); cin.tie(0);
#define lowb lower_bound
#define upb upper_bound
#define ZERO(c,n) memset(&c[0],0,sizeof(int)*n)
#define ZERO2(c,n) memset(&c[0][0],0,sizeof(int)*n)
#define debug_input fstream cin("input.txt");ofstream cout("output.txt");
#define pb(a) push_back(a)
template<class T>void scan(vector<T> a, int n) { T c; REP(i, n) { cin >> c; a.push_back(c); } }
using vs = vector<string>; using vi = vector<int>; using pii = pair<int, int>; using psi = pair<string, int>; using vvi = vector<vi>;
template<class T>bool valid(T x, T w) { return 0 <= x&&x < w; }
int dx[4] = { 1, -1, 0, 0 }; int dy[4] = { 0, 0, 1, -1 };
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

using dc = deque<string>;
using vd = vector<dc>;
using mcv = map<string, vd>;

class InstantRunoff {
public:
	string outcome(string candidates, vector <string> ballots)
	{
		vs a = ballots;
		mcv mcv;
		int num = 0;
		num = a.size();

		for (auto x : a) {
			dc d;
			for (auto c : x) {
				d.push_back(to_string(c));
			}
			auto t = d.front();
			d.pop_front();
			mcv[t].push_back(d);
		}

		while (mcv.size()) {
			for (auto x : mcv) {
				if (num / 2 < x.second.size()) {
					return x.first ;
				}
			}

			auto minv = inf;
			vector<mcv::iterator> its;

			EACH(it, mcv) {
				if (it->second.size() < minv) {
					minv = it->second.size();
				}
				++it;
			}

			EACH(it, mcv) {
				if (it->second.size() == minv) {
					its.push_back(it);
				}
				++it;
			}

			for (auto it : its) {
				for (auto x : it->second) {
					if (x.empty())
						continue;
					auto t = x.front();
					x.pop_front();
					while (mcv.find(t) == mcv.end() && x.size()) {
						t = x.front();
						x.pop_front();
					}
					mcv[t].push_back(x);
				}
				mcv.erase(it);
			}
		}
		return "";
	}
};


signed main()
{
	QUICK_CIN;
	debug_input;

	vs a;
	int n;
	cin >> n;
	REP(i, n) {
		string c;
		cin >> c;
		a.pb(c);
	}

	mcv mcv;
	int num = 0;
	num = a.size();

	for (auto x : a) {
		dc d;
		for (auto c : x) {
			d.push_back(string({ c }));
		}
		auto t = d.front();
		d.pop_front();
		mcv[t].push_back(d);
	}

	while (mcv.size()) {
		for (auto x : mcv) {
			if (num / 2 < x.second.size()) {
				cout << x.first << endl;
				return 0;
			}
		}

		auto minv = inf;
		vector<mcv::iterator> its;

		EACH(it, mcv) {
			if (it->second.size() < minv) {
				minv = it->second.size();
			}
			++it;
		}

		EACH(it, mcv) {
			if (it->second.size() == minv) {
				its.push_back(it);
			}
			++it;
		}

		for (auto it : its) {
			for (auto x : it->second) {
				if (x.empty())
					continue;
				auto t = x.front();
				x.pop_front();
				while (mcv.find(t) == mcv.end() && x.size()) {
					t = x.front();
					x.pop_front();
				}
				mcv[t].push_back(x);
			}
			mcv.erase(it);
		}
	}
	cout << "" << endl;
}
