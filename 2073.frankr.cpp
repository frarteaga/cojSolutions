//2073 - Casting Spells
//Palindromos, hashing
//frankr@coj

#include <bits/stdc++.h> 

using namespace std; 

#define V(c) ((c) - 'A' + 1)

typedef long long LL; 

const int MAXN = 3e5 + 1;
const LL B = 53;
const LL MOD = 2e9 + 99;

int N;
string S;
LL pot[MAXN][2];
LL hlr[MAXN][2];
LL hrl[MAXN + 1][2];
int radius[MAXN];

void precalc(){
	pot[0][0] = pot[0][1] = 1;
	for (int i = 1 ; i < MAXN ; i++){
		//pot[i][0] = pot[i - 1][0] * B;
		pot[i][1] = pot[i - 1][1] * B % MOD;
	}
}

void hash_prefix(){
	for (int i = 1 ; i <= N ; i++){
		//hlr[i][0] = hlr[i - 1][0] * B + V(S[i]);
		hlr[i][1] = (hlr[i - 1][1] * B + V(S[i])) % MOD;
	}
	
	for (int i = N ; i >= 1 ; i--){
		//hrl[i][0] = hrl[i + 1][0] * B + V(S[i]);
		hrl[i][1] = (hrl[i + 1][1] * B + V(S[i])) % MOD;
	}
}

pair<LL, LL> hashLR(int a, int b){
	//LL h1 = hlr[b][0] - pot[b - a + 1][0] * hlr[a - 1][0];
	LL h2 = hlr[b][1] - pot[b - a + 1][1] * hlr[a - 1][1] % MOD;
	if (h2 < 0)
		h2 += MOD;
	return make_pair(0, h2);
	//return make_pair(h1, h2);
}

pair<LL, LL> hashRL(int a, int b){
	//LL h1 = hrl[a][0] - pot[b - a + 1][0] * hrl[b + 1][0];
	LL h2 = hrl[a][1] - pot[b - a + 1][1] * hrl[b + 1][1] % MOD;
	if (h2 < 0)
		h2 += MOD;
	return make_pair(0, h2);
	//return make_pair(h1, h2);
}

void find_radius(){
	for (int i = 1 ; i < N ; i++){
		radius[i] = 0;
		int ini = 0;
		int fin = min(i, N - i);
		while (ini < fin){
			int mit = (ini + fin + 1) / 2;

			pair<LL, LL> hr = hashLR(i + 1, i + mit);
			pair<LL, LL> hl = hashRL(i - mit + 1, i);

			if (hr == hl)
				ini = mit;
			else
				fin = mit - 1;
		}
		radius[i] = ini;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); 

	precalc();

	int c;
	cin >> c;
	while (c--){
		cin >> S;
		N = S.size();
		S = " " + S;

		hash_prefix();

		find_radius();

//		for (int i = 1 ; i < N ; i++)
//			cout << radius[i] << ' ';
//		cout << endl;

		int sol = 0;
		for (int i = 1 ; i < N ; i++){
			int r = radius[i];
			if (r & 1)
				r--;
			while (r > 0 && 2 * r > sol){
				if (radius[i + r / 2] >= r / 2)
					break;
				r -= 2;
			}
			if (sol < 2 * r)
				sol = 2 * r;
		}

		cout << sol << '\n';
	}
	
	return 0;
}
