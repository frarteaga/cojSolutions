//3563 - ¿Donde Construyo el Inv?
//Busqueda binaria
//frankr@coj

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2001;

int X, Y, P, F;
int TF[MAXN][MAXN];
int TP[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

  // freopen("d.in", "r", stdin);

    cin >> X >> Y >> P >> F;
    for (int i = 0 ; i < P ; i++){
        int px, py;
        cin >> px >> py;
        TP[px][py] = 1;
    }
    for (int i = 0 ; i < F ; i++){
        int fx, fy;
        cin >> fx >> fy;
        TF[fx][fy] = 1;
    }

    for (int i = 1 ; i <= X ; i++)
        for (int j = 1 ; j <= Y ; j++){
            TP[i][j] += TP[i - 1][j] + TP[i][j - 1] - TP[i - 1][j - 1];
            TF[i][j] += TF[i - 1][j] + TF[i][j - 1] - TF[i - 1][j - 1];
        }

    int sol = 0, px, py, L = MAXN;
    for (int i = 1 ; i <= X ; i++)
        for (int j = 1 ; j <= Y ; j++){
            //if (i == 7 && j == 3)
            //    int hh = 10;
            int ini = 0, mit, fin = min(X - i + 1, Y - j + 1);

            while (fin - ini > 5){
                mit = (ini + fin) / 2;

                if (TP[i + mit - 1][j + mit - 1] - TP[i - 1][j + mit - 1] - TP[i + mit - 1][j - 1] + TP[i - 1][j - 1] == 0)
                    ini = mit;
                else
                    fin = mit;
            }

            while (fin > ini && TP[i + fin - 1][j + fin - 1] - TP[i - 1][j + fin - 1] - TP[i + fin - 1][j - 1] + TP[i - 1][j - 1] > 0)
                fin--;

            int area = TF[i + fin - 1][j + fin - 1] - TF[i - 1][j + fin - 1] - TF[i + fin - 1][j - 1] + TF[i - 1][j - 1];
            fin++;
            if (sol <= area){
                //sol = area;
                ini = 0;
                while (fin - ini > 5){
                    mit = (ini + fin) / 2;
                    if (TF[i + mit - 1][j + mit - 1] - TF[i - 1][j + mit - 1] - TF[i + mit - 1][j - 1] + TF[i - 1][j - 1] < area)
                        ini = mit;
                    else
                        fin = mit;
                }

                while (ini < fin && TF[i + ini - 1][j + ini - 1] - TF[i - 1][j + ini - 1] - TF[i + ini - 1][j - 1] + TF[i - 1][j - 1] < area)
                    ini++;
                //ini--;

                if (sol < area){
                    sol = area;
                    L = ini;
                    px = i;
                    py = j;
                }
                else
                if (ini < L){
                    L = ini;
                    px = i;
                    py = j;
                }
            }
        }

    cout << px - 1 << " " << py - 1 << '\n';
    cout << L << '\n' << sol << '\n';

    return 0;
}

