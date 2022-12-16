/// Solution idea: https://github.com/vss2sn/advent_of_code/blob/master/2022/cpp/day_15b.cpp

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

const long long int MAX_SEARCH = 4000000;

vector<pair<pair<long long int, long long int>, long long int>> sensors;
vector<pair<long long int, long long int>> beacons;

int main() {
//  freopen("/Users/aislam6/workspace/projects/personal/adventofcode/2022/15/input_sample.txt", "r", stdin);
  freopen("/Users/aislam6/workspace/projects/personal/adventofcode/2022/15/input.txt", "r", stdin);
//  freopen("/Users/aislam6/workspace/projects/personal/adventofcode/2022/15/output.txt", "w", stdout);

  string line;
  int len;
  long long int sx, sy, bx, by, dist;

  while (getline(cin, line)) {
    len = line.size();
    /// note: this bug did not cause problem in part-1; but affected in part-2
    for(int i=0; i<len; i+=1) if(!(line[i] >= '0' && line[i] <= '9') && line[i] != '-') line[i] = ' ';

    stringstream ss(line);
    ss >> sy;
    ss >> sx;
    ss >> by;
    ss >> bx;

    dist = abs(sx - bx) + abs(sy - by);

    sensors.push_back(make_pair(make_pair(sx, sy), dist));
    beacons.push_back(make_pair(bx, by));
  }

  sort(sensors.begin(), sensors.end(), [](const auto& s1, const auto& s2) {return s1.first.second < s2.first.second;});

  long long delta_col;
  long long int tuning_freq = -1;
  bool found;

  for(long long int r=0; r<=MAX_SEARCH; r+=1) {
    for (long long int c = 0; c <= MAX_SEARCH; c += 1) {
      found = true;
      for (const auto &s: sensors) {
        if(abs(s.first.first - r) + abs(s.first.second - c) <= s.second) {
          delta_col = s.second - abs(s.first.first - r);

          c += ((s.first.second - c) + delta_col);
          found = false;
          break;
        }
      }
      if(found) {
        cout << "row: " << r << ", col: " << c << endl;
        tuning_freq = (c * 4000000) + r;
        printf("%lld\n", tuning_freq);
        return 0;
        break;
      }
    }
    if(found) break;
  }

  printf("%lld\n", tuning_freq);

  return 0;
}
