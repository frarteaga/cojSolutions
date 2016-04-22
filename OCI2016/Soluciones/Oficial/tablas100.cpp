#include<iostream>
#include <cstdio>

using namespace std;

const int MAXN=40;

long long r[2*MAXN][MAXN];

int main()
{

    freopen( "tablas.in", "r", stdin );
    freopen( "tablas.out", "w", stdout );

    char s[2*MAXN];
    int n, m, k, x;
    cin >> n;
    for(int i=0; i<=2*n; i++)
      s[i]='?';
    cin >> m;
    for(int i=1; i<=m; i++)
    {
        cin >> x;
        s[x] = '(';
    }
    cin >> k;
    for(int i=1; i<=k; i++)
    {
        cin >> x;
        s[x] = ')';
    }
    r[0][0]=1;
    for(int i=1; i<=2*n; i++)
    {
        if(s[i]==')' || s[i]=='?') r[i][0]=r[i-1][1];
        for(int j=1; j<=n; j++)
        {
            if(s[i]=='(' || s[i]=='?') r[i][j]+=r[i-1][j-1];
            if(s[i]==')' || s[i]=='?') r[i][j]+=r[i-1][j+1];
        }
    }
    cout << r[2*n][0] << '\n';
    return 0;
}
