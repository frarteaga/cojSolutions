//3482 - An Interesting List
//DP conteo

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL maxn = 1005, mod = 1e9 + 7;

LL N, L, M;

LL Dp[maxn][maxn], temp[maxn];

int main()
{
    //freopen(".in", "r", stdin);
    int T;
    cin >> T;
    for(int i = 1; i < maxn; i++)
        Dp[1][i] = 1;

    while(T--){
        cin >> N >> L >> M;
        for(int i = 2; i <= L; i++){
            for(int j = 1; j <= N; j++)
                temp[j] = (temp[j - 1] + Dp[i - 1][j]);

            for(int j = 1; j <= N; j++){
                LL a, b;
                if(j - M - 1 >= 0)
                    a = temp[j - M - 1];
                else
                    a = 0;
                if(j + M <= N)
                    b = temp[j + M];
                else
                    b = temp[N];
                Dp[i][j] = (b - a) % mod;
            }

        }
        LL sol = 0;
        for(int i = 1; i <= N; i++) 
            sol = (sol + Dp[L][i]) % mod;
        cout << sol << '\n';

        for(int i = 2; i <= L; i++)
            for(int j = 1; j <= N; j++)
            Dp[i][j] = 0;
    }

    return 0;
}
