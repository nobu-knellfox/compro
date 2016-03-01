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
#define cx() real()
#define cy() imag()
#define px first
#define py second
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


class BestView {
public:
	int numberOfBuildings(vector <int> heights){

		vi a = heights;

		vi b(a.size(), 0);

		int n = a.size();

		REP(i, n) {
			double k = 0;
			double s = a[i];
			REPS(i + 1, j, n) {
				s = a[i] + (j - i)*k;
				if (s < a[j]) {
					k = max(k, ((double)(a[j] - a[i])) / (j - i));
					b[j]++;
					b[i]++;
				}
			}
		}

		reverse(ALL(a));
		reverse(ALL(b));

		REP(i, n) {
			double k = 0;
			double s = a[i];
			REPS(i + 1, j, n) {
				s = a[i] + (j - i)*k;
				if (s < a[j]) {
					k = max(k, ((double)(a[j] - a[i])) / (j - i));
					b[j]++;
					b[i]++;
				}
			}
		}


		REP(i, n) {
			REPS(i + 1, j, n) {
				if (a[i] == a[j]) {
					b[i]++;
				}
				if (a[i] <= a[j]) {
					break;
				}
			}
		}

		reverse(ALL(a));
		reverse(ALL(b));


		REP(i, n) {
			REPS(i + 1, j, n) {
				if (a[i] == a[j]) {
					b[i]++;
				}
				if (a[i] <= a[j]) {
					break;
				}
			}
		}

		return *max_element(ALL(b));
	}
};

