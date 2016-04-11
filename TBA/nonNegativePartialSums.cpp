/*
B - Non-negative Partial Sums (Hello 2016 en judge.matcom.uh.cu)
Time Limit: 5 second(s)
Memory Limit: 256 megabytes

Usted recibe una secuencia de $n$ números $A_0, ..., A_{n-1}$. Un corrimiento
cíclico de $k$ posiciones $(0 \le k \le n - 1)$ termina en la siguiente
secuencia $A_k, A_{k+1}, ..., A_0, A_1, ..., A_{k-1}$.  El problema que
queremos resolver es cuántos corrimientos cíclicos satisfacen la condición que
la suma de los primeros $i$ números es mayor o igual que cero para todos los
$i$ $(1 \le i \le n)$.

Input

Cada caso consiste de dos líneas. La primera contiene el número $n$ $(1\le n
\le 1000000)$, el número de enteros en la secuencia. La segunda contiene $n$
enteros $A_0, ..., A_{n-1}$ $(-1000 \le A_i \le 1000)$ representando la
sequencia de números. La entrada termina con una línea que
contiene $0$.

*La cantidad de casos $T$ es $(T \le 105)$.

Output

Para cada caso imprima una línea, el número de corrimientos cíclicos que
satisfacen la condición.

Sample test(s)

Input

3 
2 2 1 
3 
-1 1 1 
1
-1 
0

Output

3
2 
0

Tags: Ordenamiento y búsqueda, Sumas Parciales
frankr@coj
*/

#include <bits/stdc++.h> 

using namespace std; 

const int MAXN = 1e6 + 1;

int N;
int A[MAXN];
int SP[MAXN];
int MDI[MAXN]; //minimo acumulado de derecha a izquierda
int MID[MAXN]; //minimo acumulado de izquierda a derecha

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0); 

	while (cin >> N){
		if (N == 0)
			break;

		for (int i = 1 ; i <= N ; i++){
			cin >> A[i];
			SP[i] = SP[i - 1] + A[i];
		}

		MID[1] = SP[1];
		for (int i = 2 ; i <= N ; i++)
			MID[i] = min(MID[i - 1], SP[i]);

		MDI[N] = SP[N];
		for (int i = N - 1 ; i > 0 ; i--)
			MDI[i] = min(MDI[i + 1], SP[i]);

		int sol = 0;
		for (int i = 1 ; i <= N ; i++){
			int sum1 = SP[i];
			int sum2 = SP[N] - SP[i];

			if (i != N && MDI[i + 1] - sum1 < 0)
				continue;
			if (MID[i] + sum2 < 0)
				continue;
			sol++;
		}

		cout << sol << '\n';
	}

	return 0;
}
