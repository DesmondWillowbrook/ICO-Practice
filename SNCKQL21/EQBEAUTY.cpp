#include<bits/stdc++.h>

using namespace std;

/*
Difference in beauty of the two arrays is min. number of moves required to 
make both arrays equal in beauty.
=> Min. difference in beauty between both arrays is desirable.
*/

/*
Strategy:
Sort array, we know that smallest and biggest will determine beauty of one or both arrays.
Pair smallest and biggest with two elements which are adjacent, or
start with elements at opposite ends and adjust indices to get difference as low as possible.
*/

long long int solve () {
	long int n; cin >> n;
	vector<long int> a (n);
	for (long int i = 0; i < n; i++) cin >> a[i];

	sort(a.begin(), a.end());
	
	if (n == 2) return 0;
	if (n == 3) return min(a[2] - a[1], a[1] - a[0]); // sort before to make it idiotproof

	long int c = 0, d = 0, ans;
	for (long int i = 0; i < n - 1; i++) {
		c += abs(a[((n-1)/2)] - a[i]);
	}
	for (long int i = 1; i < n; i++) {
		d += abs(a[((n-1)/2)+1] - a[i]);
	}
	ans = min (c, d);

	long int small_pair = n - 2, big_pair = 1, small_dif, big_dif;

	while (small_pair > big_pair) {
		small_dif = a[small_pair] - a[0];
		big_dif = a[n-1] - a[big_pair];

		ans = min(ans, abs(small_dif - big_dif));

		if (small_dif > big_dif) small_pair--;
		else if (small_dif < big_dif) big_pair++;
		else return 0; //rather redundant, but I'll leave it.
	}

	return ans;
}

int main () {
	long int t; cin >> t;

	while (t--) {
		cout << solve() << endl;
	}
}