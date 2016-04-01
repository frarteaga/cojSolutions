//lmm@coj

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string cad;
    cin >> cad;

    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;

        int sum = cad[a] + cad[b];
        a++, b--;
        bool flag = false;
        while(a <= b)
        {
            if(cad[a] + cad[b] != sum){
                flag = true;
                break;
            }
            a++;
            b--;
        }
        if(!flag)cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}

