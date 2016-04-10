//3530 - Product Of 3 Factors
//Idea: Guardar todos los divisores y luego fijar dos
//Investigar sobre los numeros altamente compuestos
//que son los que llevan el algoritmo al peor caso.
//frankr@coj

#include <bits/stdc++.h>

using namespace std;

int p3(int n){
    long long N = n;

    vector<long long> d; //lista de divisores
    int i;
    for (i = 1 ; i * i <= N ; i++)
        if (N%i==0){
            d.push_back(i);
            d.push_back(N / i);
        }
    if (N > 1)
        d.push_back(N);
    sort(d.begin(), d.end());
    set<long long> ss(d.begin(), d.end());
    d = vector<long long>(ss.begin(), ss.end());
    
    //cout << "S " << d.size() << endl;

    int sol = 0;
    for (int i = 0 ; i < d.size() ; i++)
        for (int j = 0 ; j < d.size() ; j++)
            if (N % (d[i] * d[j]) == 0)
                sol++;

    return sol;
}

typedef long long ll;

int fb(ll N){
    int sol = 0;
    for (ll i = 1 ; i <= N ; i++)
        if (N % i == 0)
            for (ll j = 1 ; j <= N ; j++)
                if (N % j == 0 && i * j <= N)
                   for (ll z = 1 ; z <= N ; z++)
                        if (N % i == 0 && j * z == N / i)
                            sol++;
    return sol;
}

int main()
{
    int N;
    cin >> N;
    int sol = p3(N);
    cout << sol;
    return 0;
}

/*
    std::vector<int> d;
    int i;
    for (i = 1 ; i * i < N ; i++)
        if (N%i==0){
            d.push_back(i);
            d.push_back(N / i);
        }
    if (i * i == N)
        d.push_back(i);

    std::set<std::pair<int, std::pair<int, int> > > sol;
    for (i = 0 ; i < d.size() ; i++)
        for (int j = 0 ; j < d.size() && d[i] <= N / d[j] ; j++)
            if (N % (d[i] * d[j]) == 0){
                int s[3] = {d[i], d[j], N / d[i] / d[j]};
                std::sort(s, s + 3);
                do{
                    sol.insert(std::make_pair(s[0], std::make_pair(s[1], s[2])));
//                    cout << s[0] << " " << s[1] << " " << s[2] << endl;
                }while(std::next_permutation(s, s + 3));
            }

    return sol.size();
*/

