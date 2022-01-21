#include <bits/stdc++.h>

using namespace std;

int calc_cost (pair<pair<int, int>, int> min_s, pair<pair<int, int>, int> max_s) {
	int cost;

	if (max_s != min_s) {cost = max_s.second + min_s.second;}
	else {cost = min_s.second;}
	
	return cost;
}

bool st_comp (const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
return (a.first.first < b.first.first || (a.first.first == b.first.first && a.second < b.second));
}

bool lt_comp (const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
	return (a.first.second < b.first.second || (a.first.second == b.first.second && a.second < b.second));
}

// a expected to be <= b
void swi (int& int_num, int& cost, pair<pair<int, int>, int> min_s, pair<pair<int, int>, int> max_s) {
	#ifdef DEBUG
	printf ("Considering (%d, %d (%d)), (%d, %d (%d))\n", min_s.first.first, min_s.first.second, min_s.second, max_s.first.first, max_s.first.second, max_s.second);
	#endif

	if (int_num == max_s.first.second - min_s.first.first + 1) {
		if (calc_cost(min_s, max_s) < cost) {
			cost = calc_cost(min_s, max_s);
			int_num = max_s.first.second - min_s.first.first + 1;
		}
	} else if (int_num < max_s.first.second - min_s.first.first + 1) {
		cost = calc_cost(min_s, max_s);
		int_num = max_s.first.second - min_s.first.first + 1;
	}
}

int main () {
	int t; cin >> t;

	//assert(lt_comp({{8, 7}, 7}, {{2, 10}, 252}))
	
	while (t--) {
		int n; cin >> n;
		pair<pair<int, int>, int> segments[n], reverse_segments[n];
		for (int i = 0; i < n; i++) {
			cin >> segments[i].first.first >> segments[i].first.second >> segments[i].second;
		}

		// base case
		pair<pair<int, int>, int> min_s = segments[0], max_s = segments[0];
		int cost = INT_MAX, int_num = 0;
		for (int i = 0; i < n; i++) {
			min_s = min (min_s, segments[i], st_comp);
			max_s = max (max_s, segments[i], lt_comp);

			swi (int_num, cost, min_s, max_s);
			swi (int_num, cost, segments[i], segments[i]);

			cout << cost << endl;
		}
	}
}