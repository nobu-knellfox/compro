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
 
#define REP(i,n) for(int (i) = 0;(i) < (n) ; ++(i))
#define REPA(a,i,n) for(int (i) = (a) ; (i) < (n) ; ++(i))
#if defined(_MSC_VER)||__cplusplus > 199711L
#define AUTO(r,v) auto r = (v)
#else
#define AUTO(r,v) typeof(v) r = (v)
#endif
#define ALL(c) (c).begin() , (c).end()
#define EACH(it,c) for(AUTO(it,(c).begin());it != (c).end();++it)
#define LL long
#define int LL
#define INF  99999999999999
#define DEV 1000000007
#define QUICK_CIN ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
 
int T[5][5];
int N, K;
 
bool func(int i, int j,bool m[7]){
	if (i == N ){
		REP(a, 7){
			if (m[a])
				return true;
		}
		return false;
	}
 
	int temp = T[i][j];
 
	REP(a, 7){
		m[a] = bool(temp % 2) != m[a];
		temp /= 2;
	}
 
	bool f = true;
	REP(a, K){
		f &= func(i + 1, a, m);
	}
	return f;
}
 
bool aa[7];
 
signed main()
{
	QUICK_CIN;
	//ifstream cin("debug.txt");
	//ofstream cout("result.txt");
 
 
	cin >> N >> K;
 
 
	REP(i, N){
		REP(j, K){
			cin >> T[i][j];
		}
	}
 
	bool f = true;
	REP(a, K){
		f &= func(0, a, aa);
	}
 
	cout << (f ? "Nothing" : "Found") << endl;
}
