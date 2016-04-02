//3560 - How Many Square Free Numbers (Copa UCI)
/*
Solución: Es necesario probar los siguientes teoremas

   * El producto A*B de dos números square free A y B es square free sí y solo sí A y B son primos relativos.
   * El producto de N números square free es square free también sí y solo sí ellos son primos relativos dos a dos.
Una vez que se demostre lo anterior el problema se reduce a examinar solo los 2^N - 1 subconjuntos no vacíos y 
cada vez que tengamos un subconjunto donde todos sus elementos son primos dos a dos entonces contarlo sí su 
producto no ha aparecido antes, para saber esto se puede usar alguna función hash o logaritmos. Sí se desea 
evitar posibles colisiones de los valores hash o la precisión de los logaritmos entonces es necesario emplear 
algún algoritmo de factorización efeciente para los rangos propuestos.
*/
//frankr@coj


#include <bits/stdc++.h> 

using namespace std; 

const int MAXN = 22;

typedef unsigned long long ULL;

const ULL MOD = 1700000339;
const ULL MOD2 = 1790000273;

int N;
ULL A[MAXN];
vector<int> primos;
set< pair<ULL, ULL> > sqfp;
ULL H1, H2;
bool MCD1[MAXN][MAXN];

void back(int h, ULL H1, ULL H2){
	for (int i = 0 ; i < primos.size() ; i++)
		if (!MCD1[primos[i]][h])
			return;

	primos.push_back(h);

	sqfp.insert(pair<ULL, ULL>(H1, H2));

	for (int i = h + 1 ; i <= N ; i++)
		back(i, H1 * (A[i] % MOD2) % MOD2, H2 * (A[i] % MOD) % MOD);

	primos.pop_back();
}


int main(){
	cin >> N;

	for (int i = 0 ; i <= N ; i++)
		cin >> A[i];

	for (int i = 0 ; i <= N ; i++){
		for (int j = i ; j <= N ; j++){
			MCD1[i][j] = MCD1[j][i] = (__gcd(A[i], A[j]) == 1);
		}
	}
	
	primos.push_back(0);
	H1 = A[0] % MOD2;
	H2 = A[0] % MOD;
	for (int h = 1 ; h <= N ; h++)
		back(h, H1 * (A[h] % MOD2) % MOD2, H2 * (A[h] % MOD) % MOD);

	cout << sqfp.size() << endl;

	return 0;
}