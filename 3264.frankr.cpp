/*
Prob: Contando Cadenas
Idea: Inclusiones y exclusiones
Costo: O(K^2 * Log(N)) donde K = tamaño del alfabeto, en este caso K = 10 ya
       que alfabeto = {0, 1, ..., 9}.
       
Author: frankr@coj
*/

#include <bits/stdc++.h> 

using namespace std; 

typedef long long LL; 

//const int MAXN = 1000001;
const int MAX_D = 10;
const LL MOD = 1e9 + 7;

int N, A, B;
LL TP[MAX_D + 1][MAX_D + 1];

LL ModPow(LL B, int e){
	if (e == 0)
		return 1LL;
	if (e & 1)
		return B * ModPow(B, e - 1) % MOD;
	LL r = ModPow(B, e >> 1);
	return r * r % MOD;
}

void TPascal(){
	for (int i = 0 ; i <= MAX_D ; i++)
		TP[i][0] = TP[i][i] = 1LL;

	for (int i = 2 ; i <= MAX_D ; i++)
		for (int j = 1 ; j < i ; j++)
			TP[i][j] = (TP[i - 1][j] + TP[i - 1][j - 1]) % MOD;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); 

	//freopen("cc.in", "r", stdin);
	//freopen("cc.out", "w", stdout);

	TPascal();//precalcular Triangulo de Pascal

	cin >> N >> A >> B;

	LL sol = 0;
	for (int K = A ; K <= B ; K++){
		LL sum = 0;
		for (int i = 0 ; i < K ; i++){
			if (i & 1)
				sum -= TP[K][i] * ModPow(K - i, N);
			else
				sum += TP[K][i] * ModPow(K - i, N);
			sum %= MOD;
		}
	
		sum *= TP[MAX_D][K];
		sum %= MOD;
		sol += sum;
		sol %= MOD;
	}

	sol += MOD;
	sol %= MOD;
	cout << sol << '\n';

	return 0;
}