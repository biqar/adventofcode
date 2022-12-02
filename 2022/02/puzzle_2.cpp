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

#define OP_ROCK "A"
#define OP_PAPER "B"
#define OP_SCISSOR "C"

#define SELF_LOOSE "X"
#define SELF_DRAW "Y"
#define SELF_WIN "Z"

#define ROCK_SCORE 1
#define PAPER_SCORE 2
#define SCISSOR_SCORE 3

#define LOOSE_SCORE 0
#define DRAW_SCORE 3
#define WIN_SCORE 6

int main() {
  freopen("/Users/aislam6/workspace/projects/personal/adventofcode/2022/02/input.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);

  int i, j, k;
  int test, t = 0, kase = 0;
  int score = 0;
  string op, self, line;

  while(getline(cin, line)) {
    stringstream ss(line);
    ss >> op;
    ss >> self;

    if(op == OP_ROCK) {
      if(self == SELF_LOOSE) {
        score += (SCISSOR_SCORE + LOOSE_SCORE);
      }
      if(self == SELF_DRAW) {
        score += (ROCK_SCORE + DRAW_SCORE);
      }
      if(self == SELF_WIN) {
        score += (PAPER_SCORE + WIN_SCORE);
      }
    }
    if(op == OP_PAPER) {
      if(self == SELF_LOOSE) {
        score += (ROCK_SCORE + LOOSE_SCORE);
      }
      if(self == SELF_DRAW) {
        score += (PAPER_SCORE + DRAW_SCORE);
      }
      if(self == SELF_WIN) {
        score += (SCISSOR_SCORE + WIN_SCORE);
      }
    }
    if(op == OP_SCISSOR) {
      if(self == SELF_LOOSE) {
        score += (PAPER_SCORE + LOOSE_SCORE);
      }
      if(self == SELF_DRAW) {
        score += (SCISSOR_SCORE + DRAW_SCORE);
      }
      if(self == SELF_WIN) {
        score += (ROCK_SCORE + WIN_SCORE);
      }
    }
  }

  printf("%d\n", score);

  return 0;
}
