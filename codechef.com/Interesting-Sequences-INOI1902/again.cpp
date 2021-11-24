#include <bits/stdc++.h>

using namespace std;

int assert_lsc (int l, int cost, pair<int, int>* arr, uint n) {
	uint dp[n]; // ith element = max. length of subseq. ending at i
	fill(dp, dp+n, 1);

	for (uint i = 0; i < n; i++) {
		for (uint j = 0; j < i; j++) {
			if (abs (arr[i].second - arr[j].second) >= cost) {
				dp[i] = max (dp[i], dp[j] + 1);
				if (dp[i] >= l) {
					return true;
				}
			}
		}
	}
	return false;
}

int main () {
	uint t; cin >> t;
	while (t--) {
		uint n, l; cin >> n >> l;
		
		pair<int, int> arr[n];
		for (int i = 0; i < n; i++) {cin >> arr[i].first; arr[i].second = i;}

		sort(arr, arr+n);

		#ifdef DEBUG
		for (uint i = 0; i < n; i++) cout << arr[i].first << " ";
		cout << endl;
		#endif

		// handling identical elements.
		// as assert_lsc makes assumption that elements can't be reused
		// and in non-identical cases, they can't. Previous elem is always smaller
		// than new elem.

		int curr = 0;

		for (uint i = 0; i < n; i++) {
			for (uint j = i + 1; j < n && arr[i].first == arr[j].first; j++) {
				curr = max (curr, abs(arr[i].second - arr[j].second));
			}
		}

		for (int k = n/2; k >= 1; k /= 2) {
			while (k + curr < n && assert_lsc(l, k + curr, arr, n)) {
				curr += k;
				#ifdef DEBUG
				printf ("Checked %d: It is %s\n", curr, assert_lsc(l, curr, arr, n) ? "true" : "false");
				#endif
			}
		}
		cout << curr << endl;
	}
}