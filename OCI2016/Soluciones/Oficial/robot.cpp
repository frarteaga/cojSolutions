#include <iostream>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int i, j, n, m, b[505][505], k, d, r, x, y, t, dp[205][205][205], ret = -2, z, pr[205][205][205];
char a[205][205];
string ans;

void validate (string s) {
	string t = "";
	while (t.length() < n + m - 1) t += s;
	t = t.substr(0, n + m - 1);
	int tx = 1, ty = 1;
	for(int i = 0; i < n + m - 1; i++) {
		assert(a[tx][ty] != '#');
		if (t[i] == 'D') ++tx; else ++ty;
		if (tx > n || ty > m) break;
	}
}

int main (int argc, char * const argv[]) {

    freopen ("ROBOT.IN","r",stdin);
    freopen ("ROBOT.OUT","w",stdout);
 
	scanf("%d %d %d\n", &n, &m, &k);
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= m; j++) a[i][j] = getchar();
		scanf("\n");
	}
	for(d = 0; d <= k; d++) for(r = 0; r <= k - d; r++) if (r + d) {
		for(i = 0; i <= d; i++) for(j = 0; j <= r; j++) b[i][j] = 0;
		x = 1, y = 1;
		while (x <= n && y <= m) {
			for(i = 0; i <= d; i++) 
				for(j = 0; j <= r; j++) if (x + i <= n && y + j <= m) {
					if (a[x + i][y + j] == '#') b[i][j] = -1; else 
					if (b[i][j] != -1 && (x + y == 2 || i + j != 0)) b[i][j] += a[x + i][y + j] - '0';
				}
			x += d, y += r;
		}
		for(i = 0; i <= d; i++) for(j = 0; j <= r; j++) for(t = 0; t <= d; t++) dp[i][j][t] = -1;
		dp[0][0][0] = b[0][0];
		for(i = 0; i <= d; i++) for(j = 0; j <= r; j++) for(t = 0; t <= d; t++) if (dp[i][j][t] != -1) {
			if (b[i + 1][j] != -1 && i + 1 <= d && dp[i][j][t] + b[i + 1][j] > dp[i + 1][j][t + 1]) {
				dp[i + 1][j][t + 1] = dp[i][j][t] + b[i + 1][j];
				pr[i + 1][j][t + 1] = 0;
			}
			if (b[i][j + 1] != -1 && j + 1 <= r && dp[i][j][t] + b[i][j + 1] > dp[i][j + 1][t]) {
				dp[i][j + 1][t] = dp[i][j][t] + b[i][j + 1];
				pr[i][j + 1][t] = 1;
			}
		}
		if (dp[d][r][d] != -1 && dp[d][r][d] > ret) {
			ret = dp[d][r][d];
			ans = "";
			x = d, y = r, z = d;
			for(j = d + r; j; j--) {
				if (pr[x][y][z] == 0) {
					ans += "D";
					--x; --z;
				} else {
					ans += "R";
					--y;
				}
			}
			reverse(ans.begin(), ans.end());
		}
	}
	assert(ret != -2);
	validate(ans);
	cout << ans << endl;
    return 0;
}
