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

vector<string> grid;
vector<vector<int>> flg;

int main() {
  freopen("/Users/aislam6/workspace/projects/personal/adventofcode/2022/08/input.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);

  int curr;
  int r, c;
  string line;
  int total_vis = 0;

  while(getline(cin, line)) {
    grid.push_back(line);
  }

  r = grid.size();
  c = grid[0].size();
  flg.resize(r, vector<int>(c, 0));

  for(int i=0; i<r; i+=1) {
    // left-to-right
    curr = -1;
    for(int j=0; j<c; j+=1) {
      if(curr < (grid[i][j] - '0')) {
        flg[i][j] = 1;
        curr = (grid[i][j] - '0');
      }
    }

    // right-to-left
    curr = -1;
    for(int j=c-1; j>=0; j-=1) {
      if(curr < (grid[i][j] - '0')) {
        flg[i][j] = 1;
        curr = (grid[i][j] - '0');
      }
    }
  }

  for(int j=0; j<c; j+=1) {
    // top-to-bottom
    curr = -1;
    for(int i=0; i<r; i+=1) {
      if(curr < (grid[i][j] - '0')) {
        flg[i][j] = 1;
        curr = (grid[i][j] - '0');
      }
    }

    // bottom-to-top
    curr = -1;
    for(int i=r-1; i>=0; i-=1) {
      if(curr < (grid[i][j] - '0')) {
        flg[i][j] = 1;
        curr = (grid[i][j] - '0');
      }
    }
  }

  for(int i=0; i<r; i+=1) {
    for(int j=0; j<c; j+=1) {
      if(flg[i][j]) total_vis += 1;
    }
  }

  printf("%d\n", total_vis);

  return 0;
}
