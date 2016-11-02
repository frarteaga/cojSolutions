/*
Prob: 2074 - Defense Lines
Idea: Simple DP + BIT for minimun values 
frankr@coj
*/

#include <bits/stdc++.h> 

using namespace std; 

const int MAXN = 2e5 + 4;

int T;
int N;
int A[MAXN];
int B[MAXN];
int ID[MAXN];
int D[MAXN];
int S[MAXN];

struct BIT{
	int T[MAXN];

	BIT(){
		memset(T, 0, sizeof T);
	}

	void update(int i, int v){
		while (i <= N){
			T[i] = max(T[i], v);
			i += i & -i;
		}
	}

	int query(int i){
		int r = 0;
		while (i > 0){
			r = max(r, T[i]);
			i -= i & -i;
		}
		return r;
	}
};


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); 
	//freopen("d.in", "r", stdin);

	cin >> T;	
	while (T--){
		cin >> N;
		for (int i = 1 ; i <= N ; i++){
			cin >> A[i];
			B[i] = A[i];
		}
		
		sort(B + 1, B + N + 1);

		for (int i = 1 ; i <= N ; i++)
			ID[i] = lower_bound(B + 1, B + N + 1, A[i]) - B;

		S[N + 1] = 0;
		for (int i = N ; i >= 1 ; i--){
			S[i] = 1;
			if (ID[i] < ID[i + 1])
				S[i] += S[i + 1];
		}

		int sol = 0;
		BIT bit;

		for (int i = 1 ; i <= N ; i++){
			D[i] = 1;
			if (ID[i] > ID[i - 1])
				D[i] += D[i - 1];

			bit.update(ID[i], D[i]);

			int s = S[i] + bit.query(ID[i] - 1);

			if (sol < s)
				sol = s;
		}

		cout << sol << '\n';
	}

	return 0;
}
