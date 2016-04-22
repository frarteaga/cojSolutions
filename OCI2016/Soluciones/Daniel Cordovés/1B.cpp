#include <bits/stdc++.h>
using namespace std;

const int
	MAX = 3e4 + 5,
	BASE = 71,
	INV1 = 98591550,
	INV2 = 957746499,
	MOD1 = 1e9 + 7,
	MOD2 = 1e9 + 21;
int n, l, k, pw1[205], pw2[205], p1[MAX], p2[MAX], s1[MAX], s2[MAX];
int f[70], t[MAX];
char a[MAX][205];

struct data {
	int h1, h2, c;

	data(int x = 0, int y = 0, int z = 0) {
		h1 = x, h2 = y, c = z;
	}

	bool operator < (const data &d) const {
		if(h1 != d.h1)
			return h1 < d.h1;

		return h2 < d.h2;
	}

	bool operator == (const data &d) const {
		return h1 == d.h1 && h2 == d.h2;
	}
} h[MAX];

int get(char c) {
	if(c >= '0' && c <= '9')
		return c - '0' + 1;

	if(c >= 'a' && c <= 'z')
		return c - 'a' + 11;

	if(c >= 'A' && c <= 'Z')
		return c - 'A' + 37;

	if(c == '@')
		return 63;

	return 64;
}

int main() {

    freopen("cuentas.in", "r", stdin);
    freopen("cuentas.out", "w", stdout);

	scanf("%d%d%d", &n, &l, &k);

	pw1[0] = pw2[0] = 1;
	for(int i = 1; i < l; i++) {
		pw1[i] = (pw1[i - 1] * 1LL * BASE) % MOD1;
		pw2[i] = (pw2[i - 1] * 1LL * BASE) % MOD2;
	}

	for(int i = 1; i <= n; i++) {
		scanf("%s", a[i]);
		t[i] = t[i - 1] + i - 1;

		for(int j = 0; j < l; j++) {
			int c = get(a[i][j]);
			int v1 = (pw1[j] * 1LL * c) % MOD1;
			int v2 = (pw2[j] * 1LL * c) % MOD2;
			s1[i] = (s1[i] + v1) % MOD1;
			s2[i] = (s2[i] + v2) % MOD2;
		}
	}

	int ans = 0;
	for(int j = 0; j < l; j++) {
		for(int i = 1; i <= n; i++) {
			int c = get(a[i][j]);
			int v1 = (pw1[j] * 1LL * c) % MOD1;
			int v2 = (pw2[j] * 1LL * c) % MOD2;

			s1[i] = (s1[i] - v1 + MOD1) % MOD1;
			s2[i] = (s2[i] - v2 + MOD2) % MOD2;

			int x = (s1[i] * 1LL * INV1) % MOD1;
			int y = (s2[i] * 1LL * INV2) % MOD2;

			h[i] = data((p1[i] + x) % MOD1, (p2[i] + y) % MOD2, c);

			p1[i] = (p1[i] + v1) % MOD1;
			p2[i] = (p2[i] + v2) % MOD2;
		}

		sort(h + 1, h + n + 1);

		memset(f, 0, sizeof(f));

		int s = 0, v = 0;
		for(int i = 1; i <= n; i++) {
			if(i < n && h[i] == h[i + 1]) {
				f[h[i].c]++;
				v += f[h[i].c] - 1;
				s++;
				continue;
			}

			f[h[i].c]++;
			v += f[h[i].c] - 1;
			s++;
			s = t[s];
			ans += s - v;
			s = v = 0;

			memset(f, 0, sizeof(f));
		}
	}

	printf("%d\n", ans);
	return 0;
}
