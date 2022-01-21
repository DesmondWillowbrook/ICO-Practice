#include <bits/stdc++.h>

using namespace std;

int main () {
	int t; cin >> t;
	while (t--) {
		int n; int l; cin >> n >> l; long long int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		long long int ans = 0;

		for (int ind = 0; ind < l; ind++) {
			int one_count = 0;
			for (int i = 0; i < n; i++) {
				one_count += (a[i] >> ind) & 1;
			}
			#ifdef DEBUG
			printf ("one_count for ind %d is %d\n", ind, one_count);
			#endif
			if (one_count > n/2) {
				#ifdef DEBUG
				printf ("Adding %d to %lld\n", (1 << ind), ans);
				#endif
				ans += ((long long int) 1 << ind);
			}
		}
		cout << ans << endl;
	}
}