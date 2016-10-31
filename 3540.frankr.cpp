//3540 - Exactly K times
//BS + KMP O(N^2 Log N)
//frankr@coj

#include <bits/stdc++.h> 

using namespace std; 

const int MAXN = 1001;

int K, N;
string S;
int P[MAXN];

void pre_kmp(int i, int j){
	memset(P, 0, sizeof P);
	P[1] = 0;
	int q = 0;
	for (int o = 2 ; o <= j - i + 1 ; o++){
		while (q > 0 && S[i + o - 1] != S[i + q])
			q = P[q];
		if (S[i + q] == S[i + o - 1])
			q++;
		P[o] = q;
	}
}

int kmp(int L){
	int mc = 0;
	for (int i = 1 ; i <= N - L + 1 ; i++){
		pre_kmp(i, i + L - 1);
		int c = 0;
	
		int q = 0;	
		for (int x = 1 ; x <= N ; x++){
			while (q > 0 && S[i + q] != S[x])
				q = P[q];
			if (S[i + q] == S[x])
				q = q + 1;
			if (q == L){
				c++;
				q = P[q];
			}
		}

//		if (c == K)
//			return c;
		mc = max(c, mc);
	}

	return mc;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); 

	cin >> K;
	cin >> S;
	N = S.size();
	S = " " + S; 

	int ini = 1, mit, fin = N;

	while (fin - ini > 5){
		mit = (ini + fin) >> 1;

		if (kmp(mit) >= K)
			ini = mit;
		else
			fin = mit - 1;
	}

	int sol = -1;
	while (fin >= ini){
		if (kmp(fin) == K){
			sol = fin;
			break;
		}
		fin--;
	}

	cout << sol << endl;

	return 0;
}
