//lmm@coj

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3001;

bool calc[MAXN][MAXN];
bool cw[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string cad;
    cin >> cad;

    int t;
    cin >> t;
    while(t--)
    {
        int a, b, aa, bb;
        cin >> a >> b;
		aa = a;
		bb = b;

		if (!calc[a][b]){
			int sum = cad[a] + cad[b];
			a++, b--;
			bool flag = true;
			while(a <= b)
			{
				if(cad[a] + cad[b] != sum){
					flag = false;
					break;
				}
				if (calc[a][b]){
					flag = cw[a][b];
					break;
				}
				a++;
				b--;
			}
			cw[aa][bb] = flag;
			calc[aa][bb] = true;
		}
        if(cw[aa][bb])cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}

