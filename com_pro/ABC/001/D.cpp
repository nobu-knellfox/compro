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
#define INF  99999999
#define DEV 1000000007
#define QUICK_CIN ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
 
int timeu[24 * 60+2];
 
signed main()
{
	QUICK_CIN;
	//ifstream cin("debug.txt");
	//ofstream cout("result.txt");
 
	int n;
	cin >> n;
 
	REP(i, n){
		string a;
		cin >> a;
 
		int n1 = (a[0] - '0') * 10 + (a[1] - '0');
		int n2 = (a[2] - '0') * 10 + (a[3] - '0');
		if (n2%10)
			n2 = n2%10 < 5 ? n2/10*10 : n2/10*10+5;
 
		int n3 = (a[5] - '0') * 10 + (a[6] - '0');
		int n4 = (a[7] - '0') * 10 + (a[8] - '0');
		if (n4%10)
			n4 = n4%10 <= 5 ? n4/10*10+5 : (n4/10 == 5?++n3,0:(n4/10+1)*10);
 
		timeu[n1 * 60 + n2] += 1;
		timeu[n3 * 60 + n4 + 1] += -1;
	}
 
	REP(i, 24*60+1){
		timeu[i + 1] += timeu[i];
	}
 
	REP(i, 24*60+1){
		while (!timeu[i]  && i < 24*60+1)
			++i;
		int a = i;
		if (i == 24 * 60+1)
			break;
		while (timeu[i+1] && i < 24*60)
			++i;
		cout.width(2);
		cout.fill('0');
		cout << a / 60;
		cout.width(2);
		cout.fill('0');
		cout << a % 60 << "-";
		cout.width(2);
		cout.fill('0');
		cout << i / 60;
		cout.width(2);
		cout.fill('0');
		cout << i % 60 << endl;
	}
 
}
