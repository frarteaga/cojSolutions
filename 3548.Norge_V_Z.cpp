//3548 - Nerdson And The Magic Machine
//Divide & Conquer O(240^2 Log N)

#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;


const int N = 1e6+100;
const int mod = 1e9 + 7;

int n , k , l;
int pos[N];
int sz;
vector<int > divs;
vector<int> rgt;

void add(int &a, int x){
	a += x;
	if(a >= mod)
		a -= mod;
}

int mul(int a , int b){
	return (long long)a * b % mod;
}

int lcm(int a , int b){
	return (long long)a / __gcd(a , b) * b;
}
vector<int> solve(int n){
	if(n == 1){
		return rgt;
	}
	
	if(n & 1){
		vector<int> lft = solve(n - 1);
		vector<int> res(sz, 0);
		
		for( int i = 0; i < sz; i ++ ){
			for( int j = 0; j < sz; j++ ){
				int a = divs[i]	;
				int b = divs[j]	;
				int l = __gcd(a*1LL*b, k*1LL);
				int p = pos[l];
				add(res[p], mul(lft[i], rgt[j]));
			}
		}
		return res;
	}
	else{
		vector<int> lft = solve(n / 2);		
		vector<int> res(sz, 0);	
		
		for( int i = 0; i < sz; i ++ ){
			for( int j = 0; j < sz; j++ ){
				int a = divs[i]	;
				int b = divs[j]	;
				int l = __gcd(a*1LL*b, k*1LL);					
				int p = pos[l];				
				add(res[p], mul(lft[i], lft[j]));
			}
		}
		
		return res;
	}	
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> k >> l; 
	
	for( int i = 1; i <= k; i++ ){
		if(k % i == 0){
			pos[i] = divs.size();
			divs.push_back(i);			
		}
	}

	sz = divs.size();

	rgt = vector<int>(sz, 0);
	for( int i = 1; i <= l; i++ ){
		int gcd = __gcd(i , k);
		rgt[pos[gcd]]++;
	}	

	cout << solve(n)[pos[k]] << endl;
}

