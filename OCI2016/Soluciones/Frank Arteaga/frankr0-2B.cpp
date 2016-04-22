/*
CNC2016-2B Rutas
frankr@coj
Disjoint Sets + LCA
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> edge;
typedef pair<pii, int> lejanos;

const int MAXN = 500001;
const int MAX_LOG = 20;

#define node first
#define cost second
#define p2(e) (1 << (e))
#define nod1 first.first
#define nod2 first.second

int N;
vector<pii> A[MAXN]; //lista de adyacencia
edge E[MAXN];
int DP[MAXN][MAX_LOG]; //ancestros de cada nodo a distancias potencias de dos
int L[MAXN]; //nivel de cada nodo
int Cost[MAXN]; //cost hasta la raiz, raiz = 1
int P[MAXN]; //for Disjoint=Sets
lejanos PML[MAXN]; //par de nodos mas lejanos en el subarbol
pii sol[MAXN];
int Rank[MAXN];

void BFS(){
    int root = 1;
    L[root] = 1;
    Cost[root] = 0;
    queue<int> Q;
    Q.push(root);

    while (!Q.empty()){
        int nod = Q.front();
        Q.pop();

        for (int i = 0 ; i < A[nod].size() ; i++){
            int vecino = A[nod][i].node;
            if (L[vecino] == 0){
                L[vecino] = L[nod] + 1;
                Cost[vecino] = Cost[nod] + A[nod][i].cost;
                Q.push(vecino);
                DP[vecino][0] = nod; //parte de del LCA_precal, es el caso base
            }
        }
    }
}

void LCA_precalc(){
    for (int e = 1 ; p2(e) <= N ; e++)
        for (int v = 1 ; v <= N ; v++)
            DP[v][e] = DP[DP[v][e - 1]][e - 1];
}

int LCA_query(int x, int y){
    if(L[x] < L[y])
        swap(x, y);

    int lg = log2(L[x]);
    for(int i = lg; i >= 0; i--)
        if(L[x] - p2(i) >= L[y])
            x = DP[x][i];

    if(x == y)
        return x;

    for(int i = lg; i >= 0; i--)
        if(DP[x][i] != 0 && DP[x][i] != DP[y][i]){
            x = DP[x][i];
            y = DP[y][i];
        }

    return DP[x][0];
}

//retorna el costo del camino unico entre el nodo v y el nodo u
int Costo(int v, int u){
    int lca = LCA_query(v, u);
    int r = Cost[v] + Cost[u] - 2 * Cost[lca];
    return r;
}

int Find(int x){
    if (P[x] == x)
        return x;
    return P[x] = Find(P[x]); //compresion por caminos
}

int Union(int x, int y){
    int px = Find(x);
    int py = Find(y);
    if (Rank[px] < Rank[py])
        P[px] = py;
    else
    if (Rank[px] > Rank[py])
        P[py] = px;
    else{
        P[py] = px;
        Rank[px]++;
    }
}

vector<lejanos> posibles(6);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("rutas.in", "r", stdin);
    freopen("rutas.out", "w", stdout);

    cin >> N;
    for (int i = 1 ; i < N ; i++){
        int a, b, c;
        cin >> a >> b >> c;
        A[a].push_back(pii(b, c));
        A[b].push_back(pii(a, c));
        E[i] = edge(pii(a, b), c);
    }

    BFS();

    LCA_precalc();

    for (int i = 1 ; i <= N ; i++){
        P[i] = i;
        Rank[i] = 1;
        PML[i] = lejanos(pii(i, i), 0);
    }

    for (int i = N - 1 ; i >= 1 ; i--){
        int x = E[i].nod1;
        int y = E[i].nod2;
        int r1 = Find(x);
        int r2 = Find(y);
        int sol1 = PML[r1].cost;
        int sol2 = PML[r2].cost;
        if (sol1 > sol2)
            swap(sol1, sol2);
        sol[i] = pii(sol1, sol2);
        int l11 = PML[r1].nod1;
        int l12 = PML[r1].nod2;
        int l21 = PML[r2].nod1;
        int l22 = PML[r2].nod2;
        //vector<lejanos> posibles(6); //declararlo global para q evitar demora de la inicializacion
        posibles[0] = PML[r1];
        posibles[1] = PML[r2];
        int cl11x = Costo(l11, x);
        int cl12x = Costo(l12, x);
        int cl21y = Costo(l21, y);
        int cl22y = Costo(l22, y);
        int cc = E[i].cost;
        posibles[2] = lejanos(pii(l11, l21), cl11x + cc + cl21y);
        posibles[3] = lejanos(pii(l11, l22), cl11x + cc + cl22y);
        posibles[4] = lejanos(pii(l12, l21), cl12x + cc + cl21y);
        posibles[5] = lejanos(pii(l12, l22), cl12x + cc + cl22y);
        Union(x, y);
        int newr = Find(y);
        PML[newr] = posibles[0];
        for (int i = 1 ; i < 6 ; i++)
            if (PML[newr].cost < posibles[i].cost)
                PML[newr] = posibles[i];
    }

    for (int i = 1 ; i < N ; i++)
        cout << sol[i].first << ' ' << sol[i].second << '\n';

    return 0;
}
