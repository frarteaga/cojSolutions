//Prob: 1405 - Cutting Circles
//Idea: Formula de Euler para grafos planares
//frankr@coj

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>

#include <iostream>

using namespace std;

const double EPSILON = 1e-8;
const double PI = 3.141592653589793; 
const int oo = 2000000000;
const int di[4] = {-1, 0, 1,  0};
const int dj[4] = { 0, 1, 0, -1};
const int d8i[8] = {-1, -1, -1, 0, 1, 1,  1,  0};
const int d8j[8] = {-1,  0,  1, 1, 1, 0, -1, -1};

typedef long double real;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef set<int> seti;
typedef set<string> sets;
typedef map<int, int> mapii;

#define MAXN 1000
#define REP(i, n) for (int i = 0 ; i < n ; i++)
#define REPD(i, n) for (int i = (n) - 1 ; i > -1 ; i--)
#define FOR(i, a, b) for (int i = (a) ; i <= (b) ; i++)
#define CICLE(i, a, b, k) for (int i = (a) ; i <= (b) ; i += k)

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) > 0 ? (a) : -(a))
#define MKP(a, b) make_pair((a), (b))

#define ONES(n) __builtin_popcount(n)

#define RI(n) scanf("%d", &n)

int main()
{
	ll A, V, S, n;
	int t;
	RI(t);
	REP(tt, t){
		scanf("%lld", &n);
		A = 0;
		FOR(i, 1, n - 3)
			A += (n - 2 - i) * i;
		A += n - 3;
		A *= n;
		A >>= 1;
		A += (n << 1);
		V = n * (n - 1) * (n - 2) * (n - 3) / 24 + n;
		S = A + 1 - V;
		printf("%lld\n", S);
	}
	return 0;
}

