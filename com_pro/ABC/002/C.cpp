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
 
typedef pair<double, double> point;
 
point MakeVec(point a, point b)
{
	return point(b.first - a.first, b.second - a.second);
}
 
double CrossProduct(point a, point b, point c, point d)
{
	point ab = MakeVec(a, b);
	point cd = MakeVec(c, d);
 
	return ab.first*cd.second - ab.second*cd.first;
}
 
double TriangleArea(point a, point b, point c)
{
	return abs(CrossProduct(a, b, a, c) / 2);
}
 
signed main()
{
	//QUICK_CIN;
 
	point a, b, c;
 
	cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
 
	printf("%.2lf\n", TriangleArea(a, b, c));
 
	return 0;
}
