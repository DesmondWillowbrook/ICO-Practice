#include<bits/stdc++.h>

using namespace std;

int main () {
	uint n; cin >> n; uint arr[n];
	for (uint i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// n^2 algorithm
	uint dp[n];
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

	fill_n(dp, n, 1);
	
	uint smal[n + 1]; //smallest element at the ending of subsequence of nth length
	fill_n(smal, n + 1, INT_MAX);
	smal[1] = arr[0];

	for (uint i = 0; i < n; i++) {
		auto it = upper_bound(smal + 1, smal + i + 1, arr[i]); it--; //it may be INVALID now, after subtracting

		if (smal < it /*check if it is still in bounds*/) {
			dp[i] = (it - smal) + 1;
		}
		smal[dp[i]] = min(smal[dp[i]], arr[i]);
	}

	#ifdef DEBUG
	for (uint i = 0; i < n; i++) {printf ("%d ", arr[i]);} cout << endl;
	for (uint i = 0; i < n; i++) {printf ("%d ", dp[i]);} cout << endl;
	for (uint i = 1; i <= n && smal[i] != INT_MAX; i++) {printf ("%d ", smal[i]);} cout << endl;
	cout << endl;
	#endif

}