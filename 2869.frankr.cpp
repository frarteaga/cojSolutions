//2869 - LCSIS
//Idea: SQRT-Descomposition
//frankr@coj

#include<cstdio>
#include<cmath>

const int MAXN = 100001;
const int MAXB = 320;

struct Block{
	int R, L;
	int X;
};

int A[MAXN + MAXB];
int LB, CB;
Block B[MAXB];

inline int I(int b){
	return b * LB;
}

inline int F(int b){
	return I(b) + LB - 1;
}

int IS(int a, int b){
	int r = 0;
	int i = a;
	while (i <= b){
		int j = i + 1;
		while (j <= b && A[j] > A[j - 1])
			j++;
		if (r < j - i)
			r = j - i;	
		i = j;
	}
	return r;
}

int Rr(int pi){
	int r = 1;
	while (r < LB && A[pi + r] > A[pi + r - 1])
		r++;
	return r;
}

int Ll(int pf){
	int r = 1;
	while (r < LB && A[pf - r] < A[pf - r + 1])
		r++;
	return r;
}

inline int max(int a, int b){
	if (a > b)
		return a;
	return b;
}

inline int min(int a, int b){
	return -max(-a, -b);
}

int query(int a, int b){
	int ba = a / LB;
	int bb = b / LB;
	if (ba == bb)
		return IS(a, b);
	int r = max(IS(a, F(ba)), IS(I(bb), b));
	int act = min(B[ba].L, F(ba) - a + 1);
	int blo = ba + 1;
	while (blo < bb){
		if (A[F(blo - 1)] < A[I(blo)])
			act += B[blo].R;
		else
			act = B[blo].L;
		if (r < act)
			r = act;
		if (B[blo].X < LB)
			act = B[blo].L;
		if (r < B[blo].X)
			r = B[blo].X;
		blo++;
	}
	if (A[F(blo - 1)] < A[I(blo)])
		act += min(B[blo].R, b - I(bb) + 1);
	if (r < act)
		r = act;
	return r;
}

int main(){
	//freopen("d.txt", "r", stdin);
	int N, M;
	while (scanf("%d%d", &N, &M) != EOF){
		for (int i = 0 ; i < N ; i++)
			scanf("%d", &A[i]);
	
		LB = sqrt(N);	
		for (int i = 1 ; i <= LB ; i++)
			A[N + i] = 0;
		CB = (N + LB) / LB;
		for (int b = 0 ; b < CB ; b++){
			B[b].X = IS(I(b), F(b));
			B[b].R = Rr(I(b));
			B[b].L = Ll(F(b));
		}

		for ( ; M > 0 ; M--){
			char q[8];
			int a, b;
			scanf("%s%d%d", q, &a, &b);
			if (q[0] == 'U'){
				A[a] = b;
				b = a / LB;
				B[b].X = IS(I(b), F(b));
				B[b].R = Rr(I(b));
				B[b].L = Ll(F(b));
			}
			else{
				int r = query(a, b);
				printf("%d\n", r);
			}
		}
	}

	return 0;
}
