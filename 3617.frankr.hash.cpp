//3617 - String Compression
//Hashing
//frankr@coj

#include <bits/stdc++.h> 

using namespace std; 

typedef unsigned long long ULL; 

#define V(c) ((c) - 'A' + 1)

const int MAXN = 1e6 + 1;
const ULL B = 41;

int N;
string S;
ULL pot[MAXN];
ULL hash[MAXN];

inline ULL h(int a, int b){
	ULL r = hash[b] - hash[a - 1] * pot[b - a + 1];
	return r; 
}

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0); 
	cin >> S;
	N = S.size();
	S = " " + S;

	pot[0] = 1ULL;
	for (int i = 1 ; i <= N ; i++){
		pot[i] = pot[i - 1] * B;
		hash[i] = hash[i - 1] * B + V(S[i]);
	}

	bool ok = false;
	int i;
	for (i = 1 ; i <= N / 2 && !ok ; i++){
		if (N % i == 0){
			ok = true;
			ULL h1 = h(1, i);
			for (int j = 2 ; j <= N / i && ok ; j++){
				if (h(j * i - i + 1, j * i) != h1)
					ok = false;
			}	
		}
	}

	if (ok)
		cout << S.substr(1, i - 1) << '\n';
	else
		cout << 0 << '\n';

	return 0;
}
