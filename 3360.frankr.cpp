//3360 - The Baseball Team
//Tabla acumulativa
//frankr@coj

#include <bits/stdc++.h> 

const int MAXN = 1001;
const int MAXH = 171;

using namespace std; 

int N, Q;
int A[MAXN];
int f[MAXN][MAXH];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); 

	cin >> N >> Q;

	for (int i = 1 ; i <= N ; i++){
		cin >> A[i];
		A[i] -= 50;
	}

	for (int i = 1 ; i <= N ; i++){
		for (int j = 0 ; j < MAXH ; j++){
			f[i][j] = f[i - 1][j];
			if (A[i] <= j)
				f[i][j]++;
		}
	}	

	while (Q--){
		int a, b;
		cin >> a >> b;

		int M = max(A[a], A[b]);
		int m = f[b][M] - f[a - 1][M];
		int r = b - a + 1 - m;

		cout << r << '\n';
	}

	return 0;
}
