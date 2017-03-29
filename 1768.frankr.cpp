//1768 - Gap Sums
//SQRT trick
//frankr@coj

#include <bits/stdc++.h> 

using namespace std; 

const int MAXN = 1e5 + 1;
const int SALTO = 301;

typedef long long LL; 

int N, Q;
LL S[MAXN]; //0.8 Mb
LL T[SALTO][MAXN]; //240 Mb

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); 

	cin >> N;
	for (int i = 1 ; i <= N ; i++)
		cin >> S[i];
	
	for (int j = 1 ; j < SALTO ; j++){
		for (int i = 1 ; i <= N ; i++)
			if (i - j >= 0)
				T[j][i] = T[j][i - j] + S[i];
			else
				T[j][i] = S[i];
	}

	cin >> Q;
	for (int q = 1 ; q <= Q ; q++){
		int A, B, C;
		cin >> A >> B >> C;
		LL res = 0;
		if (B < SALTO){
			int ant = 0;
			if (A - B >= 0)
				ant = A - B;
			res = T[B][A + (C - 1) * B] - T[B][ant];
		}
		else{
			for (int i = A ; i <= A + (C - 1) * B ; i += B)
				res += S[i];
		}
		cout << res << '\n';
	}

	return 0;
}
