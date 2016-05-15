//3600 - Complementary Words II
//DP

/*alurquiza*/
#include <bits/stdc++.h>

using namespace std;

const int SIZE = 3e3 + 10;
long long DP[SIZE][SIZE];
bool Mk[SIZE][SIZE];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    freopen(".in","r",stdin);
//    freopen(".in","r",stdin);

    string S;
    cin >> S;

    for(int i = 0;i < S.size();i++){
        if(i < S.size())
            Mk[i][1] = 1;
        if(i + 1 < S.size())
            Mk[i][2] = 1;
    }

    for(int l = 3;l <= S.size();l++){
        for(int i = 0;i + l - 1 < S.size();i++){
            if(Mk[i + 1][l - 2] && S[i] + S[i + l - 1] == S[i + 1] + S[i + l - 2]){
                Mk[i][l] = 1;
            }
        }
    }

    for(int l = 1;l <= S.size();l++){
        for(int i = 0;i + l - 1 < S.size();i++){
            DP[i][l] = DP[i + 1][l - 1] + DP[i][l - 1] - DP[i + 1][l - 2] + (Mk[i][l]);
        }
    }

    int Q;
    cin >> Q;

    while(Q--){
        int a,b;
        cin >> a >> b;

        if(a > b)
            swap(a,b);

        cout << DP[a][b - a + 1] << '\n';
    }

    return 0;
}
