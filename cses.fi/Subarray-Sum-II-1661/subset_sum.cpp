#include<bits/stdc++.h>

using namespace std;

int main () {
	uint n; int x; cin >> n >> x;
	int a[n]; 
	map<int, long int> dp;
	dp[0] = 1;

	for (uint i = 0; i < n; i++) {
		cin >> a[i];

		#ifdef DEBUG
		printf ("Current number is: %d\n", a[i]);
		printf("Number of ways to form the following numbers are:\n");
		for (auto it = dp.begin(); it != dp.end(); it++) {
			printf ("%d: %ld\n", (*it).first, (*it).second);
		}
		#endif

		map<int, long int> new_dp;
		for (auto it = dp.begin(); it != dp.end(); it++) {
			new_dp[a[i] + (*it).first] += (*it).second;

			#ifdef DEBUG
			printf ("dp[%d] updated to %ld\n", a[i] + (*it).first, new_dp[a[i] + (*it).first]);
			#endif
		}
		// apply new_dp changes to old_dp
		for (auto it = new_dp.begin(); it != new_dp.end(); it++) {
			dp[(*it).first] += (*it).second;
		}
	}

	cout << dp[x] << endl;
}