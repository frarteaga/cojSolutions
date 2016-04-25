/*
2893 - Arithmetically Easy II
Combinatoria, Teorema de Lucas, Inverso Modular
*/

#include <cstdio>
#include <set>

using namespace std;

typedef long long int64;
const int MOD = 123457;
int t;
int64 f[2 * MOD];

int64 exp(int64 a, int64 b) {
    if(b == 0)
        return 1LL;

    if(b & 1)
        return (a * exp(a, b - 1)) % MOD;

    int64 sq = exp(a, b / 2);
    return (sq * sq) % MOD;
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    f[0] = 1;
    for(int64 i = 1; i < 2 * MOD; i++)
        f[i] = (f[i - 1] * i) % MOD;

    scanf("%d", &t);
    while(t--) {
        int64 k;
        scanf("%lld", &k);

        int64 sol = 0;
        set<int64> se;
        //se.clear();
        for(int i = 1; i <= 5; i++) {
            int64 n; scanf("%lld", &n);
            if (se.find(n) != se.end())
                continue;
            se.insert(n);
            int64 a = n + k - 1;
            int64 b = k - 1;
            int64 ans = 1;

            for(int64 x = a, y = b; x > 0; x /= MOD, y /= MOD) {
                int64 dx = x % MOD;
                int64 dy = y % MOD;

                if(dy > dx) {
                    ans = 0;
                    break;
                }

                int64 num = f[dx];
//                int64 den = (f[dy] * f[dx - dy]) % MOD;
                int64 den = exp(f[dy], MOD - 2);
                den = den * exp(f[dx - dy], MOD - 2);
                int64 cf = (num * den) % MOD;
                ans = (ans * cf) % MOD;
            }

            sol = (sol + ans) % MOD;
        }

        printf("%lld\n", sol);
    }

    return 0;
}

