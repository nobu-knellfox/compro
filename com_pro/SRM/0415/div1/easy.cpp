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
#define lint LL
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


class ShipLoading {
public:
	int minimumTime(vector <int> cranes, vector <string> boxes)
	{
		sort(ALL(cranes));

		vvi box;

		for (auto x : boxes) {
			vi a;
			stringstream ss;
			ss << x;
			string tmp;
			while (getline(ss, tmp, ' ')) {
				a.push_back(stoi(tmp));
			}
			box.push_back(a);
		}

		int count = 0;
		bool f = false;
		while (!box.empty()) {
			vi temp = cranes;
			EACH(it, box) {
				f = false;

				while (lower_bound(ALL(temp), *(it->begin())) != temp.end()) {
					temp.erase(lower_bound(ALL(temp), *(it->begin())));
					it->erase(it->begin());

					if (it->empty()) {
						it = box.erase(it);
						f = true;
						break;
					}
				}
				if (!f) {
					++it;
				}
			}
			count++;

			if (temp.size() == cranes.size()) {
				return -1;
			}
		}
		return count + 1;
	}
};
