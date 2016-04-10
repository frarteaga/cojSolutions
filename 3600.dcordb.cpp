#include <bits/stdc++.h>
using namespace std;

int n, q, t[3005][3005];
bool dp[3005][3005];
char a[3005];

bool ok(int q, int w, int e, int r) {
	int s1 = a[q] - 'a' + 1 + a[w] - 'a' + 1;
	int s2 = a[e] - 'a' + 1 + a[r] - 'a' + 1;
	return s1 == s2;
}

int main() {
	scanf("%s%d", a + 1, &q);
	n = strlen(a + 1);
	
	for(int i = 1; i < n; i++)
		dp[i][i + 1] = 1;
		
	for(int i = 1; i <= n; i++)
		dp[i][i] = 1;
		
	for(int l = 2; l < n; l++) {
		for(int i = 1; i + l <= n; i++) {
			int j = i + l;
			dp[i][j] = dp[i + 1][j - 1] && ok(i, j, i + 1, j - 1);
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			t[i][j] = t[i - 1][j] + t[i][j - 1] - t[i - 1][j - 1] + dp[i][j];
		}
	}
	
	while(q--) {
		int a, b; scanf("%d%d", &a, &b);
		a++, b++;
		
		if(a > b)
			swap(a, b);
			
		int s = t[b][b] - t[b][a - 1] - t[a - 1][b] + t[a - 1][a - 1];
		printf("%d\n", s);
	}
	
	return 0;
}

