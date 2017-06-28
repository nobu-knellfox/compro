#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int (i) = 0;(i) < (n) ; ++(i))
#define REPS(a,i,n) for(int (i) = (a) ; (i) < (n) ; ++(i))
#define REVERSE(i,n) for(int (i) = n-1;(i) >= 0 ; --i)
#define ALL(c) (c).begin() , (c).end()
#define LL long long
#define int LL
#define inf  (1LL << 60)
#define mod 1000000007
#define QUICK_CIN ios::sync_with_stdio(false); cin.tie(0);
#define lower lower_bound
#define upper upper_bound
#define ZERO(c,n) memset(&c[0],0,sizeof(int)*n)
#define ZERO2(c,n) memset(&c[0][0],0,sizeof(int)*n
#define pl(a) cout << ""#a": " << a << endl;
#ifdef _DEBUG
#define debug_io fstream cin("input.txt");ofstream cout("output.txt");
template<class T>fstream& operator>>(fstream& is, vector<T>& v)
{
	int n = v.size();
	REP(i, n) {
		is >> v[i];
	}
	return is;
}
#else
#define debug_io ;
#endif
#define debug_input debug_io
#define DOWN(T) std::greater<T>()
template<class T>istream& operator>>(istream& is, vector<T>& v)
{
	int n = v.size();
	REP(i, n) {
		is >> v[i];
	}
	return is;
}
using vs = vector<string>; using vi = vector<int>; using pii = pair<int, int>;
using psi = pair<string, int>; using vvi = vector<vi>; using pss = pair<string, string>;
using vpii = vector<pii>;
template<class T>bool valid(T x, T w) { return 0 <= x&&x < w; }
int dx[4] = { 1, -1, 0, 0 }; int dy[4] = { 0, 0, 1, -1 };
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

signed main()
{
	QUICK_CIN;
	debug_input;

}