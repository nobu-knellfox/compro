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
 
#define REP(i,n) for(int (i) = 0;(i) < (n) ; ++(i))
#define REPA(a,i,n) for(int (i) = (a) ; (i) < (n) ; ++(i))
#if defined(_MSC_VER)||__cplusplus > 199711L
#define AUTO(r,v) auto r = (v)
#else
#define AUTO(r,v) typeof(v) r = (v)
#endif
#define ALL(c) (c).begin() , (c).end()
#define EACH(it,c) for(AUTO(it,(c).begin());it != (c).end();++it)
#define LL long long 
#define int long
#define INF  99999999;
#define QUICK_CIN ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
 
bool relation[12][12];
 
 
signed main()
{
	QUICK_CIN;
	int n, m;
 
	cin >> n >> m;
	REP(i, m){
		int a, b;
		cin >> a >> b;
		relation[a-1][b-1] = relation[b-1][a-1] = true;
	}
 
	int maxi = 0;
	REP(i, n){
		bool prospective[13];//候補
		fill(prospective, prospective + n, false);
 
		REP(j, n){
			prospective[j] = relation[i][j];
		}
		REP(j, n){
			if (prospective[j]){
				REP(k, n){
					if (j != k && prospective[k]){
						prospective[k] &= relation[j][k];
					}
				}
			}
		}
		maxi = max(maxi, (int)count(prospective, prospective + n, true)+1);
	}
	cout << maxi << endl;
	return 0;
}
