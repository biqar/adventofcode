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

int get_score(char ch) {
  if(ch >= 'a' && ch <= 'z') return (ch - 'a' + 1);
  else return (ch - 'A' + 1 + 26);
}

int main() {
  freopen("/Users/aislam6/workspace/projects/personal/adventofcode/2022/04/input.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);

  int i, j, k;
  int test, t = 0, kase = 0;
  int score = 0, len, tmp;
  string line;
  vector<int> vec(4);

  while(getline(cin, line)) {
    len = line.length();

    for(int i=0; i<len; i+=1) {
      if(!(line[i] >= '0' && line[i] <= '9')) line[i] = ' ';
    }

    stringstream ss(line);
    while(ss >> tmp) {
      vec.push_back(tmp);
    }

    if((vec[0] <= vec[2] && vec[3] <= vec[1]) || (vec[2] <= vec[0] && vec[1] <= vec[3])) score += 1;

    vec.clear();
  }

  printf("%d\n", score);

  return 0;
}
