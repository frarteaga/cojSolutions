//3527 - Throwing Eggs
//frankr@coj

#include <bits/stdc++.h> 

using namespace std; 

typedef long long LL;

LL N, S, K;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); 

	int T;
	cin >> T;
	//assert(T <= 50000);

	while (T--){
		cin >> K >> S >> N;

		//assert(1 <= K); assert(K <= 60);
		//assert(1 <= S); assert(S < (1LL << 60));

		N = min(N, 61LL);
		LL sol = __builtin_popcountll(((1LL << N) - 1) & S) + ((S & -S) == (1LL << N));

		cout << sol << '\n';
	}

	return 0;
}

