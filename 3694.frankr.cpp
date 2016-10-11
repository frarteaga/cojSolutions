//3694 - Rubik Packages
//Brute Force
//frankr@coj

#include <bits/stdc++.h> 

using namespace std; 

int N;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);	

	while (1){
		cin >> N;
		if (N == 0)
			break;

		int sol = 0;
		int i = 1;
		while (i * i * i <= N){
			if (N % (i * i * i) == 0)
				sol++;
			i++;
		}

		cout << sol << '\n';
	}

	return 0;
}
