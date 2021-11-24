#include<bits/stdc++.h>

using namespace std;

uint prev;
uint a[101], b[101];
const uint M = 1e8 + 7;

uint dp[101][101][201][2];

uint f (int k, int n, int m, int last) {
	if (n < 0 || m < 0 || k < 1 || n + m < k) return 0;
	if (dp[n][m][k][last] != -1) return dp[n][m][k][last];

	uint ans = 0;

	if (n > 0 && b > 0) {
		if (a[n] == b[m]) {
			ans += f (k, n - 1, m, 1); ans %= M;
			ans += f (k, n, m - 1, 0); ans %= M;
		} else if (a[n] != b[m]) {
			ans += f (k - 1, n - 1, m, 1); ans %= M;
			ans += f (k - 1, n, m - 1, 0); ans %= M;
		}
	}

	if (n - 1 > 0) {
		if (a[n] == a[n-1]) {
			ans += f (k, n - 1, m, 0); ans %= M;
		} else {
			ans += f (k - 1, n - 1, m, 0); ans %= M;
		}
	}
	if (m - 1 > 0) {
		if (b[m] == b[m-1]) {
			ans += f (k, n, m - 1, 1); ans %= M;
		} else {
			ans += f (k - 1, n, m - 1, 1); ans %= M;
		}
	}

	#ifdef DEBUG
	printf ("Checked f (k = %d, n = %d, m = %d, %d) = %d\n", k, n, m, last, ans);
	#endif

	dp[n][m][k][last] = ans;
	return ans;
}

int main () {
	uint t;	cin >> t;
	while (t--) {
		uint n, m, k; cin >> n >> m >> k;
		for (uint i = 1; i <= n; i++) cin >> a[i];
		for (uint i = 1; i <= m; i++) cin >> b[i];

		for (uint i = 0; i <= n; i++)
			for (uint j = 0; j <= m; j++)
				for (uint k = 0; k <= n + m; k++)
						dp[i][j][k][0] = dp[i][j][k][1] = -1;
		
		dp[1][0][1][0] = dp[0][1][1][1] = 1;

		cout << "Answer: " << (f (k, n, m, 0) + f (k, n, m, 1)) % ((uint) pow(10, 8) + 7) << endl;
	}
}