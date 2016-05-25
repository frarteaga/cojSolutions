//2250 - Substring Frequency
//Hashing
//frankr@coj

#include <bits/stdc++.h> 

using namespace std; 

typedef long long LL; 

const LL B = 31;
const int MAXN = 1e6 + 1;

#define V(c) ((c) - 'a' + 1)

string P, T;
int lP, lT;
LL hT[MAXN];
LL pot[MAXN];

//retorna el hash[a..b]
LL h(int a, int b){
	int e = b - a + 1;
	LL res = hT[b] - hT[a - 1] * pot[e];
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); 
	int t, tt;
	cin >> t;
	tt = 1;
	while (t--){
		cin >> T;
		cin >> P;

		lP = P.size();
		lT = T.size();

		P = " " + P;
		T = " " + T;

		LL hP = 0;
		for (int i = 1 ; i <= lP ; i++)
			hP = hP * B + V(P[i]);

		pot[0] = 1; //FIXME: sacar
		for (int i = 1 ; i <= lT ; i++){
			pot[i] = pot[i - 1] * B;
			hT[i] = hT[i - 1] * B + V(T[i]);
		}

		int c = 0;
		for (int i = 1 ; i <= lT - lP + 1 ; i++)
			if (h(i, i + lP - 1) == hP)
				c++;
		
		cout << "Case " << tt << ": " << c << '\n';
		tt++;
	}

	return 0;
}
