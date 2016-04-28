/*
Contando pares ST 3 usando inverso modular para calcular los
numeros binomiales
sum(c(n, k) * (2^(n - k) - 1)) para k=0..n-1
frankr@coj
*/

#include <bits/stdc++.h> 

using namespace std; 

typedef long long LL; 

const int MAXN = 1e5 + 1;
const LL MOD = 1e9 + 7;

int n;
LL pot2[MAXN];
LL fact[MAXN];
LL invf[MAXN];

LL potMod(LL B, int e){
	if (e == 0)
		return 1LL;
	if (e & 1)
		return B * potMod(B, e - 1) % MOD;
	LL r = potMod(B, e / 2);
	return r * r % MOD;
}

LL invMod(LL x){
	return potMod(x, MOD - 2);
}

LL binom(int n, int k){
	LL fn = fact[n];
	LL fk = fact[k];
	LL fnk = fact[n - k];
	return (fn * invMod(fk)) % MOD * invMod(fnk) % MOD;
}

int main(){
	cin >> n;

	pot2[0] = 1;
	fact[0] = 1;
	for (int i = 1 ; i <= n ; i++){
		pot2[i] = pot2[i - 1] * 2 % MOD;
		fact[i] = fact[i - 1] * i % MOD;
		invf[i] = invMod(fact[i]);
	}

	LL res = 0;

	for (int k = 0 ; k < n ; k++){
		res += binom(n, k) * (pot2[n - k] - 1);
		res %= MOD;
	}
	
	res += MOD;
	res %= MOD;

	cout << res << '\n';

	return 0;
}
