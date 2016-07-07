#include <bits/stdc++.h> 

using namespace std; 

typedef long long LL; 
typedef pair<int, int> pii;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); 
	int n;
	cin >> n;
	if (n % 2 == 0)
		cout << "First\n";
	else
	if (n == 1)
		cout << "Tie\n";
	else
		cout << "Second\n";
	return 0;
}
