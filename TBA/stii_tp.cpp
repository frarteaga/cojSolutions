/*
Contando pares ST 2
sum(c(n, k) * (2^(n - k) - 1)) para k=0..n-1
frankr@coj
*/

#include <bits/stdc++.h> 

using namespace std; 

typedef long long LL; 

const int MAXN = 2001;
const LL MOD = 1e9 + 7;

int n;
LL pot2[MAXN];
LL TP[MAXN][MAXN];

int main(){
	cin >> n;

	pot2[0] = 1;
	for (int i = 1 ; i <= n ; i++){
		pot2[i] = pot2[i - 1] * 2 % MOD;
		TP[i][0] = TP[i][i] = 1;
	}

	for (int i = 2 ; i <= n ; i++)
		for (int j = 1 ; j < i ; j++)
			TP[i][j] = (TP[i - 1][j - 1] + TP[i - 1][j]) % MOD;

	LL res = 0;

	for (int k = 0 ; k < n ; k++)
		res += TP[n][k] * (pot2[n - k] - 1) % MOD;
	
	res %= MOD;
	res += MOD;
	res %= MOD;

	cout << res << '\n';

	return 0;
}
