#pragma warning ( disable : 4786 )

#include <iostream>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>

#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <fstream>

using namespace std;

//#define _rep( i, a, b, x ) for( __typeof(b) i = ( a ); i <= ( b ); i += x )
#define _rep(i, a, b, x) for( i = ( a ); i <= ( b ); i += x )
#define rep(i, n) _rep( i, 0, n - 1, 1 )

#define ff first
#define ss second

#define pii pair< int, int >
#define psi pair< string, int >

#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

#define set(p) memset(p, -1, sizeof(p))
#define clr(p) memset(p, 0, sizeof(p))

//typedef long long i64;
//typedef __int64 i64;
typedef long double ld;

//const double pi = (2.0*acos(0.0));
const double pi = acos(-1.0);
const double eps = 1e-9;
const int inf = (1 << 28);
const int MAX = 1005;

int main() {
  freopen("/Users/aislam6/workspace/projects/personal/adventofcode/2022/12/input.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);

  string line;
  vector<string> grid;

  while(getline(cin, line)) {
    grid.push_back(line);
  }

  int r = grid.size(), c = grid[0].size();
  pair<int, int> nd, u, v;

  for(int i=0; i<r; i+=1) {
    for(int j=0; j<c; j+=1) {
      if(grid[i][j] == 'S') {
        grid[i][j] = 'a';
      }
      if(grid[i][j] == 'E') {
        nd = make_pair(i, j);
        grid[i][j] = 'z';
      }
    }
  }

//  for(string str : grid) cout << str << endl;

  vector<vector<int>> dir{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
  vector<vector<int>> dist(r, vector<int>(c, inf));
  queue<pair<int, int>> q;
  q.push(nd);
  dist[nd.first][nd.second] = 0;

  while(!q.empty()) {
    u = q.front(); q.pop();
//    cout << u.first << " " << u.second << endl;

    for(vector<int>& d : dir) {
      v.first = u.first + d[0];
      v.second = u.second + d[1];

      if(v.first < 0 || v.first >= r || v.second < 0 || v.second >= c) continue;
//      cout << v.first << " " << v.second << " " << grid[v.first][v.second] << endl;
      if(grid[u.first][u.second] - 'a' > grid[v.first][v.second] - 'a' + 1) continue;
//      cout << "passed" << endl;
      if(dist[v.first][v.second] > dist[u.first][u.second] + 1) {
        dist[v.first][v.second] = dist[u.first][u.second] + 1;
        q.push(v);
      }
    }
  }

  int min_dist = inf;
  for(int i=0; i<r; i+=1) {
    for (int j = 0; j < c; j += 1) {
      if (grid[i][j] == 'a') {
        min_dist = min(min_dist, dist[i][j]);
      }
    }
  }

  printf("%d\n", min_dist);

  return 0;
}
