#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct edge {
    int to, ln;
};

int n;

vector<int> a;
vector<int> b;
vector<int> d;

vector< pair<int, int> > ans;

vector<edge> g[1 << 20];
int dep[1 << 20];
int par[1 << 20][21];

int rdis[1 << 20];

queue<int> q;

void bfs_step(int v) {
    for (int j = 1; j < 21; ++j) {
        par[v][j] = par[ par[v][j - 1] ][j - 1];
    }
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i].to;
        int l = g[v][i].ln;
        if (par[u][0] == -1) {
            par[u][0] = v;
            dep[u] = dep[v] + 1;
            rdis[u] = rdis[v] + l;
            q.push(u);
        }
    }
}

void bfs(int v) {
    q.push(v);
    par[v][0] = 0;
    while (q.size()) {
        bfs_step(q.front());
        q.pop();
    }
}

inline int lca(int v, int t) {
    if (dep[v] < dep[t]) {
        swap(v, t);
    }
    int k = 20;
    while (dep[v] > dep[t]) {
        while (dep[ par[v][k] ] < dep[t]) {
            --k;
        }
        v = par[v][k];
    }
    k = 20;
    if (v == t) {
        return v;
    }
    while (par[v][0] != par[t][0]) {
        while (par[v][k] == par[t][k]) {
            --k;
        }
        v = par[v][k];
        t = par[t][k];
    }
    return par[v][0];
}

inline int sdist(int v, int t) {
    int dis = rdis[v] + rdis[t] - 2 * rdis[lca(v, t)];
   return dis;
}

int lc = 0;

int upar[1 << 20];
int de[1 << 20][2];
int di[1 << 20];

vector<int> cc;
int com(int v) {
    cc.clear();
    while (upar[v] != -1) {
        cc.push_back(v);
        v = upar[v];
    }
    for (int i = 0; i < (int) cc.size(); ++i) {
        upar[ cc[i] ] = v;
    }
    return v;
}

int main() {

    freopen( "rutas.in", "r", stdin );
    freopen( "rutas.out", "w", stdout );

    memset(upar, -1, sizeof(upar));
    scanf("%d", &n);
    a.resize(n - 1);
    b.resize(n - 1);
    d.resize(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d %d", &a[i], &b[i], &d[i]);
        edge e;
        e.to = b[i];
        e.ln = d[i];
        g[a[i]].push_back(e);

        e.to = a[i];
        g[b[i]].push_back(e);
    }

    memset(par, -1, sizeof(par));
    for (int i = 0; i < 21; ++i) {
        par[0][i] = 0;
    }
    dep[0] = -1;
    dep[1] = rdis[1] = 0;
    bfs(1);

    for (int i = 0; i <= n; ++i) {
        de[i][0] = de[i][1] = i;
        di[i] = 0;
    }

    ans.resize(n - 1);
    for (int i = n - 2; i >= 0; --i) {
        // first ask, then add diam
        int h[2];
        h[0] = com(a[i]);
        h[1] = com(b[i]);
        ans[i].first = di[h[0]];
        ans[i].second = di[h[1]];
        int b0;
        if (sdist(a[i], de[h[0]][0]) >= sdist(a[i], de[h[0]][1])) {
            b0 = de[h[0]][0];
        } else {
            b0 = de[h[0]][1];
        }

        int b1;
        int k[2];
        for (int j = 0; j < 2; ++j) {
            k[j] = sdist(b0, de[h[1]][j]);
        }
        int mk;
        if (k[0] >= k[1]) {
            b1 = de[h[1]][0];
            mk = k[0];
        } else {
            b1 = de[h[1]][1];
            mk = k[1];
        }
        if (ans[i].first >= mk) {
            b0 = de[h[0]][0];
            b1 = de[h[0]][1];
            mk = ans[i].first;
        }
        if (ans[i].second >= mk) {
            b0 = de[h[1]][0];
            b1 = de[h[1]][1];
            mk = ans[i].second;
        }
        de[h[1]][0] = b0;
        de[h[1]][1] = b1;
        di[h[1]] = mk;
        upar[h[0]] = h[1];
    }

    int h = com(1);

    for (int i = 0; i < n - 1; ++i) {
        printf("%d %d\n", min(ans[i].first, ans[i].second),
                          max(ans[i].first, ans[i].second));
    }
    return 0;
}
