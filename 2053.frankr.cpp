// 2053 - Ball of Reconciliation
// Brute Force
// frankr@coj

#include <bits/stdc++.h>

using namespace std;

int main()
{
    while (1){
        int N;
        cin >> N;
        if (N == -1)
            break;

        int sol = 0;
        for (int c = 0 ; c <= N ; c++){
            for (int b = c ; b * c <= N && b <= N ; b++)
                if (b + c != 0 && (N - b * c) % (b + c) == 0){
                    int a = (N - b * c) / (b + c);
                    if (a >= b){
                        sol++;
                        //cout << a << " " << b << " " << c << endl;
                    }
                }
        }

        cout << sol << '\n';
    }
    return 0;
}
