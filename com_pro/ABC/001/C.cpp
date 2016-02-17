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
#define INF 99999999;
#define QUICK_CIN ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
typedef vector<LL> ints; typedef pair<LL, LL> point; typedef vector<point> points;
 
string deg[] = { "N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW" ,"N"};
 
int dis(double n){
	if (n <= 0.2){
		return 0;
	}
	else if (n <= 1.5){
		return 1;
	}
	else if (n <= 3.3){
		return 2;
	}
	else if (n <= 5.4){
		return 3;
	}
	else if (n <= 7.9){
		return 4;
	}
	else if (n <= 10.7){
		return 5;
	}
	else if (n <= 13.8){
		return 6;
	}
	else if (n <= 17.1){
		return 7;
	}
	else if (n <= 20.7){
		return 8;
	}
	else if (n <= 24.4){
		return 9;
	}
	else if (n <= 28.4){
		return 10;
	}
	else if (n <= 32.6){
		return 11;
	}
	else{
		return 12;
	}
}
 
int main(){
	QUICK_CIN;
	long de, di;
	cin >> de >> di;
	
	de *= 10;
	de += 1125;
 
	string deg_ans = deg[de / 2250];
 
	int dis_ans = dis((round((10*(1.0*di) / 60)))/10);
	if (dis_ans)
		cout << deg_ans << " " << dis_ans << endl;
	else
		cout << "C" << " " << dis_ans << endl;
	return 0;
 
}
