/*
Given a positive integer n, find the number of pairs (i, j) in the set {0, 1, 2, ... 2^n - 1}, such that j > i and j & i == i.

Example

For n = 2, the output should be
countPairs(n) = "5".

The valid pairs are: (0, 1), (0, 2), (0, 3), (1, 3) and (2, 3).

    [input] integer n

	    1 ≤ n ≤ 30.

    [output] string

	    String representation of the number of pairs.
*/

#include <bits/stdc++.h> 

using namespace std;

int main(){
	for (int n = 1 ; n <= 15 ; n++){
		int c = 0;
		for (int i = 0 ; i < (1 << n) ; i++)
			for (int j = i + 1 ; j < (1 << n) ; j++)
				if ((j & i) == i)
					c++;
		cout << n << ") " << c << endl;
	}

	return 0;
}

/*
k  2^(n - k) - 1 

n = 2

c(2, 0) * (2^2 - 1) + c(2, 1) * (2^1 - 1)

sum(c(n, k) * (2^(n - k) - 1)) para k=0..n-1
*/
