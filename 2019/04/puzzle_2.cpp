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

int valid_password(int num) {
    bool adj_check = false;
    int last_dig = num % 10;
    num /= 10;
    int adj_count = 1;
    while(num) {
        int curr_dig = num % 10;
        num /= 10;

        if(curr_dig == last_dig) {
            adj_count += 1;
        } else {
            if(curr_dig > last_dig) return 0;
            if(adj_count == 2) adj_check = true;
            adj_count = 1;
        }
        last_dig = curr_dig;
    }
    if(adj_count == 2) adj_check = true;

    return adj_check ? 1 : 0;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int i, j, k;
    int test, t = 0, kase = 0;
    int lo = 147981, hi = 691423, pass_count = 0;

    for(i=lo; i<hi; i+=1) {
        pass_count += valid_password(i);
    }
    printf("%d\n", pass_count);

    return 0;
}
