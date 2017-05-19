//http://coj.uci.cu/24h/problem.xhtml?pid=3703

#include <bits/stdc++.h> 

using namespace std; 

typedef long long LL; 
typedef pair<int, int> pii;
typedef std::vector<std::vector<LL> > matrix;

const LL MOD = 1e9 + 7;

int ce;
int N, b;
matrix B;

matrix matrixMultiplication(matrix& matrix1, matrix& matrix2) {
  matrix result;
  int n = matrix1.size();
  for (int i = 0; i < n ; i++) {
    std::vector<LL> empty_(n);
    result.push_back(empty_);
    for (int j = 0; j < n; j++) {
      //result[i].push_back(0);
      for (int k = 0; k < n; k++) {
        result[i][j] = (result[i][j] + matrix1[i][k] * matrix2[k][j]) % MOD;
      }
    }
  }
  return result;
}

matrix pot(int N){
    if (N == 1)
        return B;
    if (!(N & 1)){
        matrix r = pot(N >> 1);
        return matrixMultiplication(r, r);
    }
    matrix r = pot(N - 1);
    return matrixMultiplication(r, B);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); 

	cin >> N >> b;
	
	ce = 1 << b;
	for (int i = 0 ; i < ce + b ; i++){
		std::vector<LL> empty_(ce + b);
		B.push_back(empty_);
	}

	for (int d = 0 ; d < b ; d++){
		for (int e = 0 ; e < ce ; e++){
			int ne = e ^ (1 << d);
			B[e][ne]++;
		}
	}

	for (int i = 1 ; i < b ; i++){
		B[ce][ce + i]++;
		B[ce + i][ce + i]++;
		B[ce + i][1 << i]++;
	}

	matrix S = pot(N + 1);

	LL sol = 0;
	for (int i = 0 ; i < ce ; i++){
		if (__builtin_popcount(i) <= 1)
			sol += S[ce][i];
			sol %= MOD;
	}

	cout << sol + 1 << endl;

	return 0;
}
