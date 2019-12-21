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
const int MAX = 1005;

map<pii, bool> m;

int _abs(int v) {
    return v < 0 ? -v : v;
}

int _min(int a, int b) {
    return a < b ? a : b;
}

int get_manhattan_distance(int x, int y) {
    return _abs(x - 0) + _abs(y - 0);
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int i, j, k;
    int test, t = 0, kase = 0;
    string wire1, wire2, tmp;
    int x, y;
    int min_distance = inf;

    getline(cin, wire1);
    getline(cin, wire2);

    replace(wire1.begin(), wire1.end(), ',', ' ');
    replace(wire2.begin(), wire2.end(), ',', ' ');

    stringstream ss1(wire1);
    x = 0, y = 0;
    while(ss1 >> tmp) {
        int steps = stoi(tmp.substr(1));
        if(tmp[0] == 'L') {
            for(i=1; i<=steps; i+=1) {
                y -= 1;
                m[pair<int, int>(x, y)] = true;
            }
        } else if(tmp[0] == 'R') {
            for(i=1; i<=steps; i+=1) {
                y += 1;
                m[pair<int, int>(x, y)] = true;
            }
        } else if(tmp[0] == 'U') {
            for(i=1; i<=steps; i+=1) {
                x += 1;
                m[pair<int, int>(x, y)] = true;
            }
        } else if(tmp[0] == 'D') {
            for(i=1; i<=steps; i+=1) {
                x -= 1;
                m[pair<int, int>(x, y)] = true;
            }
        }
    }

    stringstream ss2(wire2);
    x = 0, y = 0;
    while(ss2 >> tmp) {
        int steps = stoi(tmp.substr(1));
        if(tmp[0] == 'L') {
            for(i=1; i<=steps; i+=1) {
                y -= 1;
                if(m.find(pair<int, int>(x, y)) != m.end()) {
                    min_distance = _min(min_distance, get_manhattan_distance(x, y));
                }
            }
        } else if(tmp[0] == 'R') {
            for(i=1; i<=steps; i+=1) {
                y += 1;
                if(m.find(pair<int, int>(x, y)) != m.end()) {
                    min_distance = _min(min_distance, get_manhattan_distance(x, y));
                }
            }
        } else if(tmp[0] == 'U') {
            for(i=1; i<=steps; i+=1) {
                x += 1;
                if(m.find(pair<int, int>(x, y)) != m.end()) {
                    min_distance = _min(min_distance, get_manhattan_distance(x, y));
                }
            }
        } else if(tmp[0] == 'D') {
            for(i=1; i<=steps; i+=1) {
                x -= 1;
                if(m.find(pair<int, int>(x, y)) != m.end()) {
                    min_distance = _min(min_distance, get_manhattan_distance(x, y));
                }
            }
        }
    }

    printf("%d\n", min_distance);

    return 0;
}
