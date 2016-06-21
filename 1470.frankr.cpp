//1470 - Digger Octaves
//backtracking + bitmask
//frankr@coj

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

const int MAXN = 14;
const int dx[] = {-1, 0, 1,  0};
const int dy[] = { 0, 1, 0, -1};

int N;
char A[MAXN][MAXN];
bool mk[MAXN][MAXN];
set<ULL> sol;
ULL R[MAXN];

void dfs(int a, int b, int c){
    if (mk[a][b] || A[a][b] != 'X')
        return;
    R[c] = (a - 1) * N + b - 1;
    if (c == 7){
        ULL H = 0;
        for (int i = 0 ; i < 8 ; i++)
            H |= (1ULL << R[i]);
        sol.insert(H);
        return;
    }
    mk[a][b] = true;
    for (int k = 0 ; k < 4 ; k++){
        int aa = a + dx[k];
        int bb = b + dy[k];
        dfs(aa, bb, c + 1);
    }
    mk[a][b] = false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("d.in", "r", stdin);
    int t;
    cin >> t;
    while (t--){
        cin >> N;
        memset(A, '.', sizeof A);
        memset(mk, false, sizeof mk);
        for (int i = 1 ; i <= N ; i++){
            cin >> &A[i][1];
            A[i][N + 1] = '.';
        }

//        for (int i = 1 ; i <= N ; i++){
//            for (int j = 1 ; j <= N ; j++)
//                cout << A[i][j];
//            cout << endl;
//        }
        sol.clear();
        for (int i = 1 ; i <= N ; i++)
            for (int j = 1 ; j <= N ; j++)
                dfs(i, j, 0);
        cout << sol.size() << '\n';
    }
    return 0;
}
