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
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <fstream>
#include <regex>

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

const long long int targeted_row = 2000000;

vector<pair<pair<long long int, long long int>, long long int>> sensors;
vector<pair<long long int, long long int>> beacons;
unordered_set<long long int> marked_cols;

int main() {
  freopen("/Users/aislam6/workspace/projects/personal/adventofcode/2022/15/input.txt", "r", stdin);
//  freopen("/Users/aislam6/workspace/projects/personal/adventofcode/2022/14/output.txt", "w", stdout);

  string line;
  int len;
  long long int sx, sy, bx, by, dist;

  while (getline(cin, line)) {
    len = line.size();
    /// note: potential bug here; missing minus sign in the numbers; it took 3 hours for me to find it during part-2.
    for(int i=0; i<len; i+=1) if(!(line[i] >= '0' && line[i] <= '9')) line[i] = ' ';

    stringstream ss(line);
    ss >> sy;
    ss >> sx;
    ss >> by;
    ss >> bx;

    dist = abs(sx - bx) + abs(sy - by);

//    cout << sx << " " << sy << " " << bx << " " << by << " " << dist << endl;

    sensors.push_back(make_pair(make_pair(sx, sy), dist));
    if(bx == targeted_row) beacons.push_back(make_pair(bx, by));
  }

  int delta_col;
  for(const auto& s : sensors) {
    if(s.first.first == targeted_row ||
        (s.first.first < targeted_row && s.first.first + s.second >= targeted_row) ||
        (s.first.first > targeted_row && s.first.first - s.second <= targeted_row)) {
      delta_col = s.second - abs(s.first.first - targeted_row);

      for(long long int j=s.first.second - delta_col; j<=s.first.second + delta_col; j+=1) {
        marked_cols.insert(j);
      }
    }
  }

//  printf("%ld\n", marked_cols.size());

  for(const auto& b : beacons) {
    if(marked_cols.find(b.second) != marked_cols.end()) marked_cols.erase(b.second);
  }

  printf("%ld\n", marked_cols.size());

  return 0;
}
