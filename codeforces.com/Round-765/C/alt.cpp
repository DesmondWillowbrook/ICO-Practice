#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
void preview_diff () {

}
#endif

int main () {
	int n, l, k; cin >> n >> l >> k;
	int p[n], d[n + 1];

	for (int i = 0; i < n; i++) {
		cin >> d[i];
	} d[n] = n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	pair<int, int> removal_diff[n + 1];
	
	int init_time = 0;

	for (int i = 0; i < n; i++) {
		init_time += (d[i + 1] - d[i]) * p[i];
	}
	init_time += (n - d[n - 1]) * p[n - 1];

	for (int i = 1; i < n; i++) {
		pair<int, int> r;
		r.first =
			(d[i + 1] - d[i]) * p[i] + (d[i + 1] - d[i]) * p[i - 1];
		r.second = i;
		removal_diff[i] = r;
	}
	removal_diff[0] = {0, -1};
	auto max_diff = removal_diff[0];
	for (int i = 0; i < n; i++) {
		max_diff = max (max_diff, removal_diff[i]);
	}
	
	for (int c = 0; c < k; c++) {
		auto r = max_diff;
		int i = r.second;
		init_time -= r.first;
		removal_diff[i].second = -1;

		// adjust dist of sign before deleted element
		int before_pos = i - 1, after_pos = i + 1;
		for (; before_pos >= 0 && removal_diff[before_pos].second != -1; before_pos--);
		if (before_pos >= 0 && removal_diff[before_pos].second != -1) {
			// adjust
			d[before_pos] += d[i] - d[before_pos];

			int before_before_pos = before_pos - 1;
			for (; before_before_pos >= 0 && removal_diff[before_before_pos].second != -1; before_before_pos--);
			if (before_before_pos >= 0 && removal_diff[before_before_pos].second != -1) {
				removal_diff[before_pos].first = (d[i] - d[before_pos]) * p[before_pos] + (d[i] - d[before_pos]) * p[before_before_pos];
			}
		}
		for (; after_pos < n && removal_diff[after_pos].second != -1; after_pos++);
		if (after_pos < n && removal_diff[after_pos].second != -1) {
			//adjust
			removal_diff[after_pos].first = (d[i] - d[before_pos]) * p[before_pos] + (d[i] - d[before_pos]) * p[before_before_pos];
		}

	

		pair<int, int> s;
		s.first =
			(d[i] - d[before_pos]) * p[before_pos] + (d[i] - d[before_pos]) * p[i - 1];
		s.second = before_pos;

		// adjust removal_diff of sign after element
	}
}