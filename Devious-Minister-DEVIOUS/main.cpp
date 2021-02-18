#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool len_cmp (pair<size_t, size_t> a, pair<size_t, size_t> b) {
	return abs((ll) a.first - (ll) a.second) < abs((ll) b.first - (ll) b.second);
}

int main () {
	size_t N; cin >> N;
	int p[N]; for (size_t i = 0; i < N; i++) cin >> p[i];

	pair<ll, size_t> sums[N]; sums[0] = {p[0], 1};
	for (size_t i = 1; i < N; i++) sums[i] = {sums[i - 1].first + p[i], i + 1};

	#ifdef DEBUG
	for (size_t i = 0; i < N; i++) printf ("%lld %ld\n", sums[i].first, sums[i].second);	
	cout << endl;
	#endif

	sort (sums, sums + N);

	#ifdef DEBUG
	for (size_t i = 0; i < N; i++) printf ("%lld %ld\n", sums[i].first, sums[i].second);
	cout << endl;
	#endif

	ll ans = LONG_LONG_MAX; pair<size_t, size_t> seg = {0, 0};
	pair<ll, size_t> start, end;

	for (size_t i = 1; i < N; i++) {
		start = sums[i - 1]; end = sums[i];
		if (start.second > end.second) swap (start, end);

		if (abs(ans) >= abs(start.first - end.first)) {
			if (abs(ans) > abs(start.first - end.first))
				seg = {start.second + 1, end.second};
			else
				seg = min (seg, {start.second + 1, end.second}, len_cmp);

			ans = end.first - start.first;
		}
	}

	printf ("%lld\n%ld %ld\n", ans, seg.first, seg.second);
}