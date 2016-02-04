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

int comp(string str1, string str2)
{
	int mo1 = stoi(string({ str1[0],str1[1] }));
	int da1 = stoi(string({ str1[3],str1[4] }));

	int mo2 = stoi(string({ str2[0],str2[1] }));
	int da2 = stoi(string({ str2[3],str2[4] }));

	if (mo1 == mo2) {
		if (da1 != da2) {
			return da1 < da2 ? -1 : 1;
		}
		return 0;
	}
	return mo1 < mo2 ? -1 : 1;
}

string change(string str)
{
	int da1 = stoi(string({ str[3],str[4] }));

	if (da1 < 13) {
		return string({ str[3],str[4],str[2],str[0],str[1] });
	}
	else {
		return str;
	}
}

string dp[100000];

class DateFormat {
public:

	string fromEuropeanToUs(vector <string> dateList)
	{

		vs as = dateList;

		string str = "";

		for (auto x : as) {
			str += x;
		}

		stringstream ss(str);

		vs a;

		string temp;
		while (ss >> temp) {
			a.push_back(temp);
		}

		dp[0] = comp(a[0], change(a[0])) == -1 ? a[0] : change(a[0]);

		REPS(1, i, a.size()) {
			string mis = comp(a[i], change(a[i])) == -1 ? a[i] : change(a[i]);
			string mas = comp(a[i], change(a[i])) == -1 ? change(a[i]) : a[i];

			int ci = comp(dp[i - 1], mis);
			int ca = comp(dp[i - 1], mas);

			if (ci == -1) {
				dp[i] = mis;
			}
			else if (ca == -1) {
				dp[i] = mas;
			}
			else {
				return "";
			}
		}

		string ans = "";

		REP(i, a.size()) {
			ans += dp[i];
			ans += " ";
		}

		return ans.substr(0, ans.size() - 1);
	}
};
