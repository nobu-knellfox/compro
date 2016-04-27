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
#define LL long long 
#define int LL
#define INF  99999999999999
#define DEV 1000000007
#define QUICK_CIN ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
 
int DP[51][51][10010];
 
int A[50], B[50];
 
signed main()
{
	QUICK_CIN;
	//ifstream cin("debug.txt");
	//ofstream cout("result.txt");
 
	int W, N, K;
 
	cin >> W >> N >> K;
 
	REP(i, N){
		cin >> A[i] >> B[i];
	}
 
	REPA(1, i, N + 1){
		REPA(1, k, N + 1){
			REP(j, 10010){
				if (0 <= j - A[i - 1]){
					DP[i][k][j] = max(DP[i - 1][k - 1][j - A[i - 1]] + B[i - 1], DP[i - 1][k][j]);
				}
				else
					DP[i][k][j] = max(DP[i - 1][k][j], DP[i][k][j]);
			}
		}
	}
 
 
	cout << DP[N][K][W] << endl;
}
