//3483 - Frustrated Engineers
//DP O(N^3)

#include <bits/stdc++.h>
using namespace std;

typedef long long int64;
const int MAX = 30;
int n, m, c[MAX];
int64 dp[MAX][MAX], w[MAX][MAX];
vector <int> g[MAX];

void dfs(int u, int p = -1) {
	if(g[u].size() == 1 && u > 1) {
		dp[u][0] = 1;
		c[u] = 1;
		return;
	}
	
	int h[MAX], l = 0;
	
	for(int v : g[u]) {
		if(v == p)
			continue;
			
		dfs(v, u);
		h[++l] = v;
		c[u] += c[v];
	}

	c[u]++;
	
	memset(w, 0, sizeof(w));
	w[0][0] = 1;
	for(int i = 1; i <= l; i++) {
		int v = h[i];
		for(int s = 0; s <= c[u]; s++) {
			for(int j = 0; j < c[v]; j++) {
				if(s - j < 0)
					continue;

				int64 val = w[i - 1][s - j] * dp[v][j];
				w[i][s] += val;
			}
			
			if(s >= c[v])
				w[i][s] += w[i - 1][s - c[v]];
		}
	}
	
	for(int i = 0; i <= c[u]; i++) {
		dp[u][i] = w[l][i];
	}
}

int main() {
	scanf("%d%d", &n, &m);
	
	for(int i = 1; i < n; i++) {
		int a, b; scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	dfs(1);
	
	int64 sol = 0;
	for(int i = 1; i <= n; i++)
		if(n - c[i] <= m)
			sol += dp[i][m - (n - c[i])];
	
	printf("%lld\n", sol);
	return 0;
}

