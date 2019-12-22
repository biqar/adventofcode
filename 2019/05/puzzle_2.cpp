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

const int POSITION_MODE = 0;
const int IMMEDIATE_MODE = 1;

const int OP_HALT = 99;
const int OP_ADD = 1;
const int OP_MUL = 2;
const int OP_INPUT = 3;
const int OP_OUTPUT = 4;
const int OP_JUMP_TRUE = 5;
const int OP_JUMP_FALSE = 6;
const int OP_LESS_THAN = 7;
const int OP_EQUAL = 8;

int arr[MAX];

void solver(int i, int input_instruction) {
    int j = 0;
    while(j < i) {
        int op = arr[j] % 100;
        int a_mode = (arr[j] / 100) % 10;
        int b_mode = (arr[j] / 1000) % 10;
        int c_mode = (arr[j] / 10000) % 10;
        int a, b, c;

        if(op == OP_HALT) {
            break;
        }
        else if (op == OP_ADD) {
            a = a_mode == POSITION_MODE ? arr[arr[j+1]] : arr[j+1];
            b = b_mode == POSITION_MODE ? arr[arr[j+2]] : arr[j+2];

            if(c_mode == IMMEDIATE_MODE) {
                printf("[%d] wrong mode detected in ADD operation!\n", arr[j]);
                exit(0);
            }

            arr[arr[j+3]] = a + b;
            j += 4;
        }
        else if (op == OP_MUL) {
            a = a_mode == POSITION_MODE ? arr[arr[j+1]] : arr[j+1];
            b = b_mode == POSITION_MODE ? arr[arr[j+2]] : arr[j+2];

            if(c_mode == IMMEDIATE_MODE) {
                printf("[%d] wrong mode detected in MUL operation!\n", arr[j]);
                exit(0);
            }

            arr[arr[j+3]] = a * b;
            j += 4;
        }
        else if (op == OP_INPUT) {
            if(a_mode == IMMEDIATE_MODE) {
                printf("[%d] wrong mode detected in INPUT operation!\n", arr[j]);
                exit(0);
            }

            arr[arr[j+1]] = input_instruction;
            j += 2;
        }
        else if (op == OP_OUTPUT) {
            printf("output: %d\n", a_mode == POSITION_MODE ? arr[arr[j+1]] : arr[j+1]);
            j += 2;
        }
        else if (op == OP_JUMP_TRUE) {
            a = a_mode == POSITION_MODE ? arr[arr[j+1]] : arr[j+1];
            b = b_mode == POSITION_MODE ? arr[arr[j+2]] : arr[j+2];

            if(a != 0) {
                j = b;
            }
            else {
                j += 3;
            }
        }
        else if (op == OP_JUMP_FALSE) {
            a = a_mode == POSITION_MODE ? arr[arr[j+1]] : arr[j+1];
            b = b_mode == POSITION_MODE ? arr[arr[j+2]] : arr[j+2];

            if(a == 0) {
                j = b;
            }
            else {
                j += 3;
            }
        }
        else if (op == OP_LESS_THAN) {
            a = a_mode == POSITION_MODE ? arr[arr[j+1]] : arr[j+1];
            b = b_mode == POSITION_MODE ? arr[arr[j+2]] : arr[j+2];

            if(c_mode == IMMEDIATE_MODE) {
                printf("[%d] wrong mode detected in LESS_THAN operation!\n", arr[j]);
                exit(0);
            }

            if(a < b) arr[arr[j+3]] = 1;
            else arr[arr[j+3]] = 0;
            j += 4;
        }
        else if (op == OP_EQUAL) {
            a = a_mode == POSITION_MODE ? arr[arr[j+1]] : arr[j+1];
            b = b_mode == POSITION_MODE ? arr[arr[j+2]] : arr[j+2];

            if(c_mode == IMMEDIATE_MODE) {
                printf("[%d] wrong mode detected in EQUAL operation!\n", arr[j]);
                exit(0);
            }

            if(a == b) arr[arr[j+3]] = 1;
            else arr[arr[j+3]] = 0;
            j += 4;
        }
        else {
            printf("unknown operation!\n");
            exit(0);
        }
    }
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

    solver(ii, 5);

    return 0;
}
