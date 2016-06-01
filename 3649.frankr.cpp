//3649 - Diamond Collector
//Tabla acumulativa
//frankr@coj

#include <bits/stdc++.h> 

using namespace std; 

const int MAXN = 1001;
const int MAXK = 10002;

int N, K;
int A[MAXN];
int F[MAXK];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); 

	cin >> N >> K;

	for (int i = 0 ; i < N ; i++){
		int X;
		cin >> X;
		X++;
		F[X]++;
		A[i] = X;
	}

	for (int i = 1 ; i < MAXK ; i++)
		F[i] += F[i - 1];
	
	int sol = 0;
	for (int i = 0 ; i < N ; i++){
		if (A[i] + K < MAXK && sol < F[A[i] + K] - F[A[i] - 1])
			sol = F[A[i] + K] - F[A[i] - 1];
	}

	cout << sol << endl;

	return 0;
}
