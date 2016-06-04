//2559 - Treasure Island
//Busqueda binaria + bfs para decidir
//frankr@coj

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 501;

const int dx[] = {-1, 0, 1,  0};
const int dy[] = { 0, 1, 0, -1};

int R, C;
int H[MAXN][MAXN];

typedef pair<int, int> pii;
bool mk[MAXN][MAXN];
int CC[MAXN][MAXN];

bool bfs(int h){
    if (H[1][1] <= h)
        return false;

    queue<pii> q;
    memset(mk, 0, sizeof mk);
    memset(CC, 0, sizeof CC);

    q.push(pii(1, 1));
    mk[1][1] = 1;

    while (!q.empty()){
        pii x = q.front();
        q.pop();

        if (x.first == R && x.second == C)
            return true;

        for (int k = 0 ; k < 4 ; k++){
            int ii = x.first + dx[k];
            int jj = x.second + dy[k];

            if (ii < 1 || jj < 1 || jj > C || ii > R)
                continue;

            if (mk[ii][jj])
                continue;

            CC[ii][jj] = CC[x.first][x.second] + 1;

            if (H[ii][jj] - CC[ii][jj] <= h)
                continue;

            mk[ii][jj] = 1;
            q.push(pii(ii, jj));
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

  // freopen("d.in", "r", stdin);
    cin >> R >> C;

    for (int i = 1 ; i <= R ; i++)
        for (int j = 1 ; j <= C ; j++)
            cin >> H[i][j];

    int ini = 1 , mit , fin = 1e6 + 1;

    while (fin - ini > 3){
        mit = (fin + ini) / 2;

        if (bfs(mit))
            ini = mit;
        else
            fin = mit;
    }

    while (ini < fin && bfs(ini))
        ini++;
    ini--;

    if (bfs(ini))
        cout << ini << '\n';
    else
        cout << -1 << endl;

    return 0;
}

