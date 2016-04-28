/*
Contando pares ST1
Fuerza bruta: iterar por todos lo pares y comprobar la condición
frankr@coj
*/

#include <bits/stdc++.h> 

using namespace std;

int main(){
	int n;
	cin >> n;
	//for (int n = 1 ; n <= 15 ; n++){
		int c = 0;
		for (int i = 0 ; i < (1 << n) ; i++)
			for (int j = i + 1 ; j < (1 << n) ; j++)
				if ((j & i) == i)
					c++;
		cout << c << '\n';
//		cout << n << ") " << c << endl;
//	}

	return 0;
}

/*
k  2^(n - k) - 1 

n = 2

c(2, 0) * (2^2 - 1) + c(2, 1) * (2^1 - 1)

sum(c(n, k) * (2^(n - k) - 1)) para k=0..n-1
*/
