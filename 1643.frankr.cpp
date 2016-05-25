/*
1643 - Searching for Stars
Tabla acumulativa, doble puntero
frankr@coj
*/

#include <bits/stdc++.h> 

using namespace std; 

const int MAXN = 502;

int N, M, K;
string A[MAXN];
int C[MAXN][MAXN];
int B[MAXN];

bool isStar(int i, int j){
	int c = 0;
	c += A[i][j - 1] == '1';
	c += A[i - 1][j - 1] == '1';
	c += A[i - 1][j] == '1';
	c += A[i - 1][j - 2] == '1';
	c += A[i - 2][j - 1] == '1';
	return c == 5;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); 

	cin >> N >> M >> K;
	for (int i = 1 ; i <= N ; i++){
		cin >> A[i];
		A[i] = " " + A[i];
	}

	//for (int i = 1 ; i <= N ; i++)
	//	cout << A[i] << endl;

	for (int j = 3 ; j <= M ; j++){
		for (int i = 3 ; i <= N ; i++){
			C[j][i] = C[j][i - 1];
			if (havaStar(i, j))
				C[j][i]++;
		}
	}

	long long sol = 0;
	for (int f1 = 1 ; f1 < N - 1 ; f1++){
		for (int f2 = f1 + 2 ; f2 <= N ; f2++){
			for (int i = 1 ; i <= M ; i++)
				B[i] = B[i - 1] + C[i][f2] - C[i][f1 + 1];

			int c1 = 1;
			int c2 = 3;
			while (c2 < M){
				while (c2 < M && B[c2] - B[c1 + 1] < K)
					c2++;

				while (c1 < c2 - 1 && B[c2] - B[c1 + 1] >= K){
					sol += M - c2 + 1;
					c1++;
				}
			}
		}
	}

	cout << sol << '\n';
	
	return 0;
}
