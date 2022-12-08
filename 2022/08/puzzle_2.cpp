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

  int curr_h, curr_s, ii, jj;
  int r, c;
  string line;
  int max_vis = 0;

  while(getline(cin, line)) {
    grid.push_back(line);
  }

  r = grid.size();
  c = grid[0].size();
  flg.resize(r, vector<int>(c, 0));

  for(int i=1; i<r-1; i+=1) {
    for (int j = 1; j < c-1; j += 1) {
      curr_h = (grid[i][j] - '0');
      curr_s = 1;

      // up
      ii = i - 1;
      while(ii >= 0 && (grid[ii][j] - '0') < curr_h) ii -= 1;
      if(ii < 0) ii += 1;
      curr_s *= (i - ii);
      assert(curr_s > 0 && "curr-score should be larger than Zero after going up.");

      // down
      ii = i + 1;
      while(ii < r && (grid[ii][j] - '0') < curr_h) ii += 1;
      if(ii == r) ii -= 1;
      curr_s *= (ii - i);
      assert(curr_s > 0 && "curr-score should be larger than Zero after going down.");

      // left
      jj = j - 1;
      while(jj >= 0 && (grid[i][jj] - '0') < curr_h) jj -= 1;
      if(jj < 0) jj += 1;
      curr_s *= (j - jj);
      assert(curr_s > 0 && "curr-score should be larger than Zero after going left.");

      // right
      jj = j + 1;
      while(jj < c && (grid[i][jj] - '0') < curr_h) jj += 1;
      if(jj == c) jj -= 1;
      curr_s *= (jj - j);
      assert(curr_s > 0 && "curr-score should be larger than Zero after going right.");

      flg[i][j] = curr_s;
    }
  }

  for(int i=0; i<r; i+=1) {
    for(int j=0; j<c; j+=1) {
      max_vis = max(max_vis, flg[i][j]);
    }
  }

//  for(int i=0; i<r; i+=1) {
//    for(int j=0; j<c; j+=1) {
//      if(flg[i][j] == 363825) {
//        cout << i << " " << j << " " << grid[i][j] << endl;
//        cout << grid[i-1][j] << " " << grid[i][j+1] << " " << grid[i+1][j] << " " << grid[i][j-1] << endl;
//
//        curr_h = (grid[i][j] - '0');
//        curr_s = 1;
//
//        // up
//        ii = i - 1;
//        while(ii >= 0 && (grid[ii][j] - '0') < curr_h) ii -= 1;
//        curr_s *= (i - ii);
//        assert(curr_s > 0 && "curr-score should be larger than Zero after going up.");
//        cout << "went to up: " << (i - ii) << endl;
//
//        // down
//        ii = i + 1;
//        while(ii < r && (grid[ii][j] - '0') < curr_h) ii += 1;
//        curr_s *= (ii - i);
//        assert(curr_s > 0 && "curr-score should be larger than Zero after going down.");
//        cout << "went to down: " << (ii - i) << endl;
//
//        // left
//        jj = j - 1;
//        while(jj >= 0 && (grid[i][jj] - '0') < curr_h) jj -= 1;
//        curr_s *= (j - jj);
//        assert(curr_s > 0 && "curr-score should be larger than Zero after going left.");
//        cout << "went to left: " << (j - jj) << endl;
//
//        // right
//        jj = j + 1;
//        while(jj < c && (grid[i][jj] - '0') < curr_h) jj += 1;
//        curr_s *= (jj - j);
//        assert(curr_s > 0 && "curr-score should be larger than Zero after going right.");
//        cout << "went to right: " << (jj - j) << endl;
//      }
//    }
//  }

  printf("%d\n", max_vis);

  return 0;
}
