//3559 - Little Rakin
//Factorizar, ad-hoc
//frankr@coj

#include <bits/stdc++.h> 

using namespace std; 

typedef long long LL; 

map<int, LL> fact(int n){
	map<int, LL> m;
	if (n % 2 == 0)
		m[2] = 0;
	while (n % 2 == 0){
		m[2]++;
		n /= 2;
	}
	for (int i = 3 ; i * i <= n ; i += 2){
		if (n % i == 0){
			m[i] = 0;
			while (n % i == 0){
				m[i]++;
				n /= i;
			}
		}
	}
	if (n > 1)
		m[n] = 1;
	return m;
}

int main(){
	int t;

	cin >> t;

	while (t--){
		int n, a, b;
		cin >> n >> a >> b;
		vector<map<int, LL> > f(41);
		f[0] = fact(a);
		f[1] = fact(b);
		set<int> primos;
		for (auto &x : f[0])
			primos.insert(x.first);
		for (auto &x : f[1])
			primos.insert(x.first);

		for (int i = 2 ; i <= n ; i++){
			for (auto &p : primos)
				f[i][p] = f[i - 1][p] + f[i - 2][p];
			//for (map<int, LL>::iterator x = f[i - 1].begin() ; x != f[i - 1].end() ; x++)
			//	f[i][(*x).first] = (*x).second + f[i - 2][(*x).first];
		}

		for (auto &x : f[n]){
			cout << x.first << " " << x.second << '\n';
		}
		cout << '\n';
	}

	return 0;
}


