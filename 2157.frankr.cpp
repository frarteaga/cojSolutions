//FIXME: WA
//2157 - A Counting Problem I
//math
//See A002415
//frankr@coj

#include <bits/stdc++.h>

using namespace std;

#define DBG(x) cerr << __LINE__ << ": " << (#x) << " = " << (x) << endl;

typedef pair<double, double> P;
typedef pair<int, int> pii;

const double PI = acos(-1);
const double PId2 = PI / 2.0;
const double a270 = PI * 3.0 / 2.0;
const double EPS = 0.00001;

#define X first
#define Y second

int N;

P rotccw(P a, P b, double ang){
	//P t(a);
	//a.X = a.Y = 0;
	b.X -= a.X;
	b.Y -= a.Y;
	double r = sqrt(b.X * b.X + b.Y * b.Y);
	double alfa = acos(b.X / r);
	if (b.Y < 0)
		alfa += PI;
	double beta = ang + alfa;
	//DBG(alfa * 180.0 / PI);
	//DBG(r);
	P res;
	res.X = r * cos(beta);
	res.Y = r * sin(beta);
	//DBG(res.X);
	//DBG(res.Y);
	res.X += a.X;
	res.Y += a.Y;
	return res;
}

bool equals(P a, P b){
    return fabs(a.X - b.X) < EPS && fabs(a.Y - b.Y) < EPS;
}

void UnitTests(){
//	for (int i = 1 ; i <= 100000 ; i++){
		assert(equals(rotccw(P(1, 1), P(2, 2), PId2), P(0, 2)));
		assert(equals(rotccw(P(1, 1), P(3, 2), PId2), P(0, 3)));
		assert(equals(rotccw(P(0, 0), P(1, 2), PId2), P(-2, 1)));
		assert(equals(rotccw(P(0, 0), P(1, 5), PId2), P(-5, 1)));
		assert(equals(rotccw(P(-1, -1), P(0, -1), PId2), P(-1, 0)));
		assert(equals(rotccw(P(-1, -1), P(0, 0), a270), P(0, -2)));
		assert(equals(rotccw(P(1, 2), P(1, 1), a270), P(0, 2)));
		assert(equals(rotccw(P(-1, -1), P(0, 0), PId2 / 2.0), P(-1, 0.4142135623730951)));
//	}
}

bool inGrid(P a){
	return a.X >= 1.0 - EPS && a.X <= EPS + N
	    && a.Y >= 1.0 - EPS && a.Y <= EPS + N;
}

bool square( int x1, int y1, int x2, int y2 )
{
	int dx = x2-x1, dy = y1-y2;
	if( x1+dy <= N && y1+dx <= N && x2+dy <= N && y2+dx <= N )
	    return true;
	return false;
}

int p = 0;
pii v[10001];

int main(){
	UnitTests();
	while (cin >> N){
//		for (int i = 1 ; i <= N ; i++)
//			for (int j = 1 ; j <= N ; j++)
//				v[p++] = pii(i, j);
//		int sol = 0;
//		for (int i = 0 ; i < p ; i++)
//			for (int j = i + 1 ; j < p ; j++)
//				if (square(v[i].X, v[i].Y, v[j].X, v[j].Y))
//					sol++;
//		cout << sol << '\n';
		int sol = 0;
		for (int x1 = 1 ; x1 <= N ; x1++)
			for (int y1 = 1 ; y1 <= N ; y1++)
				for (int x2 = 1 ; x2 <= N ; x2++)
					for (int y2 = 1 ; y2 <= N ; y2++)
						if (x1 != x2 || y1 != y2){
							P a(x1, y1);
							P b(x2, y2);

							P c = rotccw(a, b, PId2);
							P d = rotccw(b, a, a270);

							if (inGrid(c))
								if (inGrid(d))
									sol++;

							c = rotccw(b, a, PId2);
							d = rotccw(a, b, a270);

							if (inGrid(c))
								if (inGrid(d))
									sol++;
						}

		//DBG(sol);
		assert(sol % 8 == 0);
		sol /= 8;
		cout << sol << '\n';
	}
	return 0;
}

