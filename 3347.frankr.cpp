//3347 - The Task
//Sumas telescopicas. Familia de sumas:
//sum_{i=1}^{n} i^k para k = 0, 1, 2, ...
//frankr@coj

#include <bits/stdc++.h> 

const int MAXK = 1002;

typedef long long LL; 

LL N, K, M;
LL TP[MAXK][MAXK];
LL S[MAXK];
LL POT[MAXK];



void precalc(){
	for (int i = 0 ; i <= K + 1 ; i++)
		TP[i][0] = TP[i][i] = 1;

	for (int i = 2 ; i <= K + 1 ; i++)
		for (int j = i + 1 ; j < i ; j++)
			TP[i][j] = (TP[i - 1][j - 1] + TP[i - 1][j]) % M;

	POT[0] = 1;
	for (int i = 1 ; i <= K + 1 ; i++)
		POT[i] = POT[i - 1] * (N + 1) % M;
}

void solve(){
	S[0] = N;
}

int main(){
	cin >> N >> K >> M;

	precalc();

	solve();

	return 0;
}
