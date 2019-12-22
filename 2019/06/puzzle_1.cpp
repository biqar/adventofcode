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
const int MAX = 1000005;

string line;
map <string, int> M;
vector<int> G[MAX];
int total_node, vis[MAX];

void get_input() {
    total_node = 0;
    while(true) {
        getline(cin, line);
        if(line.size() == 0) break;
        replace(line.begin(), line.end(), ')', ' ');

        string ustr, vstr;
        int u, v;
        stringstream ss(line);
        ss >> ustr;
        ss >> vstr;

        if(M.find(ustr) == M.end()) {
            M[ustr] = total_node;
            u = total_node;
            total_node += 1;
        } else {
            u = M[ustr];
        }

        if(M.find(vstr) == M.end()) {
            M[vstr] = total_node;
            v = total_node;
            total_node += 1;
        } else {
            v = M[vstr];
        }

        G[v].push_back(u);
    }
}

int dfs(int u) {
    //base case
    if(G[u].size() == 0) return 0;
    if(vis[u] == 1) return 0;

    int ret = 0;
    for(int i=0; i<G[u].size(); i+=1) {
        ret += (1 + dfs(G[u][i]));
    }
    return ret;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int i, j, k;
    int test, t = 0, kase = 0;
    int orbit_count = 0;

    get_input();
    for(i=0; i<total_node; i+=1) {
        memset(vis, 0, sizeof(vis));
        orbit_count += dfs(i);
    }

    printf("The total number of direct and indirect orbits: %d\n", orbit_count);

    return 0;
}
