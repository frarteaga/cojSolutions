//1005 - Rent your Airplane and make Money
//Sorting and searching + DP

#include <bits/stdc++.h>
#include <ext/algorithm>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define endl '\n'

int main()
{
#ifdef HOME
	assert(freopen("input.in", "r", stdin));
	// assert(freopen("output.out", "w", stdout));
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		struct order { int s, e, p; };

		vector<order> O(n);
		for (order &o : O)
		{
			cin >> o.s >> o.e >> o.p;
			o.e += o.s;
		}

		sort(O.begin(), O.end(), [](order a, order b) { return a.e < b.e; });

		for (int i = 1; i < n; ++i)
		{
			int lo = -1, hi = i - 1;

			while (lo < hi)
			{
				int mid = (lo + hi + 1) / 2;

				if (O[mid].e <= O[i].s)
					lo = mid;
				else hi = mid - 1;
			}

			if (lo >= 0)
				O[i].p += O[lo].p;

			O[i].p = max(O[i].p, O[i - 1].p);
		}

		cout << O.back().p << endl;
	}
	
	return 0;
}

