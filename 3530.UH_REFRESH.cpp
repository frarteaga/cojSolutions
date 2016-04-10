#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'

ll n, sol;
map<ll, ll> m;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (ll i = 2; i*i <= n; i++) {
        while (n % i == 0) {
            m[i]++;
            n /= i;
        }
    }
    if (n > 1)
        m[n]++;

    sol = 1;
    for (auto it = m.begin(); it != m.end(); it++) {
        //cout << it->first << " " << it->second << endl;
        ll e = it->second;
        sol *= (e+2) * (e+1) / 2;
    }
    cout << sol << endl;
}


