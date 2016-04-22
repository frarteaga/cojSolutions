#include<iostream>
#include <cstdio>
#include<algorithm>

using namespace std;

const int MAXN=40;

int a[MAXN], a1[MAXN];
int b[MAXN], b1[MAXN];
int p[2*MAXN];
int c[2*MAXN];

int main()
{
    freopen( "tablas.in", "r", stdin );
    freopen( "tablas.out", "w", stdout );

    int n, m, k, x;
    cin >> n;
    cin >> m;
    for(int i=1; i<=2*n; i++)
      p[i]=i;
    for(int i=1; i<=m; i++)
    {
      cin >> a[i];
      p[a[i]]=3*n;
    }
    cin >> k;
    for(int i=1; i<=k; i++)
    {
       cin >> b[i];
       p[b[i]]=3*n;
    }
    sort(p+1,p+2*n+1);
    int m1=n-m;
    int k1=n-k;
    for(int i=1; i<=m1; i++)
      c[i]=1;
    for(int i=m1+1; i<=m1+k1; i++)
      c[i]=2;
    int br=0;
    do
    {
        for(int i=1; i<=m; i++)
          a1[i]=a[i];
        for(int i=1; i<=k; i++)
          b1[i]=b[i];
        int posa=m;
        int posb=k;
        for(int i=1; i<=m1+k1; i++)
          if(c[i]==1) a1[++posa]=p[i];
          else b1[++posb]=p[i];
        sort(a1+1,a1+n+1);
        sort(b1+1,b1+n+1);
        bool ok=true;
        for(int i=1; i<=n && ok; i++)
          if(a1[i]>b1[i])
             ok=false;
        if(ok)
        {
            br++;
        }

    }while(next_permutation(c+1,c+m1+k1+1));

    cout << br << '\n';
    return 0;
}

