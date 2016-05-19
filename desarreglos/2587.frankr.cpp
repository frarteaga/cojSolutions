//2587 - Permutations
//Idea: Inclusiones y Exclusiones, ver: https://campcarib.wordpress.com/2016/03/18/conferencia-ii-de-combinatoria/
//frankr@coj

#include <iostream>

using namespace std;

typedef long long LL;

const LL MOD = 1000000007;
const int MAXN = 2001;

LL TP[MAXN][MAXN];
LL fact[MAXN];
LL dp[MAXN];

int main()
{
    int n;
    cin >> n;

    for (int i = 0 ; i <= n ; i++)
        TP[i][0] = TP[i][i] = 1;
    for (int i = 2 ; i <= n ; i++)
        for (int j = 1 ; j < i ; j++)
            TP[i][j] = (TP[i - 1][j - 1] + TP[i - 1][j]) % MOD;

    fact[0] = 1;
    for (int i = 1 ; i <= n ; i++)
        fact[i] = (fact[i - 1] * (LL)i) % MOD;

    dp[0] = 1;
    for (int i = 1 ; i <= n ; i++){
        LL r = 0;
        for (int k = 1 ; k <= i ; k++)
            r = (r + TP[i][k] * dp[i - k]) % MOD;
        dp[i] = (fact[i] - r + MOD) % MOD;
    }

    cout << dp[n];

    return 0;
}
