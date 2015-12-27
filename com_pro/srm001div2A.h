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
#define vscan(a) int _c_; cin >> _c_; (a).push_back(_c_);
#define debug_input fstream cin("input.txt");ofstream cout("output.txt");

template<class T>
bool valid(T x, T w) { return 0 <= x&&x < w; }

int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

using namespace std;

//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

class InstantRunoffVoting
{
	int winner(vector <string> voters)
	{

	}
};


signed main()
{
	QUICK_CIN;
	debug_input;
	vector <string> voters;
	int n;
	cin >> n;


	REP(i, n) {
		string a;
		cin >> a;
		voters.push_back(a);
	}

	using dei = deque<int>;
	using vdai = vector<dei>;
	using pvdai = pair<int, vdai>;

	int len = voters[0].size();

	map<int, vdai> ve;

	for (auto s : voters) {
		dei d;
		for (auto c : s) {
			d.push_back(c - '0');
		}
		auto te = d.front();
		d.pop_front();
		ve[te].push_back(d);
	}


	REP(i, len - 1) {
		auto ma = max_element(ALL(ve), [](pvdai a, pvdai b) {return  a.second.size() >= b.second.size(); });
		auto mi = min_element(ALL(ve), [](pvdai a, pvdai b) {return a.second.size() <= b.second.size(); });

		if (ma->second.size() > n / 2) {
			ve.erase(remove_if(ALL(ve), [=](vdai a) {a.size() < ma->second.size(); }), ve.end());
		}
		else {
			vector<int> aaa;
			for (auto it = ve.begin(); it != ve.end();it++) {
				if (it->second.size() == mi->second.size()) {
					aaa.push_back(it->first);
				}
			}
			for (auto xx : aaa) {
				for (auto x : ve[xx]) {
					while (ve.find(x.front()) == ve.end()) {
						x.pop_front();
					}
					int te = x.front();
					x.pop_front();
					ve[te].push_back(x);
				}
			}
			for (auto it = ve.begin(); it != ve.end();) {
				if (it->second.size() == 0) {

				}
			}
		}
	}

	cout << ()

	return 0;
}
