#include<bits/stdc++.h>

using namespace std;

int main () {
	uint n, m; 
	cin >> n; uint a[n + 1]; for (uint i = 1; i <= n; i++) {cin >> a[i];}
	cin >> m; uint b[m + 1]; for (uint i = 1; i <= m; i++) {cin >> b[i];}

	pair<uint, uint> dp[n + 1]; //length of lis ending at a[i], index of b[k] corresponding to a[i]

	for (uint i = 1; i <= n; i++) {
		for (uint k = 1; k <= m; k++) {
			if (a[i] == b[k]) {dp[i] = {1, k};}
		}
	}

	#ifdef DEBUG
	printf ("DP: \n");
	for (uint i = 0; i <= n; i++) {
		printf ("%d\t", dp[i].first);
	}
	cout << endl;
		for (uint i = 0; i <= n; i++) {
		printf ("%d\t", dp[i].second);
	}
	cout << endl;
	#endif

	uint seq[n + 1];

	for (uint i = 1; i < n; i++) {
		for (uint j = 0; j < i; j++) {

			#ifdef DEBUG
			if (a[j] <= a[i]) {printf ("Considering chain [%d] -> [%d]\n", j, i);}
			#endif
			if (a[j] <= a[i] && dp[j].second != 0 && dp[i].first < dp[j].first + 1) {

				#ifdef DEBUG
				printf ("Potential chain extension found: len %d ... [%d] -> [%d]. Now matching with second sequence\n", dp[j].first, j, i);
				#endif

				for (uint k = dp[j].second + 1; k <= m; k++) {
					#ifdef DEBUG
					printf ("Matching [%d] (from second seq) with [%d]\n", k, i);
					#endif

					if (b[k] == a[i]) {
						#ifdef DEBUG
						printf ("Chain ending at [%d] -> [%d], match with [%d] found. Length: %d\n", j, i, k, dp[j].first + 1);
						#endif

						seq[i] = j;
						dp[i].first = dp[j].first + 1;
						dp[i].second = k;

						#ifdef DEBUG
						printf ("DP: \n");
						for (uint i = 0; i <= n; i++) {
							printf ("%d\t", dp[i].first);
						}
						cout << endl;
							for (uint i = 0; i <= n; i++) {
							printf ("%d\t", dp[i].second);
						}
						cout << endl;
						#endif
					}
				}
			}
		}
	}

	// reconstruct lis
	uint end_point = 0, list_len;
	for (uint i = 0; i <= n; i++) {
		if (dp[end_point].first < dp[i].first) {
			end_point = i;
			list_len = dp[end_point].first;
		}
	}
	printf ("%d\n", list_len);

	for (uint i = end_point; i != 0; i = seq[i]) {
		printf ("%d ", a[i]);
	}
}