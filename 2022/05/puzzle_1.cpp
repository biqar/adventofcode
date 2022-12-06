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

vector<stack<char>> stacks(9);

void load_initial_data_in_stacks() {
  stacks[0].push('J');  stacks[0].push('H');  stacks[0].push('G');
  stacks[0].push('M');  stacks[0].push('Z');  stacks[0].push('N');
  stacks[0].push('T');  stacks[0].push('F');

  stacks[1].push('V');  stacks[1].push('W');  stacks[1].push('J');

  stacks[2].push('G');  stacks[2].push('V');  stacks[2].push('L');
  stacks[2].push('J');  stacks[2].push('B');  stacks[2].push('T');
  stacks[2].push('H');

  stacks[3].push('B');  stacks[3].push('P');  stacks[3].push('J');
  stacks[3].push('N');  stacks[3].push('C');  stacks[3].push('D');
  stacks[3].push('V');  stacks[3].push('L');

  stacks[4].push('F');  stacks[4].push('W');  stacks[4].push('S');
  stacks[4].push('M');  stacks[4].push('P');  stacks[4].push('R');
  stacks[4].push('G');

  stacks[5].push('G');  stacks[5].push('H');  stacks[5].push('C');
  stacks[5].push('F');  stacks[5].push('B');  stacks[5].push('N');
  stacks[5].push('V');  stacks[5].push('M');

  stacks[6].push('D');  stacks[6].push('H');  stacks[6].push('G');
  stacks[6].push('M');  stacks[6].push('R');

  stacks[7].push('H');  stacks[7].push('N');  stacks[7].push('M');
  stacks[7].push('V');  stacks[7].push('Z');  stacks[7].push('D');

  stacks[8].push('G');  stacks[8].push('N');  stacks[8].push('F');
  stacks[8].push('H');
}

void move(int from, int to, int count) {
  for(int i=0; i<count; i+=1) {
    if(!stacks[from].empty()) {
      stacks[to].push(stacks[from].top());
      stacks[from].pop();
    }
  }
}

string get_toppers() {
  string ret = "";
  for(int i=0; i<9; i+=1) {
    if(!stacks[i].empty()) ret += stacks[i].top();
    else ret += " ";
  }

  return ret;
}

int main() {
  freopen("/Users/aislam6/workspace/projects/personal/adventofcode/2022/05/input.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);

  int i, j, k;
  int test, t = 0, kase = 0;
  int score = 0, len;
  string line, tmp;
  int count, from, to;

  load_initial_data_in_stacks();

  while(getline(cin, line)) {
    if(line[0] == '#') continue;

    stringstream ss(line);
    ss >> tmp;
    ss >> tmp;
    count = stoi(tmp);

    ss >> tmp;
    ss >> tmp;
    from = stoi(tmp);

    ss >> tmp;
    ss >> tmp;
    to = stoi(tmp);

    move(from - 1, to - 1, count);
  }

  printf("%s\n", get_toppers().c_str());

  return 0;
}
