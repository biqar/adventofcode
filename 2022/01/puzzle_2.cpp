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
//  freopen("input.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);

  int i, j, k;
  int test, t = 0, kase = 0;
  int curr = 0, top_three = 0;

  ifstream file("/Users/aislam6/workspace/projects/personal/adventofcode/2022/01/input.txt");
  vector<int> vec;
  string s;
  if (file.is_open()) {
    while (getline(file, s)) {
      if (s.empty()) {
        vec.push_back(curr);
        curr = 0;
      }
      else {
        curr += stoi(s);
      }
    }
  }

  sort(vec.begin(), vec.end());
  top_three = vec[vec.size() - 1] + vec[vec.size() - 2] +vec[vec.size() - 3];
  printf("%d\n", top_three);

  return 0;
}
