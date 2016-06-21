//Superfactorial
//frankr@coj

#include <bits/stdc++.h> 

using namespace std; 

long long g(long long n){ 
    if (n <= 1)
        return n;
    return 2 * g((n + 1) / 2 - 1) + (n + 1) / 2;
}

long long f(long long n){ 
    if (((n + 1) & n) == 0)
        return g(n);
    long long p = 1;
    while (p - 1 <= n)
        p *= 2;
    p /= 2;
    return g(p - 1) + f(n - p) + n - p + 1;
}

long long sflowbit(long long n){
	long long t = n * (n + 1) / 2;
	t -= f(n);
	return t;
}

int main()
{
    assert(g(3) == 4); 

	long long n;
	cin >> n;
	cout << sflowbit(n);

    return 0;
}

