/*
Prob: 3008 - Flip Five
Idea: BFS, bitmask for state representation
frankr@coj
*/


#include <bits/stdc++.h>

using namespace std;

int K[3][3];
bool mk[1 << 9];
int C[1 << 9];

const int dx[] = {-1, 0, 0, 1, 0};
const int dy[] = {0, -1, 1, 0, 0};

int bfs(int ef){
    fill(mk, mk + (1 << 9), 0);
    fill(C, C + (1 << 9), 0);

    queue<int> Q;

    Q.push(0);
    mk[0] = true;

    while (!Q.empty()){
        int ne = Q.front();
        Q.pop();

        if (ne == ef)
            break;

        for (int i = 0 ; i < 3 ; i++)
            for (int j = 0 ; j < 3 ; j++){
                int hijo = ne;
                for (int k = 0 ; k < 5 ; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (x > -1 && x < 3 && y > -1 && y < 3)
                        hijo ^= (1 << K[x][y]);
                }
                if (!mk[hijo]){
                    Q.push(hijo);
                    mk[hijo] = true;
                    C[hijo] = C[ne] + 1;
                }
            }
    }

    return C[ef];
}

int main()
{
    int p = 0;
    for (int i = 0 ; i < 3 ; i++)
        for (int j = 0 ; j < 3 ; j++)
            K[i][j] = p++;

    int t;
    cin >> t;

    while (t--){
        int e = 0;
        for (int i = 0 ; i < 3 ; i++)
            for (int j = 0 ; j < 3 ; j++){
                char c;
                cin >> c;
                if (c == '*')
                    e |= (1 << K[i][j]);
            }

        cout << bfs(e) << '\n';
        //cout << "DBG " << e;
    }

    return 0;
}

