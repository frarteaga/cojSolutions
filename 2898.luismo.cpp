/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 2898 - GCD and Longest Subsequence III
    Online Judge: COJ
    Idea: Easy DP. Use a DP array, to store in the i-th position the longest
	continuous subsequence that ends at position i where each pair of values
	in it are coprime. Iterate the array DP and check backwards at most DP[i-1]
	positions with variable j, updating DP[i] if values at position i and j are
	coprimes, otherwise break.
*/
#include <iostream>
#include <cstdio>
// Containers
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
// Algorithm
#include <algorithm>
#include <cstring>
#include <cmath>
// Constants
#define MAXN 1000001
#define MOD 1000000007
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);
#define nlong(i) sf("%lld",&i);

using namespace std;

const int lim = 2003;

int N;
int arr[lim];
int dp[lim];


void solve()
{
	cin >> N;

	// reading integers
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	fill(dp, dp + N, 1);

	int answ = dp[0];

	for(int i = 1; i < N; i++)
	{
		int idx = i - 1;
		int cnt = dp[i - 1];

		while(cnt > 0 && __gcd(arr[i], arr[idx]) == 1)
		{
			dp[i]++;
			idx--; cnt--;
		}
		answ = max(answ, dp[i]);
	}
	cout << answ <<"\n";
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("e:\\lmo.in","r",stdin);
}

int main()
{
    // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}

