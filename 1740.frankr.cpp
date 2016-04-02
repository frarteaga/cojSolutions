//Prob: 1740 - Another Palindrome Problem II
//Idea: DP O(N^2), resolver antes 1624 - Counting Palindromes
//frankr@coj

#include <cstdio>
#include <cstring>

char S[2002];
bool IP[2002][2002];
int CP[2001];

int main()
{
	scanf("%s", &S[1]);

	int n = strlen(&S[1]);

	for (int i = 1 ; i <= n ; i++)
		IP[i][i] = true;

	for (int i = 1 ; i < n ; i++)
		IP[i][i + 1] = S[i] == S[i + 1];

	for (int j = 3 ; j <= n ; j++)
		for (int i = 1 ; i <= n - j + 1 ; i++) 
			IP[i][i + j - 1] = IP[i + 1][i + j - 2] && (S[i] == S[i + j - 1]);

	CP[n] = 1;
	for (int i = n - 1 ; i >= 1 ; i--){
		CP[i] = CP[i + 1];
		for (int j = i ; j <= n ; j++)
			CP[i] += IP[i][j];
	}

	long long sol = 0;
	for (int i = 1 ; i < n ; i++)
		for (int j = i ; j < n ; j++)
			if (IP[i][j])
				sol += CP[j + 1];

	printf("%lld\n", sol);

	return 0;
}