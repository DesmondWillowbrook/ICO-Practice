#include <bits/stdc++.h>

using namespace std;

int main () {
	uint t; cin >> t;
	while (t--) {
		uint n, k; cin >> n >> k;
		int arr[n + 1], imb[n + 1], ans[n + 1] = {0};

		int imbalance = 0; char curr;
		for (uint i = 1; i <= n; i++) {
			cin >> curr;
			if (curr == '0') {imbalance++;}
			else {imbalance--;}

			#ifdef DEBUG
			printf ("Imbalance is: %d\n", imbalance);
			#endif

			imb[i] = imbalance;
		}
		imb[0] = 0;
		// imbalance queries are exclusive on left side and inclusive on the right
		uint start = 1, end = n;
		while (start != n + 1) {
			while (abs(imb[end] - imb[start - 1]) > k) end -= abs(imb[end] - imb[start - 1]) - k;

			#ifdef DEBUG
			printf ("Start is: %d, end is: %d, and imbalance is %d\n", start, end, abs(imb[end] - imb[start]));
			#endif

			ans[start] = 1;
			start = end + 1; end = n;
		}

		for (uint i = 1; i <= n; i++) cout << ans[i];
		cout << endl;
	}
}