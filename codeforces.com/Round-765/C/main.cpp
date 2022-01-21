#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
int preview_diff (map<int, int> m) {
	for(auto it = m.begin(); it != m.end(); ++it)
	{
		std::cout << it->first << " " << it->second << endl;
	}
	return 0;
}
#endif

int main () {
	int n, l, k; cin >> n >> l >> k;
	int p[n], d[n + 2];

	for (int i = 0; i < n; i++) {
		cin >> d[i];
	} d[n] = n;

	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	map<int, int> removal_diff;
	
	int init_time = 0;

	for (int i = 0; i < n; i++) {
		init_time += (d[i + 1] - d[i]) * p[i];
	}

	for (int i = 1; i < n; i++) {
		removal_diff[i] =
			((d[i + 1] - d[i]) * p[i]) - ((d[i + 1] - d[i]) * p[i - 1]);
	}
	removal_diff[0] = -1;
	removal_diff[n] = -1;

	#ifdef DEBUG
	preview_diff (removal_diff);
	#endif

	pair<int, int> max_diff = {removal_diff[0], 0};
	for (int i = 0; i < n; i++) {
		if (max_diff.first < removal_diff[i]) {
			max_diff = {removal_diff[i], i};
		}
	}
	
	for (int c = 0; c < k; c++) {
		#ifdef DEBUG
		preview_diff (removal_diff);
		#endif

		auto diff = max_diff.first;
		init_time -= diff;

		d[(*(--removal_diff.find(max_diff.second))).first] += d[max_diff.second] - d[(*(--removal_diff.find(max_diff.second))).first];
		removal_diff.erase(max_diff.second);

		for (int i = 1; i < n; i++) {
			if (removal_diff.find(i) == removal_diff.end()) {continue;}

			removal_diff[i] =
				(d[(*(++removal_diff.find(i))).first] - d[i]) * p[i]
				+ (d[(*(++removal_diff.find(i))).first] - d[i]) * p[(*(--removal_diff.find(i))).first];

			if (max_diff.first < removal_diff[i]) {
				max_diff = {removal_diff[i], i};
			}
		}
	}
	cout << init_time << endl;
}