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
  freopen("/Users/aislam6/workspace/projects/personal/adventofcode/2022/06/input.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);

  int i, j, k;
  int test, t = 0, kase = 0;
  int pos = 0, len;
  string line;
  int count, from = 0, to = from + 4, prev_to;

  getline(cin, line);
  len = line.length();
  map<char, int> mp;
  bool done = false;

  while(true) {
    mp.clear();
    prev_to = to;
    for(int i=from; i<to; i+=1) {
      if(mp.find(line[i]) != mp.end()) {
        from = mp[line[i]] + 1;
        to = from + 4;
      }
      else mp[line[i]] = i;
    }

    if(prev_to == to) break;
    if(to > len) {
      to = -1;
      done = true;
      break;
    }
  }

  printf("%d\n", to);

  return 0;
}
