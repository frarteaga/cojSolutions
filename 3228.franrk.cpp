//3228 - Block Line
//Idea: SQRT-Descomposition
//frankr@coj

#include <bits/stdc++.h> 

using namespace std; 

const int MAXN = 1e5 + 1;
const int MAX_B = 320;
const int oo = 2e9;

int A[MAXN + MAX_B];
int B[MAX_B][MAX_B + 2];

int N, Q;
int LB, CB; //longitud de bloque y cantidad de bloques

int queryBlock(int b, int n, int m, int x){
	int r = 0;
	for (int i = 1 ; i <= B[b][0] ; i++)
		if (n <= B[b][i] && B[b][i] <= m){
			if (A[B[b][i]] <= x)
				r++;
		}
	return r;
}

bool cmpUP(int value, int it){
	return value < A[it];
}

int query(int a, int b, int x){
	int lo = a / LB;
	int hi = b / LB;

	if (lo == hi)
		return queryBlock(lo, a, b, x);

	int r = 0;

	if (a % LB){
		lo++;
		r += queryBlock(lo - 1, a, lo * LB - 1, x);
	}
	
	if ((b + 1) % LB){
		r += queryBlock(hi, hi * LB, b, x);
		hi--;
	}

	while (lo <= hi){
		r += upper_bound(B[lo] + 1, B[lo] + B[lo][0] + 1, x, cmpUP) - B[lo] - 1;
		lo++;
	}

	return r;
}

bool cmp(int i, int j){
	return A[i] < A[j];
}

void update(int a, int x){
	int b = a / LB;
	A[a] = x;
	sort(B[b] + 1, B[b] + B[b][0] + 1, cmp);
}

int main(){	
	ios_base::sync_with_stdio(0); cin.tie(0); 

	cin >> N >> Q;
	for (int i = 0 ; i < N ; i++)
		cin >> A[i];

	LB = (int)sqrt(N);

	for (int i = 1 ; i <= LB ; i++)
		A[N + i] = oo; //sentinelas
	
	//-- PRECALC --
	for (int i = 0 ; i < N ; i += LB){
		for (int j = i ; j < i + LB ; j++)
			B[CB][++B[CB][0]] = j;
		sort(B[CB] + 1, B[CB] + B[CB][0] + 1, cmp);
		CB++;
	}
	//-- END PRECALC --

	for (int q = 0 ; q < Q ; q++){
		char op;
		cin >> op;
		int a, b, x;
		if (op == 'Q'){
			cin >> a >> b >> x;
			a--; b--;
			int r = query(a, b, x);
			cout << r << '\n';
		}
		else{
			cin >> a >> x;
			a--;
			update(a, x);
		}
	}

	return 0;
}