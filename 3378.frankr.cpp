//3378 - Sum and Sum
//Divisivilidad por 9, DP
//frankr@coj

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 1;
const int MOD = 1e9 + 7;

int N;
int A[MAXN];
int dp[MAXN][10];

int main()
{
    //freopen("d.in", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1 ; i <= N ; i++){
        cin >> A[i];
        A[i] %= 9;
    }

    dp[0][0] = 1;

    for (int i = 1 ; i <= N ; i++){
        for (int r = 0 ; r < 9 ; r++){
            dp[i][r] = dp[i - 1][r];
            dp[i][r] += dp[i - 1][(r - A[i] + 9) % 9];
            dp[i][r] %= MOD;
        }
    }

    for (int i = 1 ; i < 9 ; i++)
        cout << dp[N][i] << '\n';
    cout << dp[N][0] - 1;

    return 0;
}
