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
  freopen("/Users/aislam6/workspace/projects/personal/adventofcode/2022/07/input.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);

  int i, j, k;
  int test, t = 0, kase = 0;
  int pos = 0, len;
  string line;
  map<string, int> mp;
  stack<string> st;
  vector<string> vec;
  string dir = "", tmp;

  while(getline(cin, line)) {
    vec.clear();
    stringstream ss(line);
    while(ss >> tmp) vec.push_back(tmp);
    if(vec[0] == "$") {
      if(vec[1] == "cd") {
        if(vec[2] == "..") {
          int inner_sz = mp[dir];
          st.pop();
          dir = st.top();
          mp[dir] += inner_sz;
        }
        else {
          if(vec[2] != "/" && dir != "/") dir += ("/" + vec[2]);
          else dir += vec[2];
        }
      }
      if(vec[1] == "ls") {
        st.push(dir);
      }
    }
    else {
      if(vec[0] != "dir") {
        mp[dir] += stoi(vec[0]);
      }
    }
  }

  cout << st.top() << " " << mp[st.top()] << endl;
  int curr_sz = mp[st.top()];
  st.pop();
  while(!st.empty()) {
    cout << st.top() << " " << mp[st.top()] << endl;
    mp[st.top()] += curr_sz;
    curr_sz = mp[st.top()];
    st.pop();
  }

  int min_del = INT_MAX;
  int total_sz = mp["/"];
  int free_sz = 70000000 - total_sz;
  int req_free_sz = 30000000 - free_sz;
  cout << "total_sz: " << total_sz << ", free_sz: " << free_sz << ", req_free_sz: " << req_free_sz << endl;
  for(auto it : mp) {
    if(it.second >= req_free_sz) {
//      cout << it.first << " " << it.second << endl;
      min_del = min(min_del, it.second);
    }
  }

  printf("%d\n", min_del);

  return 0;
}
