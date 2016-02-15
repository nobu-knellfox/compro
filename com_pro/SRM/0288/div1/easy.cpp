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
#define inf  ((int)1 << 30)
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

struct P {
	int x, y, z;
};

map<string, vector<P>> ma;

class FindTriangle {
public:
	double largestArea(vector <string> points)
	{
		vs input = points;

		for (auto x : input) {
			stringstream ss(x);

			string temp;
			while (ss >> temp) {
				string a, b, c;
				ss >> a >> b >> c;
				ma[temp].push_back({ stoi(a),stoi(b),stoi(c) });
			}
		}

		double maxi = -inf;


		string sss[3] = { "R","G","B" };

		for (auto y : sss) {
			auto now = ma[y];
			REP(i, now.size()) {
				REPS(i + 1, j, now.size()) {
					REPS(j + 1, k, now.size()) {
						double dx = now[i].x - now[j].x;
						double dy = now[i].y - now[j].y;
						double dz = now[i].z - now[j].z;
						double a = dx*dx + dy*dy + dz*dz;

						dx = now[i].x - now[k].x;
						dy = now[i].y - now[k].y;
						dz = now[i].z - now[k].z;
						double b = dx*dx + dy*dy + dz*dz;

						dx = now[k].x - now[j].x;
						dy = now[k].y - now[j].y;
						dz = now[k].z - now[j].z;
						double c = dx*dx + dy*dy + dz*dz;

						double area = (2*(a*c + a*b + b*c) - a*a - b*b - c*c)/16;

						area = max(area, 0.0);

						maxi = max(maxi, area);
					}
				}
			}
		}


		auto nowR = ma["R"];
		auto nowG = ma["G"];
		auto nowB = ma["B"];
		REP(i, nowR.size()) {
			REP(j, nowG.size()) {
				REP(k, nowB.size()) {
					double dx = nowR[i].x - nowG[j].x;
					double dy = nowR[i].y - nowG[j].y;
					double dz = nowR[i].z - nowG[j].z;
					double a = dx*dx + dy*dy + dz*dz;

					dx = nowR[i].x - nowB[k].x;
					dy = nowR[i].y - nowB[k].y;
					dz = nowR[i].z - nowB[k].z;
					double b = dx*dx + dy*dy + dz*dz;

					dx = nowB[k].x - nowG[j].x;
					dy = nowB[k].y - nowG[j].y;
					dz = nowB[k].z - nowG[j].z;
					double c = dx*dx + dy*dy + dz*dz;

					double area = (2 * (a*c + a*b + b*c) - a*a - b*b - c*c) / 16;

					area = max(area, 0.0);

					maxi = max(maxi, area);
				}
			}
		}

		return sqrt(maxi);

	}
};
