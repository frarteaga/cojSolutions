//============================================================================
// Name        : a.cpp
// Author      : Ernestico
// Version     :
// Description : RMQ2D + bitmask O(N^3 Log N)
//============================================================================

#include <bits/stdc++.h>
#define maxn 105

using namespace std;

int F, C, K, RMQ[maxn][maxn][10][10];
char mat[maxn][maxn];

inline int lg2 ( int x )
{
 return 31 - __builtin_clz ( x );
}

inline int query ( int x1, int y1, int x2, int y2 )
{
 int lf = lg2 ( x2-x1+1 );
 int lc = lg2 ( y2-y1+1 );
 int a = RMQ[x1][y1][lf][lc];
 int b = RMQ[x1][y2-(1<<lc)+1][lf][lc];
 int c = RMQ[x2-(1<<lf)+1][y1][lf][lc];
 int d = RMQ[x2-(1<<lf)+1][y2-(1<<lc)+1][lf][lc];
 return (a | b | c | d);
}

int main()
{
 

 scanf ("%d%d%d", &F, &C, &K );
 for ( int i = 1; i <= F; i ++ )
  scanf ("%s", mat[i]+1 );

 for ( int i = 1; i <= F; i ++ )
  for ( int j = 1; j <= C; j ++ )
    RMQ[i][j][0][0] = 1<<(mat[i][j] - 'A');

 /// en la misma fila
 for ( int lc = 1; (1<<lc) <= C; lc ++ )
  for ( int i = 1; i <= F; i ++ )
   for ( int j = 1; j+(1<<lc)-1 <= C; j ++ )
    RMQ[i][j][0][lc] = ( RMQ[i][j][0][lc-1] | RMQ[i][j+(1<<(lc-1))][0][lc-1] );


/// en la misma columna
for ( int lf = 1; (1<<lf) <= F; lf ++ )
 for ( int i = 1; i+(1<<lf)-1 <= F; i ++ )
  for ( int j = 1; j <= C; j ++ )
   RMQ[i][j][lf][0] = RMQ[i][j][lf-1][0] | RMQ[i+(1<<(lf-1))][j][lf-1][0];

 for ( int lf = 1; (1<<lf) <= F; lf ++ )
  for ( int lc = 1; (1<<lc) <= C; lc ++ )
   for ( int i = 1; i+(1<<lf)-1 <= F; i ++ )
    for ( int j = 1; j+(1<<lc)-1 <= C; j ++ )
    {
     int a = RMQ[i][j][lf-1][lc-1];
     int b = RMQ[i][j+(1<<(lc-1))][lf-1][lc-1];
     int c = RMQ[i+(1<<(lf-1))][j][lf-1][lc-1];
     int d = RMQ[i+(1<<(lf-1))][j+(1<<(lc-1))][lf-1][lc-1];
     RMQ[i][j][lf][lc] = (a | b | c | d);
    }

 query ( 3, 1, 4, 1 );

 int sol = 0, ini, fin, piv, x, c;
 for ( int i = 1; i <= F; i ++ )
  for ( int j = 1; j <= C; j ++ )
    for ( int i2 = i; i2 <= F; i2 ++ )
     {
      ini = j, fin = C;
      while ( ini != fin )
      {
       piv = (ini+fin)>>1;
       x = query ( i, j, i2, piv );
       if ( __builtin_popcount(x) >= K )
        fin = piv;
       else
        ini = piv+1;
      }

      x = query ( i, j, i2, ini );
      if ( __builtin_popcount(x) != K )
       continue;

     c = ini, fin = C;
     while ( ini != fin )
     {
      piv = (ini+fin+1)>>1;
      x = query ( i, j, i2, piv );
      if ( __builtin_popcount(x) > K )
        fin = piv-1;
      else
        ini = piv;
     }

      sol += (ini-c+1);
     }

 printf ("%d", sol );


 return 0;
}

