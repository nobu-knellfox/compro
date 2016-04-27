#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <math.h>
#include <functional>
#include <algorithm>
#include <utility>
#include <numeric>
 
typedef long long Int; 
#pragma warning(disable : 4996)
#define REP(i,n) for(int i = 0 ; i < n ; ++i)
#define REPS(a,i,n) for(int i = a ; i < n ; ++i)
using namespace std;
 
typedef pair<int, int> Pa;
 
 
 
int tile[11][11];
 
int main(){
	int n, m;
 
	cin >> n >> m;
 
	REP(i, m){
		int a, b;
		cin >> a >> b;
 
		tile[a-1][b-1] = tile[b-1][a-1] = 1;
	}
 
	REP(i, n){
		int ed[11];
		fill(ed, ed + 11, 0);
		ed[i] = 1;
		REP(j, n){
			if (tile[i][j]){
				REP(k, n){
					if (tile[j][k])
						ed[k] = 1;
				}
			}
		}
		ed[i] = 0;
		REP(j, n){
			if (tile[i][j])
				ed[j] = 0;
		}
 
		auto ans = accumulate(ed, ed + 11, 0);
 
		cout << ans << endl;
	}
 
	return 0;
}
