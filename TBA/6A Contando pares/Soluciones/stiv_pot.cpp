/*
Contando pares ST 4
3^n - 2^n
frankr@coj
*/

#include <bits/stdc++.h> 

using namespace std; 

typedef long long LL; 

const int MAXN = 1e5 + 1;
const LL MOD = 1e9 + 7;

int n;

LL potMod(LL B, int e){
	if (e == 0)
		return 1LL;
	if (e & 1)
		return B * potMod(B, e - 1) % MOD;
	LL r = potMod(B, e / 2);
	return r * r % MOD;
}

int main(){
	cin >> n;

	LL res = potMod(3, n) - potMod(2, n);

	res += MOD;
	res %= MOD;

	cout << res << '\n';

	return 0;
}
