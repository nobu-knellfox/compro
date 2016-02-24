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
#define lint LL
#define inf  ((int)1 << 30)
#define mod 1000000007
#define QUICK_CIN ios::sync_with_stdio(false); cin.tie(0);
#define lowb lower_bound
#define upb upper_bound
#define ZERO(c,n) memset(&c[0],0,sizeof(int)*n)
#define ZERO2(c,n) memset(&c[0][0],0,sizeof(int)*n)
#define pl(a) cout << ""#a": " << a << endl;
#ifdef _DEBUG
#define debug_io fstream cin("input.txt");ofstream cout("output.txt");
#else
#define debug_io ;
#endif
#define debug_input debug_io
#define pb(a) push_back(a)
template<class T>void scan(vector<T>& a, int n, istream& cin) { T c; REP(i, n) { cin >> c; a.push_back(c); } }
using vs = vector<string>; using vi = vector<int>; using pii = pair<int, int>; using psi = pair<string, int>; using vvi = vector<vi>;
template<class T>bool valid(T x, T w) { return 0 <= x&&x < w; }
int dx[4] = { 1, -1, 0, 0 }; int dy[4] = { 0, 0, 1, -1 };
////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////


class CountriesRanklist {
public:

	vector <string> findPlaces(vector <string> knownPoints)
	{
		int most = inf;

		map<string, vi> ma;

		vs input = knownPoints;

		for (auto x : input) {
			stringstream ss(x);

			string temp;
			while (ss >> temp) {
				string s, t;
				ss >> s >> t;

				ma[temp].push_back(stoi(t));
			}
		}

		for (auto x : ma) {
			for (auto y : x.second) {
				most = min(most, y - 1);
			}
		}

		using pis = pair<int, string>;

		vector<pis> low;
		vector<pis> high;

		for (auto x : ma) {
			int sum = 0;
			for (auto y : x.second) {
				sum += y;
			}

			low.emplace_back(sum, x.first);
			high.emplace_back(sum + (4 - x.second.size())*most, x.first);
		}

		sort(ALL(low), greater<pis>());
		sort(ALL(high), greater<pis>());

		vector<pis> low_res;
		vector<pis> high_res;

		map<string, pii> mma;

		for (auto x : high) {
			int now = 1;
			REP(i, low.size()) {
				if (x.second == low[i].second)
					continue;

				if (x.first >= low[i].first) {
					break;
				}
				now++;
			}
			mma[x.second].first = now;
		}

		for (auto x : low) {
			int now = 1;
			REP(i, high.size()) {
				if (x.second == high[i].second)
					continue;

				if (x.first >= high[i].first) {
					break;
				}
				now++;
			}
			mma[x.second].second = now;
		}

		vs ans;

		for (auto x : mma) {
			ans.emplace_back(x.first + " " + to_string(x.second.first) + " " + to_string(x.second.second));
		}

		for (auto x : ans) {
			cout << x << endl;
		}
		return ans;
	}
};

