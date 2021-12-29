#include<bits/stdc++.h>

using namespace std;

const long long int MOD = 1e9 + 7;

int dp[(long int) 1e6 + 1];

int k1 (int n) {
	if (n < 3) {return 0;}
	return n % 3 == 0 ? 1 : 0;
}

int k2 (int n) {
	if (dp[n] != -1) {return dp[n];}

	if (n <= 1) {return 0;}
	if (n == 2 || n == 3) {return 1;}

	long int ans = ((k2(n - 2) % MOD) + (k2(n - 3) % MOD)) % MOD;
	dp[n] = ans;
	return ((k2(n - 2) % MOD) + (k2(n - 3) % MOD)) % MOD;
}

long int k3 (int n) {
	long int dp[3][n + 1];
	fill (dp[0], dp[0] + n + 1, 0);
	fill (dp[1], dp[1] + n + 1, 0);
	fill (dp[2], dp[2] + n + 1, 0);

	dp[0][0] = 1;
	dp[0][1] = 1; // 1x3 bar
	dp[0][2] = 1;
	dp[0][3] = 2;

	dp[1][0] = 0;
	dp[1][1] = 0;
	dp[1][2] = 0; // 2x2 square
	dp[1][3] = 2; // 2x2 square
	
	dp[2][0] = 0;
	dp[2][1] = 0;
	dp[2][2] = 0;
	dp[2][3] = 2; // square + bar
	for (int i = 3; i <= n; i++) {
		dp[0][i] = ((2 * dp[1][i - 2]) % MOD + (dp[0][i - 1]) % MOD + (dp[0][i - 3]) % MOD) % MOD;
		dp[1][i] = ((dp[2][i - 1]) % MOD + (dp[1][i - 3]) % MOD) % MOD;
		dp[2][i] = ((dp[0][i - 3]) % MOD + (dp[2][i - 3]) % MOD) % MOD;
	}

	return dp[0][n];
}

int main () {
	int t; cin >> t;
	while (t--) {
		int k, n; cin >> k >> n;
		assert(k <= 3);

		fill_n(dp, n + 1, -1);
		if (k == 1) {
			cout << k1(n) << endl;
		} else if (k == 2) {
			cout << k2(n) << endl;
		} else if (k == 3) {
			cout << k3(n) << endl;
		}
	}
}