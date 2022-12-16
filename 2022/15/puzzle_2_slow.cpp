/// note: very slow; only works in sample input; created to conceptually understand the problem.

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

const long long int MIN_ROW = 0;
//const long long int MAX_ROW = 4000000;
const long long int MAX_ROW = 20;

vector<vector<char>> grid(MAX_ROW+1, vector<char>(MAX_ROW+1, '.'));

vector<pair<pair<long long int, long long int>, long long int>> sensors;
vector<pair<long long int, long long int>> beacons;
vector<bool> marked_cols(MAX_ROW + 1);

void print_grid() {
  for (int i = 0; i <= MAX_ROW; i += 1) {
    for (int j = 0; j <= MAX_ROW; j += 1) {
      cout << grid[i][j];
    }
    cout << endl;
  }
}

int main() {
  freopen("/Users/aislam6/workspace/projects/personal/adventofcode/2022/15/input_sample.txt", "r", stdin);
//  freopen("/Users/aislam6/workspace/projects/personal/adventofcode/2022/15/input.txt", "r", stdin);
//  freopen("/Users/aislam6/workspace/projects/personal/adventofcode/2022/14/output.txt", "w", stdout);

  string line;
  int len;
  long long int sx, sy, bx, by, dist;

  while (getline(cin, line)) {
    len = line.size();
    for(int i=0; i<len; i+=1) if(!(line[i] >= '0' && line[i] <= '9') && line[i] != '-') line[i] = ' ';

    stringstream ss(line);
    ss >> sy;
    ss >> sx;
    ss >> by;
    ss >> bx;

    dist = abs(sx - bx) + abs(sy - by);

    sensors.push_back(make_pair(make_pair(sx, sy), dist));
    beacons.push_back(make_pair(bx, by));

    if(sx <= MAX_ROW && sy <= MAX_ROW) grid[sx][sy] = 'S';
    if(bx <= MAX_ROW && by <= MAX_ROW) grid[bx][by] = 'B';
  }

  int delta_col;
  long long int tuning_freq;
  for(int targeted_row=MIN_ROW; targeted_row<=MAX_ROW; targeted_row+=1) {
    if(targeted_row && targeted_row % 400000 == 0) {
      cout << "processed " << targeted_row << " rows ..." << endl;
    }

    int total_marked = 0;
    fill(marked_cols.begin(), marked_cols.end(), false);

    for(const auto& s : sensors) {
      if(s.first.first == targeted_row ||
         (s.first.first < targeted_row && s.first.first + s.second >= targeted_row) ||
         (s.first.first > targeted_row && s.first.first - s.second <= targeted_row)) {
        delta_col = s.second - abs(s.first.first - targeted_row);

        for(long long int j=s.first.second - delta_col; j<=s.first.second + delta_col; j+=1) {
          if(j >= MIN_ROW && j <= MAX_ROW && !marked_cols[j]) {
            marked_cols[j] = true;
            total_marked += 1;
          }

          if(j >= MIN_ROW && j <= MAX_ROW && grid[targeted_row][j] == '.') grid[targeted_row][j] = '#';
        }
      }
    }

    if(total_marked < MAX_ROW+1) {
      cout << "we found a possible distress beacon at row: " << targeted_row << ", total marked cols: " << total_marked << endl;
      for(long long int i=0; i<=MAX_ROW; i+=1) {
        if(!marked_cols[i]) {
          cout << "row: " << targeted_row << ", col: " << i << endl;
          tuning_freq = (i * 4000000) + targeted_row;
//          break;
        }
      }
//      break;
    }
//    if(targeted_row == 20) break;
  }

  print_grid();

  printf("%lld\n", tuning_freq);

  return 0;
}
