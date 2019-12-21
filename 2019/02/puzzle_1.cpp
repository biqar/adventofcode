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

int arr[MAX];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int i, j, k, tmp;
    int test, t = 0, kase = 0;
    string line;

    getline(cin, line);
    replace(line.begin(), line.end(), ',', ' ');
    stringstream ss(line);
    i = 0;

    while(ss >> tmp) {
        arr[i] = tmp;
        i += 1;
    }
    j = 0;
    while(j < i) {
        if(arr[j] == 99) {
            break;
        }
        else if (arr[j] == 1) {
            arr[arr[j+3]] = arr[arr[j+1]] + arr[arr[j+2]];
        }
        else if (arr[j] == 2) {
            arr[arr[j+3]] = arr[arr[j+1]] * arr[arr[j+2]];
        }
        j += 4;
    }
    printf("%d\n", arr[0]);
    return 0;
}
