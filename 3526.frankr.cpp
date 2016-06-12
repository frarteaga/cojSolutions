//3526 - Unordered List
//Idea in book Looking for a Challenge?, pag 100-101
//frankr@coj

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 2;

int N;
int A[MAXN];
int SOL[MAXN];
int ODD[MAXN];

int main()
{
    //freopen("d.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1 ; i <= N ; i++)
        cin >> A[i];

	int cz = 0;
	while (cz < N){
		memset(ODD, 0, sizeof ODD);

		cz = 0;
		for (int i = N ; i > 0 ; i--){
			if (A[i] & 1)
				ODD[A[i]]++;
			else{
				SOL[i] += ODD[A[i] + 1];
				if (A[i] == 0)
					cz++;
			}
			A[i] >>= 1;
		}
	}	

    cout << SOL[1];
    for (int i = 2 ; i <= N ; i++)
        cout << ' ' << SOL[i];

    return 0;
}


