#include<bits/stdc++.h>

using namespace std;

int main () {
	long int n, m; cin >> n >> m;
	bool safe[n][n]; long int max_berr[n][n];
	long int sol[n][n]; //we can probably trim this down to sol[2][n]

	for (long int i = 0; i < n; i++) {
		for (long int j = 0; j < n; j++) {
			cin >> max_berr[i][j];
			sol[i][j] = -INT_MAX;
		}
	}

	for (long int c = 0; c < m; c++) {
		long int x, y, k; cin >> x >> y >> k;
		x--; y--;

		for (long int i = max ((long int) 0, x - k); i <= min (n - 1, x + k); i++) {
			for (long int j = max ((long int) 0, y - k); j <= min (n - 1, y + k); j++) {
				if (abs(x - i) + abs(y - j) <= k) {
					safe[i][j] = true;
				}
			}
    	}
	}

	sol[0][0] = max_berr[0][0];
	for (long int i = 0; i < n; i++) {
		for (long int j = 0; j < n; j++) {
			if (!safe[i][j]) continue;
			if (i == 0 && j == 0) continue;

			long int ans = -INT_MAX;
			if (i > 0) {
				if (sol[i - 1][j] != -INT_MAX) ans = max (ans, sol[i - 1][j] + max_berr[i][j]);
			}
			if (j > 0) {
				if (sol[i][j - 1] != -INT_MAX) ans = max (ans, sol[i][j - 1] + max_berr[i][j]);
			}
			#ifdef DEBUG
			printf ("Max number of berries for (%ld, %ld) is %ld\n", i, j, ans);
			#endif
			sol[i][j] = ans;
		}
	}

	if (sol[n - 1][n - 1] != -INT_MAX) {
		printf ("YES\n%ld\n", sol[n - 1][n - 1]);
	} else {
		printf ("NO\n");
	}
}