#include<bits/stdc++.h>

using namespace std;

const int N = 1000, M = 1000, K = 20;
int n, m, k;
int arr[N + 1][M + 1];
long int dp_max[N + 1][M + 1][K + 1], dp_min[N + 1][M + 1][K + 1];

long int big (int i, int j, int turn) {
	if (dp_max[i][j][turn] != -INT_MAX) {return dp_max[i][j][turn];}
	long int ans = -INT_MAX;
	/*if (j == 0) { //single column, max = sum of that column
		ans = arr[i][j];
	} else*/ if (turn == 0 /*cannot turn further*/ || i == 0) { 
		//sum = sum of this column + sum of previous column with same height
		// turning means considering sum of previous column with one less height as well
		ans = arr[i][j] + big(i, j - 1, turn);
	} else {
		ans = arr[i][j] + max (big(i - 1, j - 1, turn - 1), big(i - 1, j, turn));
	}
	#ifdef DEBUG
	printf ("Maximum sum achievable at (%d, %d, %d) is %ld\n", i, j, turn, ans);
	#endif

	dp_max[i][j][turn] = ans;
	return ans;
}

long int small (int i, int j, int turn) {
	if (dp_min[i][j][turn] != -INT_MAX) {return dp_min[i][j][turn];}
	long int ans = -INT_MAX;
	/*if (j == 0) { //single column, max = sum of that column
		ans = arr[i][j];
	} else*/ if (turn == 0 /*cannot turn further*/ || i == 0) { 
		//sum = sum of this column + sum of previous column with same height
		// turning means considering sum of previous column with one less height as well
		ans = arr[i][j] + small(i, j - 1, turn);
	} else {
		ans = arr[i][j] + min (small(i - 1, j - 1, turn - 1), small(i - 1, j, turn));
	}
	#ifdef DEBUG
	printf ("Maximum sum achievable at (%d, %d, %d) is %ld\n", i, j, turn, ans);
	#endif

	dp_min[i][j][turn] = ans;
	return ans;
}

int main () {
	int t; cin >> t;
	while (t--) {
		cin >> n >> m >> k;

		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= m; j++) {
				for (int turn = 0; turn <= k; turn++) {
					dp_max[i][j][turn] = -INT_MAX;
					dp_min[i][j][turn] = -INT_MAX;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			arr[i][0] = 0;
			for (int turn = 0; turn <= k; turn++) {
				dp_max[i][0][turn] = 0;
				dp_min[i][0][turn] = 0;
			}
		}
		/*
		  j -->
		i 0 X X X
		| 0 X X X
		v 0 X X X
		*/
		
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= m; j++) {
				arr[i][j] += arr[i - 1][j];
			}
		}

		long int ans = -INT_MAX;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < i - k; j++) {
				ans = max(ans, big(n - 1, i, k) - small (n - 1, j, k));
				#ifdef DEBUG
				printf ("Big for (%d, %d, %d) = %ld, small for (%d, %d, %d) = %ld\n",
					n - 1, i, k, big(n - 1, i, k), n - 1, j, k, small (n - 1, j, k));
				#endif
			}
		}
		cout << ans << endl;
	}
}