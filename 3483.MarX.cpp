//3483 - Frustrated Engineers
//DP!!!

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 26;

vi adj[maxn];
int tot[maxn];
int dp[maxn][maxn][2];

void dfs(int s, int p){
	tot[s] = 1;
	for (auto u : adj[s]) if (u != p){
		dfs(u, s);
		tot[s] += tot[u];
	}
}

int calc(int s, int k, int r, int p){
	int &ans = dp[s][k][r];

	if (ans >= 0){
		return ans;
	}

	if (k == 0 || k == tot[s]){

//		cout << s << " " << k << " " << r << " : " << 1 << endl;
		return ans = 1;
	}

	ans = 0;

	if (r){
		for (auto u : adj[s]) if (u != p)
		{
			if (k >= tot[s] - tot[u])
				ans += calc(u, k - (tot[s] - tot[u]), 1, s);
		}
	}

	vector<vector<int>> ks(2, vector<int>(k + 1));
	ks[0][0] = 1;

	for (auto u : adj[s]) if (u != p){
		ks[1] = vector<int>(k + 1);
		for (int sz = 0; sz <= k; ++sz){
			for (int j = 0; j <= sz; ++j)
				ks[1][sz] += ks[0][sz - j] * calc(u, j, 0, s);
		}
		ks[0].swap(ks[1]);
	}

	ans += ks[0][k];

//	cout << s << " " << k << " " << r << " : " << ans << endl;

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	if (k == n){
		cout << 0 << endl;
		return 0;
	}

	for (int i = 1; i < n; ++i){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, -1);

	memset(dp, -1, sizeof dp);
	cout << calc(1, k, 1, -1) << endl;

//	int t; cin >> t;
//	while (t--){
//		string s; cin >> s;
//		int v = 0;
//		for (int i = 1; i < (int)s.length(); i += 2){
//			v += 2 * (s[i] - '0');
//		}
//		v = (10 - v % 10) % 10;
//		cout << v << endl;
//	}

	return 0;
}

