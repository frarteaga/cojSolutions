//3734 - Count Odd Increasing Subsequences
//O(N Log N) with two BITs
//frankr@coj

#include <bits/stdc++.h> 

using namespace std; 

const int MAXN = 1e5 + 3;
const int MOD = 1e9 + 7;

int T;
int N;
int A[MAXN];
int C[MAXN];
int P[MAXN];
int Id[MAXN];
//int DP[MAXN][2];

struct BIT{
	int T[MAXN];

	BIT(){
		memset(T, 0, sizeof T);
	}

	void update(int i, int v){
		while (i <= N){
			T[i] = (T[i] + v) % MOD;
			i += i & -i;
		}
	}

	int query(int i){
		int r = 0;
		while (i > 0){
			r = (r + T[i]) % MOD;
			i -= i & -i;
		}
		return r;
	}
};


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); 

	cin >> T;

	while (T--){
		cin >> N;
		BIT bit[2];

		for (int i = 1 ; i <= N ; i++){
			cin >> A[i];
			P[i] = A[i] & 1;
			C[i] = A[i];
			//DP[i][P[i]] = 1;
			//DP[i][!P[i]] = 0;
		}

		sort(C + 1, C + N + 1);
		for (int i = 1 ; i <= N ; i++){
			Id[i] = lower_bound(C + 1, C + N + 1, A[i]) - C;
		}

		for (int i = 1 ; i <= N ; i++){
			bit[P[i]].update(Id[i], 1);
			bit[0].update(Id[i], bit[P[i]].query(Id[i] - 1));
			bit[1].update(Id[i], bit[!P[i]].query(Id[i] - 1));
		}

		int sol = bit[1].query(N);
		cout << sol << '\n';

		/*
		for (int i = 1 ; i <= N ; i++){
			for (int j = 1 ; j < i ; j++){
				if (A[j] < A[i]){
					DP[i][0] = (DP[i][0] + DP[j][P[i]]) % MOD;
					DP[i][1] = (DP[i][1] + DP[j][!P[i]]) % MOD;
				}
			}
		}

		int sol = 0;
		for (int i = 1 ; i <= N ; i++){
			sol = (sol + DP[i][1]) % MOD;
		}
		cout << sol << endl;
		*/
	}
	return 0;
}
