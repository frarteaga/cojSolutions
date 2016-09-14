/*
Prob: 1962 - Umbrellas for Cows
Idea: DP
frankr@coj
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 5001;

int N, M;
int X[MAXN];
int C[100001];
long long Dp[MAXN];

int main()
{
    cin >> N >> M;

    for (int i = 1 ; i <= N ; i++)
        cin >> X[i];

    sort(X + 1, X + N + 1);

    for (int i = 1 ; i <= M ; i++)
        cin >> C[i];

    for (int i = M - 1 ; i > 0 ; i--)
        C[i] = min(C[i], C[i + 1]);

    Dp[1] = C[1];

    for (int i = 2 ; i <= N ; i++){
        Dp[i] = ((long long)N) * M;
        for (int j =  i ; j > 0 ; j--){
            Dp[i] = min(Dp[i], Dp[j - 1] + C[X[i] - X[j] + 1]);
        }
    }

    cout << Dp[N];

    return 0;
}

