#include <bits/stdc++.h>

using namespace std;

int main () {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		pair<int, int> ranges[n];
		for (int i = 0; i < n; i++) {
			cin >> ranges[i].first >> ranges[i].second;
		}
		sort(ranges, ranges+n);
		for (int i = 0; i < n; i++) {
			int l = ranges[i].first, r = ranges[i].second;

			if (l == r) {
				printf ("%d %d %d\n", l, r, l);
				continue;
			}

			bool broken = false;
			for (int d = l + 1; d < r; d++) {
				auto match1 = lower_bound(ranges, ranges + n, make_pair(l, d - 1));
				auto match2 = lower_bound(ranges, ranges + n, make_pair(d + 1, r));
				if (match1 == ranges + n || match2 == ranges + n) {
					continue;
				}
				if ((*match1).first == l && (*match1).second == d - 1
					&& (*match2).first == d + 1 && (*match2).second == r) {
					printf ("%d %d %d\n", l, r, d);
					broken = true;
					break;
				}
			}
			if (broken) {continue;}
			// case where start or end element was deleted
			auto startmatch = lower_bound(ranges, ranges + n, make_pair(l + 1, r));
			if (startmatch != ranges + n && *startmatch == make_pair(l + 1, r)) {
				printf ("%d %d %d\n", l, r, l);
			}
			auto endmatch = lower_bound(ranges, ranges + n, make_pair(l, r - 1));
			if (endmatch != ranges + n && *endmatch == make_pair(l, r - 1)) {
				printf ("%d %d %d\n", l, r, r);
			}
		}
		cout << endl;
	}
}