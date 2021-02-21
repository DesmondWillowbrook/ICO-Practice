/*
Does not pass last two test cases.
Likely flaw: Returns segment eg. (4, 4) for when 0 is one station's expected profit/loss,
or any sufficiently low (in magnitude) value.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool seg_cmp (pair<size_t, size_t> a, pair<size_t, size_t> b) {
	return abs((ll) a.first - (ll) a.second) < abs((ll) b.first - (ll) b.second);
}

int main () {
	size_t N; cin >> N;
	int p[N]; for (size_t i = 0; i < N; i++) cin >> p[i];

	pair<ll, size_t> sums[N + 1]; sums[0] = {0, 0};
	for (size_t i = 1; i <= N; i++) sums[i] = {sums[i - 1].first + p[i - 1], i};

	#ifdef DEBUG
	cout << "Raw sums array: \n";
	for (size_t i = 0; i <= N; i++) printf ("%lld %ld\n", sums[i].first, sums[i].second);
	cout << endl;
	#endif

	sort (sums, sums + N + 1);

	#ifdef DEBUG
	cout << "Sorted array: \n";
	for (size_t i = 0; i <= N; i++) printf ("%lld %ld\n", sums[i].first, sums[i].second);
	cout << endl;
	#endif

	ll ans = LONG_LONG_MAX; pair<size_t, size_t> seg = {0, 0};
	pair<ll, size_t> start, end;

	for (size_t i = 1; i <= N; i++) {
		start = sums[i - 1]; end = sums[i];
		if (start.second > end.second) swap (start, end);
		
		ll revenue = end.first - start.first;
		pair<size_t, size_t> curr_seg = {start.second + 1, end.second};

		if (abs(ans) > abs(revenue) ||
			(abs(ans) == abs(revenue) && seg_cmp(seg, curr_seg))) {
			seg = curr_seg;
			ans = revenue;
		}
	}

	printf ("%lld\n%ld %ld\n", ans, seg.first, seg.second);
}