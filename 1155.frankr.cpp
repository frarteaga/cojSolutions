/*
Prob: 1155 - Z-funkcija
Idea: Recurrencias Lineales .. Matrix Exponentation
Ref: Charla de Artimetica de Fidel Schsposnik (VI CaribCamp)
frankr@coj
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector< vector<int> > vv;

const int MOD = 10000;

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

int N;
matrix R(3);
vector<int> F(3);

int main()
{
    //freopen("d.in", "r", stdin);
    cin >> F[2] >> F[1] >> F[0];
    cin >> R.m[0][2] >> R.m[0][1] >> R.m[0][0];
    cin >> N;
    R.m[1][0] = 1;
    R.m[2][1] = 1;

    if (N <= 3){
        cout << F[3 - N] % MOD << '\n';
    }
    else{
        matrix RE = R.Pow(N - 3);
        vector<int> FN = RE.mult(F);
        int sol = FN[0];
        cout << sol << '\n';
    }

    return 0;
}

