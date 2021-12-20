#include<bits/stdc++.h>

using namespace std;

int main () {
	uint n; cin >> n;
	int curr[n], ideal[n];
	for (uint i = 0; i < n; i++) {cin >> curr[i];}
	for (uint i = 0; i < n; i++) {cin >> ideal[i];}

	#ifdef DEBUG
	printf ("Input taking finished\n");
	#endif

	uint ans = 0, start_ind = 0, end_ind = 0;
	while (true) {
		// skip to mismatch
		for (; curr[start_ind] == ideal[start_ind] && start_ind < n; start_ind++);
		if (start_ind == n) {break;} // all achieved ideal, loop over

		for (end_ind = start_ind; curr[end_ind] != ideal[end_ind] && end_ind < n; end_ind++);

		#ifdef DEBUG
		printf ("Range found: [%d, %d)\n", start_ind, end_ind);
		#endif

		// decrease/increase
		if (curr[start_ind] < ideal[start_ind]) {
			for (uint i = start_ind; i < end_ind; i++) {
				curr[i] += 1;
			}
		} else {
			for (uint i = start_ind; i < end_ind; i++) {
				curr[i] -= 1;
			}
		}
		ans++;
	}
	cout << ans << endl;
}