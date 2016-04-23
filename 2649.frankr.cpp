//2649 - Square Factory
//Progresión geométrica e Inverso Modular
//frankr@coj

#include<cstdio>
#include<algorithm>
#include<iostream>
#include<map>

using namespace std;

typedef long long LL;

const LL INVM = 666669;
const LL MOD = 1000003;

LL pot4(int e){
    if (e == 0)
        return 1;
    if (e % 2 == 0){
        LL r = pot4(e / 2);
        return (r * r) % MOD;
    }
    return (pot4(e - 1) * 4) % MOD;
}

int main()
{
    int T, N;
    cin >> T;
    while (T--){
        cin >> N;
        LL r = pot4(N + 1) - 1;
        r = (r * INVM) % MOD;
        cout << r << '\n';
    }

	return 0;
}
