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
#define LL int  
#define int LL
#define INF  99999999
#define DEV 1000000007
#define QUICK_CIN ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
 
 
int N, K;
 
double R[101];
 
 
signed main()
{
	//QUICK_CIN;
	//ifstream cin("debug.txt");
	cin >> N >> K;
 
	REP(i, N){
		cin >> R[i];
	}
 
	sort(R, R + N);
 
	double nowrate = 0.0;
 
	REPA(N-K,i, N){
		nowrate = (nowrate + R[i]) / 2;
	}
 
	printf("%.7lf", nowrate);
 
}
