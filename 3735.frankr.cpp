//3735 - My Longest Palindrome
//Constructive algorithm & Counting Sort
//frankr@coj

#include <bits/stdc++.h>

using namespace std;

int T;
int N;
string S, R;
int F[27];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--){
        cin >> N;
        cin >> S;
        fill(F, F + 27, 0);
        for (int i = 0 ; i < (int)S.size() ; i++)
            F[S[i] - 'A']++;
        R = "";
        char m = ' ';
        for (int i = 0 ; i < 26 ; i++){
            if ((F[i] & 1) && m == ' ')
                m = i + 'A';
            for (int j = 2 ; j <= F[i] ; j += 2)
                R += (char)(i + 'A');
        }
        cout << R;
        reverse(R.begin(), R.end());
        if (m != ' ')
            cout << m;
        cout << R << '\n';
    }
    return 0;
}

