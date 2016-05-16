/*
3552 - Be Fast
Kuhn Algorithm for Unweighted MCBM
Augmenting Path
frankr@coj
*/

#include <bits/stdc++.h> 

using namespace std; 

const int MAXN = 20001;

int N, M;
vector<int> A[MAXN];
bool mk[MAXN];
int mat[MAXN];

bool Aug(int nod){
	if (mk[nod])
		return false;
	mk[nod] = true;
	for (int i = 0 ; i < A[nod].size() ; i++){
		int to = A[nod][i];
		if (mat[to] == -1 || Aug(mat[to])){
			mat[to] = nod;
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); 

	while (1){
		cin >> N >> M;
		if (N == 0)
			break;

		for (int i = 0 ; i < N + N ; i++){
			A[i].clear();
			mat[i] = -1;
		}

		for (int i = 0 ; i < M ; i++){
			int x, y;
			cin >> x >> y;
			y += N;
			A[x].push_back(y);
			A[y].push_back(x);
		}

		for (int i = 0 ; i < N ; i++){
			memset(mk, 0, sizeof mk);
			Aug(i);
		}

		int sol = 0;
		for (int i = N ; i < N + N ; i++)
			sol += mat[i] != -1;

		cout << sol << '\n';
	}

	return 0;
}
