/*
Prob: 2066 - Trisum
Idea: Recurrencias Lineales .. Matrix Exponentation
Ref: Charla de Artimetica de Fidel Schsposnik (VI CaribCamp)
Ver problema: 1155 - Z-funkcija
frankr@coj
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector< vector<int> > vv;

const int MOD = 10007;

struct matrix{
    vv m;

    matrix(int N){
        m.resize(N);
        for (int i = 0 ; i < N ; i++)
            m[i].resize(N, 0);
    }

    matrix(const matrix& T){
        int N = T.m.size();
        m.resize(N);
        for (int i = 0 ; i < N ; i++){
            m[i].resize(N, 0);
            for (int j = 0 ; j < N ; j++)
                m[i][j] = T.m[i][j];
        }
    }

    matrix mult(const matrix& T)const{
        int N = m.size();
        matrix C(N);

        for (int i = 0 ; i < N ; i++)
            for (int j = 0 ; j < N ; j++)
                for (int k = 0 ; k < N ; k++)
                    C.m[i][j] = (C.m[i][j] + m[i][k] * T.m[k][j]) % MOD;

        return C;
    }

    vector<int> mult(const vector<int>& T)const{
        int N = m.size();
        vector<int> r(N, 0);
        for (int i = 0 ; i < N ; i++)
            for (int j = 0 ; j < N ; j++)
                r[i] = (r[i] + m[i][j] * T[j]) % MOD;
        return r;
    }

    matrix Pow(long long E) const{
        if (E == 1LL){
            //matrix r(this);
            //return r;
            return *this;
        }
        if (E & 1LL){
            matrix r(mult(Pow(E - 1)));
            return r;
        }
        matrix r(Pow(E >> 1LL));
        return r.mult(r);
    }
};

matrix R(2);
vector<int> ak(2);
vector<int> bk(2);
vector<int> ck(2);
int a0, b0, c0;
long long n;

int main()
{
    //freopen("d.in", "r", stdin);

    cin >> n >> a0 >> b0 >> c0;

    R.m[0][0] = 3;
    R.m[0][1] = 18;
    R.m[1][0] = 1;

    ak[1] = a0;
    bk[1] = b0;
    ck[1] = c0;
    ak[0] = 3 * (b0 + c0);
    bk[0] = 3 * (a0 + c0);
    ck[0] = 3 * (a0 + b0);

    if (n < 2)
        cout << ak[!n] << ' ' << bk[!n] << ' ' << ck[!n] << '\n';
    else{
        matrix RE = R.Pow(n - 1);
        vector<int> A = RE.mult(ak);
        vector<int> B = RE.mult(bk);
        vector<int> C = RE.mult(ck);
        cout << A[0] << ' ' << B[0] << ' ' << C[0] << '\n';
    }

//    //comprobando por FB:
//    swap(ak[0], ak[1]);
//    swap(bk[0], bk[1]);
//    swap(ck[0], ck[1]);
//
//    for (int i = 2 ; i <= n ; i++){
//        int a = ak.back();
//        int b = bk.back();
//        int c = ck.back();
//        ak.push_back(3 * (b + c) % MOD);
//        bk.push_back(3 * (a + c) % MOD);
//        ck.push_back(3 * (b + a) % MOD);
//    }
//
//    cout << ak[n] << ' ' << bk[n] << ' ' << ck[n] << '\n';

    return 0;
}

