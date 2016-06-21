#include <bits/stdc++.h> 

using namespace std; 

typedef long long LL; 

LL N;

int main(){
	cin >> N;

	LL sol = 0;
	for (int i = 1 ; i <= N ; i++){
		int x = i;
		while (x / 2 > 0){
			sol += x / 2;
			x /= 2;
		}
	}

	cout << sol << '\n';

	return 0;
}
