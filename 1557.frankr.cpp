//1557 - Assignments
//dp + bitmask memo
//frankr@coj

#include <iostream>
#include <cstring>

using namespace std;

typedef long long LL;

const int MAXN = 20;

int c, n;
int P[MAXN][MAXN];
int T[MAXN + 1][MAXN + 1];
LL fact[MAXN + 1];
bool calc[1 << MAXN];
LL dp[1 << MAXN];

LL f(int S){
    if (!calc[S]){
        LL r = 0;
        int Ce = __builtin_popcount(S);
        //if (Ce == 1)
        //    r = P[__builtin_ctz(S)][0];
        //else
            for (int i = 0 ; i < n ; i++)
                if (((1 << i) & S) && (P[i][Ce - 1]))
                    r += f(S ^ (1 << i));

        calc[S] = true;
        dp[S] = r;
    }

    return dp[S];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fact[0] = 1;
    for (int i = 1 ; i <= MAXN ; i++)
        fact[i] = fact[i - 1] * i;
    cin >> c;
    //cout << __builtin_ctz(c);
    while (c--){
        cin >> n;
        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < n ; j++){
                cin >> P[i][j];
                T[i + 1][j + 1] = P[i][j] + T[i][j + 1] + T[i + 1][j] - T[i][j];
                if (i == j && T[i + 1][i + 1] == (i + 1) * (i + 1)){
                    calc[(1 << i) - 1] = true;
                    dp[(1 << i) - 1] = fact[i + 1];
                }
            }

        for (int i = 0 ; i < (1 << n) ; i++)
            calc[i] = false;

        for (int i = 0 ; i < n ; i++){
            calc[1 << i] = true;
            dp[1 << i] = P[i][0];
        }

        cout << f((1 << n) - 1) << '\n';
    }
    return 0;
}

/*
20
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/

