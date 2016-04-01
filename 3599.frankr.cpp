//Prob: 3599 - Complementary Words
//Idea: DP por intervalos (precalcular)
//frankr@coj

#include <bits/stdc++.h> 

using namespace std; 

const int MAXN = 3001;

#define V(c) ((c) - 'a' + 1)

string S;
int Q;
bool DP[MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); 
	cin >> S;
	int N = S.size();
	S = " " + S;

	for (int i = 1 ; i <= N ; i++)
		DP[i][i] = true;

	for (int i = 1 ; i < N ; i++)
		DP[i][i + 1] = true;

	for (int L = 3 ; L <= N ; L++){
		for (int pos = 1 ; pos <= N - L + 1 ; pos++){
			int sum = V(S[pos]) + V(S[pos + L - 1]);
			int sum2 = V(S[pos + 1]) + V(S[pos + L - 2]);

			if (sum == sum2)
				DP[pos][pos + L - 1] = DP[pos + 1][pos + L - 2];	
			else
				DP[pos][pos + L - 1] = false;
		}	
	}

	cin >> Q;
	for ( ; Q-- ; ){
		int A, B;
		cin >> A >> B;
		A++;
		B++;
		if (A > B)
			swap(A, B);
		if (DP[A][B])
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}
