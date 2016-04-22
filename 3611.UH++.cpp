//3611 - The Rewards
//Met in the middle

#include <bits/stdc++.h>
#include <ext/algorithm>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define endl '\n'

typedef long long ll;

const ll oo = 0x3f3f3f3f3f3f3f3f;

struct point
{
	ll x, y, v;
	bool color;

	bool operator <(const point &p) const
	{
		if (y != p.y)
			return y < p.y;
		if (x != p.x)
			return x < p.x;
		return color < p.color;
	}
};



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> p(n);

	for (int i = 0; i < n; ++i)
		cin >> p[i];

	int l = n / 2;
	int r = n - l;

	int l3 = power(3, l);
	vector<point> total;

	for (int i = 0; i < l3; ++i)
	{
		vector<ll> vv(3);
		int v = i;

		for (int j = 0; j < l; ++j)
		{
			vv[v % 3] += p[j];
			v /= 3;
		}

		total.push_back({ vv[0] - vv[1], vv[1] - vv[2], vv[2] - vv[0], false });
	}

	int r3 = power(3, r);

	for (int i = 0; i < r3; ++i)
	{
		vector<ll> vv(3);
		int v = i;

		for (int j = 0; j < r; ++j)
		{
			vv[v % 3] += p[j + l];
			v /= 3;
		}

		total.push_back({ vv[1] - vv[0], vv[2] - vv[1], vv[2] - vv[0], true });
	}

	map<ll, ll> mp;

	sort(total.begin(), total.end());

	ll ans = oo;

	for (auto &p : total)
	{
		if (p.color)
		{
			auto it = mp.upper_bound(p.x);
			if (it == mp.begin())
				continue;
			--it;
			ans = min(ans, p.v + it->second);
		}
		else
		{
			auto it = mp.upper_bound(p.x);
			if (it != mp.begin() && (--it)->second <= p.v)
				continue;

			mp[p.x] = p.v;

			while (true)
			{
				auto it = mp.upper_bound(p.x);
				if (it == mp.end() || it->second <= p.v)
					break;
				mp.erase(it);
			}
		}
	}

	cout << ans << endl;

	return 0;
}
