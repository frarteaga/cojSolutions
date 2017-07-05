// 3899 - C4 - Alex Origami Squares
// Binary Search
// frankr@coj

#include <bits/stdc++.h>

using namespace std;

const double EPS = 0.0000001;

double h, w, m, mi;

bool ok(double L){
    if (L + L + L <= m + EPS && L <= mi + EPS)
        return true;
    if (L + L <= mi + EPS)
        return true;
    return false;
}

int main()
{
    //freopen("d.in", "r", stdin);
    int hh, ww;
    cin >> hh >> ww;
    h = hh; w = ww;
    m = max(h, w);
    mi = min(h, w);

    double ini = 0.1, L, fin = 10000;

    while (fin - ini > EPS){
        L = (ini + fin) / 2.0;
        if (ok(L)){
            ini = L;
        }
        else{
            fin = L;
        }
    }

    cout.precision(8);
    cout << fixed;
    cout << (fin + ini) / 2.0;

    return 0;
}
