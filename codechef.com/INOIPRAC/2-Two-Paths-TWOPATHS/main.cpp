#include<bits/stdc++.h>

using namespace std;

const int N = 1000, M = 1000, K = 20;
int n, m, k;
int arr[N + 1][M + 1];
long int dp_max[N + 1][M + 1][K + 1], dp_min[N + 1][M + 1][K + 1];

int main () {
	int t; cin >> t;
	while (t--) {
		cin >> n >> m >> k;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 1; j < m; j++) {
				arr[i][j] += arr[i][j - 1];
			}
		}

		// calc min arr
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int turn = 0; turn <= k; turn++) {
					// element at current position not included
					// because both of our "paths" are inclusive
					// => when subtracting, we want to cut out the 
					// portion which is min for that position,
					// EXCLUDING that position
					if (j > 0) {dp_min[i][j][turn] = arr[i][j - 1];}
					else {dp_min[i][j][turn] = 0;}

					//there are no rows before this one
					//thus min sum is sum of this row only
					if (i == 0) {
						continue;
					}
					//if we can't turn or we're at the first row
					//only option is to go back one row
					if (j == 0 || turn == 0) {
						dp_min[i][j][turn] += dp_min[i - 1][j][turn];
						continue;
					}
					//general case:
					//min = sum of this row NOT including current element (already added)
					// + either max of previous row with same column height
					// or max of previous row with height of column reduced by 1
					dp_min[i][j][turn] += 
						min(dp_min[i - 1][j][turn], dp_min[i - 1][j - 1][turn - 1]);
				}
			}
		}

		// calc max arr
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int turn = 0; turn <= k; turn++) {
					// element at current position included
					dp_max[i][j][turn] = arr[i][j];		
					//there are no rows before this one
					//thus max sum is sum of this row only
					if (i == 0) {
						continue;
					}
					//if we can't turn or we're at the first row
					//only option is to go back one row
					if (j == 0 || turn == 0) {
						dp_max[i][j][turn] += dp_max[i - 1][j][turn];
						continue;
					}
					//general case:
					//max = sum of this row including current element (already added)
					// + either max of previous row with same column height
					// or max of previous row with height of column reduced by 1
					dp_max[i][j][turn] += 
						max(dp_max[i - 1][j][turn], dp_max[i - 1][j - 1][turn - 1]);
				}
			}
		}

		long int ans = -INT_MAX;
		for (int j = 0; j < m; j++) {
			for (int i = j + k + 1; i < m; i++) {
				ans = max(ans, dp_max[n - 1][i][k] - dp_min[n - 1][j][k]);
				#ifdef DEBUG
				printf ("Big for (%d, %d, %d) = %ld, small for (%d, %d, %d) = %ld\n",
					n - 1, i, k, dp_max[n - 1][i][k], n - 1, j, k, dp_min[n - 1][j][k]);
				#endif
			}
		}
		cout << ans << endl;
	}
}