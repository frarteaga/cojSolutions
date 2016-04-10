//3449 - Showdown
/*alurquiza*/
#include <bits/stdc++.h>

using namespace std;

const int CONST = 12,SIZE = 501,MAXM = 1 << CONST,MOD = 1e9 + 7;
char M[CONST];
long long E[SIZE],DP[SIZE][MAXM];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    freopen(".in","r",stdin);
//    freopen(".out","w",stdout);

    int N;
    cin >> N;

    for(int i = 0;i < CONST;i++)
        cin >> M[i];

    for(int i = 1;i <= N;i++)
        for(int j = 0;j < CONST;j++){
            char ent;
            cin >> ent;
            if(ent >= M[j])
                E[i] |= 1 << j;
        }

    DP[0][0] = 1;

    for(int i = 1;i <= N;i++){
        for(int mask = 0;mask < MAXM;mask++){
            DP[i][mask] = (DP[i][mask] + DP[i - 1][mask]) % MOD;

            DP[i][mask | E[i]] = (DP[i][mask | E[i]] + DP[i - 1][mask]) % MOD;
        }
    }

    long long sol = 0;
    for(int mask = 0;mask < MAXM;mask++)
        if(__builtin_popcount(mask) > 6){
//            for(int i = 1;i <= N;i++){
                sol = (sol + DP[N][mask]) % MOD;
//            }
        }

    cout << sol << '\n';

    return 0;
}

