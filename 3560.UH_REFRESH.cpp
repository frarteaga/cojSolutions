#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define PB push_back
#define SZ(c) ((int)(c).size())
#define PC __builtin_popcountll


typedef long long ll;
typedef pair<int, int> pii;

ll log_mul(ll a, ll b, ll mod) {
	ll s = 0;
	while (b) {
		if (b & 1)
			s = (s + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return s;
}
ll log_pow(ll b, ll e, ll mod) {
	ll r = 1;
	while (e) {
		if (e & 1)
			r = log_mul(r, b, mod);
		b = log_mul(b, b, mod);
		e >>= 1;
	}
	return r;
}

ll pr(ll n) {
	if (!(n&1)) return 2;
	while (true) {
		ll x = rand() % n, y = x;
		ll c = rand() % n;
		if (c == 0 || c == 2) c = 1;
		for (int i = 1, k = 2; ; i++) {
			x = log_mul(x, x, n);
			if (x >= c) x -= c; else x += n-c;
			if (x == n) x = 0;
			if (x == 0) x = n-1; else x--;
			ll d = __gcd(x>y?x-y:y-x,n);
			if (d == n) break;
			if (d != 1) return d;
			if (i == k) {
				y = x;
				k <<= 1;
			}
		}
	}
}

bool witness(ll a, ll s, ll d, ll n) {
	ll x = log_pow(a, d, n);
	if (x == 1 || x == n-1) return false;
	for (ll i = 0; i < s-1; i++) {
		x = log_mul(x, x, n);
		if (x == 1) return true;
		if (x == n-1) return false;
	}
	return true;
}

bool is_prime(ll n) {
	if (n < 2) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	ll d = n-1, s = 0;
	while (d % 2 == 0) ++s, d/=2;
	ll test[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29 , 31 , 37, 41, 43,0};
	for (int i = 0; test[i] && test[i] < n; i++)
		if (witness(test[i], s, d, n))
			return false;
	return true;
}

void factorize(ll x, vector<ll> & f) {
	if (x == 1) return;
	if (is_prime(x))
		f.push_back(x);
	else {
		ll d = pr(x);
		factorize(d, f);
		factorize(x/d, f);
	}
}

const int MAXN = 25;
const int MAXD = 200;


ll n, x;
vector<ll> f[MAXN];
vector<ll> v;
map<ll, int> m;
unordered_set<bitset<MAXD>> sol;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	//~ double l = 1;
	//~ int cnt = 0;
	//~ int sl = 0;
	//~ for (int i = 2; i < 1000; i++) {
		//~ if (is_prime(i)) {
			//~ l *= i;
			//~ cnt++;
		//~ }
		//~ if (l > 1e16) {
			//~ sl++;
			//~ l = i;
		//~ }
		//~ if (sl == 20)
			//~ break;
	//~ }
	//~ cerr << cnt << endl;
			
	cin >> n;
	n++;
	for (int i = 0; i < n; i++) {
		cin >> x;
		factorize(x, f[i]);
		for (auto d : f[i])
			v.push_back(d);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (int i = 0; i < SZ(v); i++) {
		m[v[i]] = i;
		//cout << i << " " << v[i] << endl;
	}
		
	
	for (int mask = 2; mask < (1 << n); mask++) {
		if ((mask & 1) == 0)
			continue;
			
		bitset<MAXD> s;
		int c = 0;
		for (int i = 0; i < n; i++)
			if (mask & (1 << i)) {
				for (auto d : f[i]) {
					s.set(m[d]);
					c++;
				}
			}
		if ((int)s.count() == c)
			sol.insert(s);
	}
	
	cout << SZ(sol) << endl;
}
