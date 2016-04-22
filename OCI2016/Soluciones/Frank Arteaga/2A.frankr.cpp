/*
Prob: CNC2016-2A Tablas con tres conjuntos
Idea: Biyección con el conjunto de las perentizaciones balanceadas
autor: frankr@coj
27/02/2016
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 37;

typedef unsigned long long ULL;

int N, M, K;
char P[2 * MAXN];
ULL dp[MAXN][MAXN];

int main()
{
    freopen("tablas.in", "r", stdin);
    freopen("tablas.out", "w", stdout);

    cin >> N;

    for (int i = 1 ; i <= 2 * N ; i++)
        P[i] = '?';

    cin >> M;
    while (M--){
        int a;
        cin >> a;
        P[a] = '(';
    }

    cin >> K;
    while (K--){
        int b;
        cin >> b;
        P[b] = ')';
    }

    if (P[1] == ')' || P[2 * N] == '(')
        goto IS;

    dp[1][1] = 1;

    for (int i = 2 ; i <= N + 1 ; i++){
        for (int j = 1 ; j <= i ; j++){
            int d = i - 1 + j - 1;
            if (P[d] == '?')
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            else
            if (P[d] == '(')
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i][j - 1];
        }
    }

    IS:
        cout << dp[N + 1][N + 1];

    return 0;
}
