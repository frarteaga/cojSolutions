//3686 - Max of the K
//sliding window technique (multiset implementation)
//frankr@coj

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10000001;

int N, K;
int A[MAXN];
multiset<int> s; 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;
    assert(t > 0);
    assert(t <= 1000);

    while (t--){
        cin >> N >> K;
        assert(N >= 1);
        assert(N <= 10000000);
        assert(K <= N);
        assert(K > 0);
        //FIXME: asserts..

        for (int i = 1 ; i <= N ; i++)
            cin >> A[i];

        s.clear();
        vector<int> sol;
        for (int i = 1 ; i <= N ; i++){
            s.insert(A[i]);
            if (s.size() == K){
                int m = *(--s.end());
                //cout << m << " ";
                sol.push_back(m);
                s.erase(s.find(A[i - K + 1]));
            }
        }

        cout << sol[0];
        for (int i = 1 ; i < sol.size() ; i++){
            cout << " " << sol[i];
        }
        cout << '\n';
    }

    return 0;
}

