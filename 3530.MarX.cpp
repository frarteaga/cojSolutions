#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 3010;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> f;
	for (int i = 1; i * i <= n; ++i){
		if (n % i == 0){
			f.push_back(i);
			if (i * i != n) f.push_back(n / i);
		}
	}
	sort(f.begin(), f.end());
	int ans = 0;
	for (int i = 0; i < (int)f.size(); ++i){
		for (int j = 0; j <= i; ++j)
			if (f[i] % f[j] == 0) ++ans;
	}

	cout << ans << endl;

	return 0;
}

