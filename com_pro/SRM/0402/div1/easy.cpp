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

int n;

map<string, double> memo;

double f(vi aa)
{
	bool ff = false;

	REP(i, n) {
		if (aa[i] != i + 1) {
			ff = true;
		}
	}

	if (!ff) {
		return 0;
	}

	string str = "";

	for (auto x : aa) {
		str += to_string(x);
	}

	if (memo.find(str) != memo.end()) {
		return memo[str];
	}

	int num = 0;

	REP(i, n) {
		REPS(i + 1, j, n) {
			if (aa[i] > aa[j]) {
				num++;
			}
		}
	}

	double sum = 0;

	REP(i, n) {
		REPS(i + 1, j, n) {
			if (aa[i] > aa[j]) {
				swap(aa[i], aa[j]);
				sum += (1.0 / num)*(f(aa) + 1);
				swap(aa[i], aa[j]);
			}
		}
	}


	return memo[str] = sum;

}


class RandomSort {
public:


	double getExpected(vector <int> permutation)
	{


		vi a = permutation;

		n = a.size();

		return f(a);

	}
};
