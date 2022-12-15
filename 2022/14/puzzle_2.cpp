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

const int MAXX = 160;
/// note: Changing Y-dimension was tricky for part-2
const int MAXY = 1000;

const string coordinate_delimiter = " -> ";
const string point_delimiter = ",";
const pair<int, int> sand_location = make_pair(0, 500);

vector <vector<char>> cave_map(MAXX, vector<char>(MAXY, '.'));

void split(vector <string> &coordinates, const string &str, const string &regex_str) {
  regex regexz(regex_str);
  coordinates.assign(sregex_token_iterator(str.begin(), str.end(), regexz, -1), sregex_token_iterator());
}

bool draw_cave(const pair<int, int> &src, const pair<int, int> &dst) {
  assert(src.first >= 0 && src.first < MAXX && "wrong X coordinate");
  assert(src.second >= 0 && src.second < MAXY && "wrong Y coordinate");

  // same X, move in Y direction
  if (src.first == dst.first) {
    for (int j = min(src.second, dst.second); j <= max(src.second, dst.second); j += 1) {
      cave_map[src.first][j] = '#';
    }
  }
    // same Y, move in X direction
  else if (src.second == dst.second) {
    for (int i = min(src.first, dst.first); i <= max(src.first, dst.first); i += 1) {
      cave_map[i][src.second] = '#';
    }
  } else {
    cout << src.first << "," << src.second << " " << dst.first << "," << dst.second << endl;
    cout << "this should not happen! exit!" << endl;
    return false;
  }
  return true;
}

void print_cave() {
  for (int i = 0; i < MAXX; i += 1) {
    for (int j = 0; j < MAXY; j += 1) {
      cout << cave_map[i][j];
    }
    cout << endl;
  }
}

int main() {
  freopen("/Users/aislam6/workspace/projects/personal/adventofcode/2022/14/input.txt", "r", stdin);
//  freopen("/Users/aislam6/workspace/projects/personal/adventofcode/2022/14/output.txt", "w", stdout);

  string line;
  vector <string> str_coordinates;
  vector <string> tmp;
  vector <pair<int, int>> coordinates;
  int len;

  while (getline(cin, line)) {
    split(str_coordinates, line, coordinate_delimiter);

    for (auto &co: str_coordinates) {
      split(tmp, co, point_delimiter);
      assert(tmp.size() == 2 && "each coordinates should have two items.");
      coordinates.push_back(make_pair(stoi(tmp[1]), stoi(tmp[0])));
    }

    len = coordinates.size();
    for (int i = 1; i < len; i += 1) {
      if (!draw_cave(coordinates[i - 1], coordinates[i])) {
        cout << line << endl;
        for (string &co: str_coordinates) cout << co << endl;
        exit(-1);
      }
    }

    coordinates.clear();
    str_coordinates.clear();
  }

  draw_cave(make_pair(MAXX-1, 0), make_pair(MAXX-1, MAXY-1));

  int count = 0;
  pair<int, int> current_loc = make_pair(0, 500);

  while (true) {
    if(cave_map[sand_location.first][sand_location.second] == 'O') break;

    /// try to go down
    // down is a boundary, abort
    if (current_loc.first + 1 >= MAXX) {
      break;
    }
    // down is not a boundary, proceed
    // down have air, go down and continue
    if (cave_map[current_loc.first + 1][current_loc.second] == '.') {
      current_loc.first += 1;
      continue;
    }

    /// try to go left
    // left is a boundary, abort
    if (current_loc.second - 1 < 0) {
      break;
    }
    // left is not a boundary, proceed
    // left have air, proceed
    if (cave_map[current_loc.first + 1][current_loc.second - 1] == '.') {
      current_loc.first += 1;
      current_loc.second -= 1;
      continue;
    }

    /// left is filled, try to go right
    // right is a boundary, abort
    if (current_loc.second + 1 >= MAXY) {
      break;
    }
    // right is not a boundary, proceed
    // right have air, proceed
    if (cave_map[current_loc.first + 1][current_loc.second + 1] == '.') {
      current_loc.first += 1;
      current_loc.second += 1;
      continue;
    }

    // right is blocked, put sand into current position and re-initiate sanding process
    cave_map[current_loc.first][current_loc.second] = 'O';
    count += 1;
    current_loc = make_pair(0, 500);
  }

//  print_cave();
  printf("%d\n", count);

  return 0;
}
