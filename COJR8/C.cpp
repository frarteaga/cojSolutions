#include <bits/stdc++.h> 

using namespace std; 

typedef long long LL; 
typedef pair<int, int> pii;

const int MAXN = 1e5 + 1;

int N;
vector<int> A[MAXN];
int g[MAXN];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); 

	cin >> N;
	for (int i = 1 ; i <= N ; i++){
		int a, b;
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);
		g[a]++;
		g[b]++;
	}	

	queue<int> Q;

	for (int i = 1 ; i <= N ; i++)
		if (g[i] == 1)
			Q.push(i);

	int c = 0;
	while (!Q.empty()){
		int x = Q.front();
		Q.pop();
		c++;
		g[x]--;

		for (int j = 0 ; j < (int)A[x].size() ; j++){
			int v = A[x][j];
			if (g[v] > 0)
				g[v]--;
			if (g[v] == 1)
				Q.push(v);
		}
	}

	int s = 0;
	for (int i = 1 ; i <= N ; i++)
		s += g[i];
	
	double sum = s + c;
	double prom = sum / N;

	cout.precision(7);
	cout << fixed;
	cout << prom << endl;

	return 0;
}

/*

5
1 2
2 3
1 3
3 4
4 5

3
3 2
1 3
1 2

1000000000 7
*/
