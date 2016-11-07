/*
Prob: 1422 - Range Multiplication
Idea: SQRT Descomposition
frankr@coj
*/

#include <iostream>
#include <cassert>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long LL;

struct Data{
    LL sum;
    LL k;
};

const LL MOD = 1000000009;
const int MAXN = 1001001;

int N;
LL A[MAXN];
int Size;
Data Slots[2001];

inline int slot(int i){
    return i / Size;
}

inline int lo(int sl){
    return sl * Size;
}

inline int hi(int sl){
    return Size * (sl + 1) - 1;
}

void openslot(int sl){
    if (Slots[sl].k == 1)
        return;
    int _lo = lo(sl);
    int _hi = hi(sl);
    LL newSum = 0;
    for (int i = _lo ; i <= _hi ; i++){
        A[i] = A[i] * Slots[sl].k % MOD;
        newSum = (newSum + A[i]) % MOD;
    }
    Slots[sl].k = 1;
    Slots[sl].sum = newSum;
}

LL suma(int x, int y){
    LL res = 0;
    for (int i = x ; i <= y ; i++)
        res = (res + A[i]) % MOD;
    return res;
}

LL query(int x, int y){
    int slx = slot(x);
    int sly = slot(y);

    openslot(slx);
    openslot(sly);

    if (slx == sly)
        return suma(x, y);

    LL res = (suma(x, hi(slx)) + suma(lo(sly), y)) % MOD;

    slx++;
    while (slx < sly){
        res = (res + Slots[slx].k * Slots[slx].sum) % MOD;
        slx++;
    }

    return res;
}

void ups(int x, int y, int sl, LL k){
    /*
    assert(slot(x) == sl);
    assert(slot(y) == sl);
    assert(Slots[sl].k == 1);
*/
    for (int i = x ; i <= y ; i++){
        Slots[sl].sum -= A[i];
        A[i] = A[i] * k % MOD;
        Slots[sl].sum = (Slots[sl].sum + A[i]) % MOD;
    }
    if (Slots[sl].sum < 0)
        Slots[sl].sum += MOD;
}

void update(int x, int y, LL k){
    int slx = slot(x);
    int sly = slot(y);

    openslot(slx);
    openslot(sly);

    if (slx == sly){
        ups(x, y, slx, k);
        return;
    }

    ups(x, hi(slx), slx, k);
    ups(lo(sly), y, sly, k);

    slx++;
    while (slx < sly){
        Slots[slx].k = Slots[slx].k * k % MOD;
        slx++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("d.i", "r", stdin);
    //freopen("s.o", "w", stdout);

    int M;
    while (cin >> N >> M){

        ///construct
        for (int i = 0 ; i < N ; i++)
            A[i] = 1;
        Size = ceil(sqrt(N));
        for (int i = 0 ; i < Size ; i++){
            Slots[i].k = 1LL;
            Slots[i].sum = (LL)Size;
        }
        /*
        int slN = slot(N - 1);
        int NN = N;
        while (Slots[slN].k != 1LL){
            Slots[slN].k = 1LL;
            Slots[slN].sum = (LL)(NN - lo(slN));
            NN = lo(slN);
            slN--;
        }
        */
        ///

        for ( ; M ; M--){
            int op, x, y;
            cin >> op >> x >> y;
            assert(x <= y);
            x--; y--;
            if (op == 1)
                cout << query(x, y) << '\n';
            else{
                LL k;
                cin >> k;
                update(x, y, k);
            }
        }
    }

    return 0;
}


