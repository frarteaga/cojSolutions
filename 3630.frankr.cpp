//Standard Deviation I
//frankr@coj

#include <bits/stdc++.h> 

using namespace std; 

long long n;
long long sp[1000001];

int main(){
	int p = 1;
	for (int i = 0 ; i < 1000001 ; i++){
		long long c = 2 * i + 1;
		c *= c;
		sp[p] = sp[p - 1] + c;
		p++;
	}

	cout.precision(9);
	cout << fixed;

	while (1){
		cin >> n;
		if (n == 0)
			break;
		double S = sp[n] - n * n * n;
		S /= (double)(n - 1);
		S = sqrt(S);
		cout << S << '\n';
	}

	return 0;
}

