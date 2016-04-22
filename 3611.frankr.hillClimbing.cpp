//3611 - The Rewards

//Algoritmo: Hill Climbing o Escalador de Colinas, con cierta probabilidad 
//(TODO: determinarla según la cantidad de repeticiones) da la solución
//óptima, en los otros casos da soluciones aproximadas a la óptima.
//TODO: marcar estados ya vistos con una función hash para no
//explorarlos de nuevo.

//frankr@coj

#include <bits/stdc++.h> 

using namespace std; 

typedef long long LL;
//typedef pair< int*, LL* > piL;

#define miN(X, Y) ((X) < (Y) ? (X) : (Y))
#define maX(X, Y) ((X) > (Y) ? (X) : (Y))

const int MAXN = 24;

int N;
LL A[MAXN];
int P[3];
LL S[3];
int CE;

inline LL dif(LL* SS){
	LL mi = miN(SS[0], SS[1]);
	mi = miN(mi, SS[2]);
	LL ma = maX(SS[0], SS[1]);
	ma = maX(ma, SS[2]);
	return ma - mi;
}

inline void swapC(int i, int j, int bi, int bj, int* PP, LL* SS){
	//CE++;
	PP[0] = P[0]; PP[1] = P[1]; PP[2] = P[2];
	SS[0] = S[0]; SS[1] = S[1]; SS[2] = S[2];
	PP[i] ^= (1 << bi);
	PP[i] ^= (1 << bj);
	PP[j] ^= (1 << bj);
	PP[j] ^= (1 << bi);
	SS[i] -= A[bi];
	SS[i] += A[bj];
	SS[j] -= A[bj];
	SS[j] += A[bi];
}

inline void putC(int i, int j, int bi, int* PP, LL* SS){
	//CE++;
	PP[0] = P[0]; PP[1] = P[1]; PP[2] = P[2];
	SS[0] = S[0]; SS[1] = S[1]; SS[2] = S[2];
	PP[i] ^= (1 << bi);
	PP[j] ^= (1 << bi);
	SS[i] -= A[bi];
	SS[j] += A[bi];
}

const int Q[3][2] = {{0, 1}, {0, 2}, {1, 2}};

LL hillClimbing(){
	for (int i = 0 ; i <  3 ; i ++)
		P[i] = S[i] = 0;

	//Comenzando con una configuración aleatoria
	for (int i = 0 ; i < N ; i++){ 
		int x = rand() % 3;
		P[x] |= (1 << i); 
		S[x] += A[i];
	}
//	cout << "D: " << S[0] << " " << S[1] << " " << S[2] << endl;
	
	do {
		LL solAct = dif(S);
		LL best = solAct;
		//piL Best;
		int BestP[3];
		LL BestS[3];
		for (int q = 0 ; q < 3 ; q++){
			int i = Q[q][0];
			int j = Q[q][1];

			for (int bi = 0 ; bi < N ; bi++)
				if ((1 << bi) & P[i]){
					for (int bj = 0 ; bj < N ; bj++)	
						if ((1 << bj) & P[j]){
							int solVecP[3];
							LL solVecS[3];
							swapC(i, j, bi, bj, solVecP, solVecS);
							//cout << "D: " << solVecS[0] << " " << solVecS[1] << " " << solVecS[2] << endl;
							LL d = dif(solVecS);
							if (best > d){
								best = d;
								BestP[0] = solVecP[0];
								BestP[1] = solVecP[1];
								BestP[2] = solVecP[2];
								BestS[0] = solVecS[0];
								BestS[1] = solVecS[1];
								BestS[2] = solVecS[2];
							}
						}
				}

			for (int bi = 0 ; bi < N ; bi++)
				if ((1 << bi) & P[i]){
					int solVecP[3];
					LL solVecS[3];
					putC(i, j, bi, solVecP, solVecS);
					//cout << "D: " << solVecS[0] << " " << solVecS[1] << " " << solVecS[2] << endl;
					LL d = dif(solVecS);
					if (best > d){
						best = d;
						BestP[0] = solVecP[0];
						BestP[1] = solVecP[1];
						BestP[2] = solVecP[2];
						BestS[0] = solVecS[0];
						BestS[1] = solVecS[1];
						BestS[2] = solVecS[2];
					}
				}
		}		
		if (best >= solAct)
			return solAct;
		S[0] = BestS[0];
		S[1] = BestS[1];
		S[2] = BestS[2];
		P[0] = BestP[0];
		P[1] = BestP[1];
		P[2] = BestP[2];
	}while (1);
}

int main(){
	srand(101);

	cin >> N;
	for (int i = 0 ; i < N ; i++)
		cin >> A[i];
	
	int R = 10000; //Si se sube hasta 800000 repeticiones dan AC todos pero se demora
			//~35 segundos
	LL sol = 1LL << 62;
	while (R--){
		LL sol1 = hillClimbing();
		if (sol > sol1)
			sol = sol1;
	}

	cout << sol << endl;
	//cout << CE; //cuantas configuraciones examino
						
	return 0;
}
