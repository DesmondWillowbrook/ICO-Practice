#include<bits/stdc++.h>

using namespace std;
 
// also see:
// using three variables for fibonacci instead of an entire array
// log N sol with matrix exponentiation

void fib(int n) {
	int dp[n + 1];
	dp[0] = 0; cout << dp[0] << endl;
	dp[1] = 1; cout << dp[1] << endl;
	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 998244353;
		cout << dp[i] << endl;
	}
}
 
int main ()
{
	int n; cin >> n;
	fib(n);
}