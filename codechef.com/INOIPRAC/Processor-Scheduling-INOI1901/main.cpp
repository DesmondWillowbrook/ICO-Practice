#include <bits/stdc++.h>

using namespace std;
const int N_MAX = 5005;
long long int C[N_MAX]; pair<long long int, long long int> P[N_MAX];
long long int dp[N_MAX][N_MAX];

int main () {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;		
		for (int i = 1; i <= n; i++) {cin >> C[i];}
		for (int j = 1; j <= m; j++) {cin >> P[j].second;}
		for (int j = 1; j <= m; j++) {cin >> P[j].first;}
		sort(P, P + m + 1);

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				dp[i][j] = LONG_MAX;
			}
		}
		dp[0][0] = 0;

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (j != 0) {
					//If P[j] is invalid, then dp[i][j] is still LONG_MAX
					if (dp[i][j - 1] <= P[j].first) {
						if (dp[i][j - 1] + P[j].second < P[j].first) {
							dp[i][j] = P[j].first;
						} else {
							dp[i][j] = dp[i][j - 1] + P[j].second;
						}
					}
				} if (i != 0) {
					if (dp[i - 1][j] != LONG_MAX) {
						dp[i][j] = min(dp[i][j], dp[i - 1][j] + C[i]);
					} else {
						dp[i][j] = dp[i - 1][j];
					}
				}
			}
		}

		if (dp[n][m] == LONG_MAX) {
			cout << "-1" << endl;
		} else {
			cout << dp[n][m] << endl;
		}
	}
}