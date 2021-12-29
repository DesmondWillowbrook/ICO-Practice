#include<bits/stdc++.h>

using namespace std;

void solve () {
	int n, a, b; cin >> n >> a >> b;
	pair<int, int> joy[n];
	for (int i = 0; i < n; i++) {
		cin >> joy[i].first >> joy[i].second;
		#ifdef DEBUG
		printf ("Joy range is (%d, %d)\n", joy[i].first, joy[i].second);
		#endif
	}
	sort (joy, joy + n);

	set<uint> possible;
	possible.insert(0);

	for (int i = a; i <= b; i++) {
		for (int x = ((b - a + 1) * (a + b))/2; x >= 0; x--) {
			if (possible.count(x) == 1) {
				possible.insert(x + i);
			}
		}
	}
	#ifdef DEBUG
	printf ("Possible wake times:\n");
	for (auto it : possible) {
		printf ("%d ", it);
	}
	cout << endl;
	#endif

	int best_joy = 0;
	for (int i = 0, start_idx = 0, end_idx = 0, current_joy = 0; i <= joy[n-1].second; i++) {
		if (start_idx < n && i == joy[start_idx].first) {
			#ifdef DEBUG
			printf ("Start of range (%d, %d); incrementing joy to %d\n", joy[start_idx].first, joy[start_idx].second, current_joy + 1);
			#endif
			current_joy++; start_idx++;
		}
		if (end_idx < n && i == joy[end_idx].second) {
			#ifdef DEBUG
			printf ("End of range (%d, %d); decrementing joy to %d\n", joy[end_idx].first, joy[end_idx].second, current_joy - 1);
			#endif
			current_joy--; end_idx++;
		}
		#ifdef DEBUG
		printf ("Checked %dth time, current joy is %d\n", i, current_joy);
		#endif
		if (possible.find(i) != possible.end()) {
			#ifdef DEBUG
			printf ("Can wake at %dth time, current joy is %d\n", i, current_joy);
			#endif
			best_joy = max(best_joy, current_joy);
		}
	}
	cout << best_joy << endl;
	
}

int main () {
	uint t; cin >> t;
	while (t--) {
		solve();
	}
}