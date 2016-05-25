//1786 - Flying of Witchs
//Binary search
//frankr@coj

#include <iostream>

using namespace std;

int N;
long long P, B[180002];

bool ok(int M){
    for (int i = 1 ; i <= N - M + 1 ; i++)
        if (B[i + M - 1] - B[i - 1] > P)
            return false;
    return true;
}

int main()
{
    int T;
    cin >> T;
    while (T--){
        cin >> P;
        cin >> N;
        bool nosol = false;
        for (int i = 1 ; i <= N ; i++){
            cin >> B[i];
            if (B[i] > P)
                nosol = true;
            B[i] += B[i - 1];
        }
        if (nosol)
            cout << "0\n";
        else{
            int ini = 1, fin = N;
            while (ini < fin){
                int mit = (ini + fin + 1) / 2;
                if (ok(mit))
                    ini = mit;
                else
                    fin = mit - 1;
            }
            cout << ini << '\n';
        }
    }
    return 0;
}


