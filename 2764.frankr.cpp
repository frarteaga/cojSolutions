//Prob: 2764 - KRUZNICE
//Idea: Stack
//frankr@coj

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 3000001;
typedef pair<LL, LL> pii;

int N;
pii A[MAXN];
stack<LL> s;
stack<LL> d;

bool cmp(const pii &a, const pii &b){
    if (a.first < b.first)
        return true;
    else
    if (a.first > b.first)
        return false;
    else{
        return a.second > b.second;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1 ; i <= N ; i++){
        LL x, r;
        cin >> x >> r;
        A[i].first = x - r;
        A[i].second = 2 * r;
    }

    A[N + 1].first = 2000000000000LL + 10;
    sort(A + 1, A + N + 1, cmp);

    A[0].first = -2000000000000LL - 10;;

    LL sol = 0;
    for (int i = 0 ; i <= N ; i++){
        sol++;
        if (!s.empty()){
            int dist = d.top();
            d.pop();
            d.push(dist + A[i].second);
        }
        s.push(i);
        d.push(0);
        while (!s.empty() && A[i + 1].first >= A[s.top()].first + A[s.top()].second){
            int x = s.top();
            s.pop();
            d.pop();
            if (!s.empty() && d.top() == A[s.top()].second){
                sol++;
                //int dist = d.top();
                //d.pop();
                //d.push(dist + A[x].second);
            }
        }
//        s.push(i);
//        sol++;
//        d.push(A[i].second);
    }

    cout << sol;

    return 0;
}

