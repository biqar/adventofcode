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
const int expected_output = 19690720;

int arr[MAX], current[MAX];

int solver(int i, int noun, int verb) {
    memcpy(current, arr, sizeof(arr));
    current[1] = noun;
    current[2] = verb;

    int j = 0;
    while(j < i) {
        if(current[j] == 99) {
            break;
        }
        else if (current[j] == 1) {
            current[current[j+3]] = current[current[j+1]] + current[current[j+2]];
        }
        else if (current[j] == 2) {
            current[current[j+3]] = current[current[j+1]] * current[current[j+2]];
        }
        j += 4;
    }
    return current[0];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int ii, i, j, k, tmp;
    int test, t = 0, kase = 0;
    string line;

    getline(cin, line);
    replace(line.begin(), line.end(), ',', ' ');
    stringstream ss(line);
    ii = 0;

    while(ss >> tmp) {
        arr[ii] = tmp;
        ii += 1;
    }

    for(i=0; i<=99; i+=1) {
        for(j=0; j<=99; j+=1) {
            if(solver(ii, i, j) == expected_output) {
                printf("%d%d\n", i, j);
                exit(0);
            }
        }
    }

    return 0;
}
