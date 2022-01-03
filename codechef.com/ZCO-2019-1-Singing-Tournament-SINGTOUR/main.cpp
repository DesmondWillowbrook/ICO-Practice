#include <bits/stdc++.h>

using namespace std;

/*
exploit fact that total overlap => 2 points,
while overlap => 1 point
for both singers,

*/

int main () {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		pair<int, int> upper[n]; pair<int, int> lower[n]; int scores[n];

		for (int i = 0; i < n; i++) {
			cin >> lower[i].first >> upper[i].first;
			lower[i].second = i;
			upper[i].second = i;
			scores[i] = 0;
		}

		sort (lower, lower + n);
		sort (upper, upper + n);

		for (int i = 0; i < n; i++) {
			scores[upper[i].second] += i; // i singers (0 to i - 1) have lower high range than ith singer
			scores[lower[i].second] += n - i; // n - i singers (i + 1 to n) have higher low range than ith singer
		}
		for (int i = 0; i < n; i++) {
			cout << scores[i] - 1 << " ";
		}
		cout << endl;
	}
}