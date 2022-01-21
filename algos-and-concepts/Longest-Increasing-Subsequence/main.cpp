#include<bits/stdc++.h>

using namespace std;

int main () {
	uint n; cin >> n; uint arr[n];
	for (uint i = 0; i < n; i++) {
		cin >> arr[i];
	}
	uint dp[n]; // length of longest increasing subsequence which ends at index i
/*
	// n^2 algorithm
	fill_n(dp, n, 1);
	dp[0] = 1;

	for (uint i = 0; i < n; i++) {
		for (uint j = 0; j < i; j++) {
			if (arr[i] >= arr[j]) {
				dp[i] = max (dp[i], dp[j] + 1);
			}
		}
	}
	#ifdef DEBUG
	for (uint i = 0; i < n; i++) {printf ("%d ", arr[i]);} cout << endl; 
	for (uint i = 0; i < n; i++) {printf ("%d ", dp[i]);} cout << endl;
	cout << endl;
	#endif
*/
	fill_n(dp, n, 1);
	
	uint smal[n]; //smallest element at the ending of subsequence of ith length
	fill_n(smal, n, INT_MAX);
	smal[0] = arr[0];

	uint ans = 1;
	for (uint i = 0; i < n; i++) {
		auto it = lower_bound(smal, smal + i, arr[i]);

		// set dp as length of subsequence where number it ends in is smaller than current number + 1
		dp[i] = (it - smal) + 1;

		//set new smallest element at ending of subsequence of length dp[i]
		//(since dp[i] starts at 1, we subtract one for space-efficiency)
		smal[dp[i] - 1] = min(smal[dp[i] - 1], arr[i]);
		ans = max(dp[i], ans);
	}

	#ifdef DEBUG
	for (uint i = 0; i < n; i++) {printf ("%d ", arr[i]);} cout << endl;
	for (uint i = 0; i < n; i++) {printf ("%d ", dp[i]);} cout << endl;
	for (uint i = 0; i < n && smal[i] != INT_MAX; i++) {printf ("%d ", smal[i]);} cout << endl;
	cout << endl;
	#endif

	cout << ans << endl;
}