#include<bits/stdc++.h>

using namespace std;

int main () {
	int n, q; cin >> n >> q;
	pair<pair<int, int>, int> queries[q];
	for (int i = 0; i < q; i++) {
		cin >> queries[i].first.first >> queries[i].first.second >> queries[i].second;
		queries[i].first.first--; queries[i].first.second--; queries[i].second--;
	}

	int arr[n];
	iota(arr, arr + n, 1);
	while (next_permutation(arr, arr + n)) {
		bool should_break = false;
		for (int i = 0; i < q; i++) {
			int min_n = arr[queries[i].second];
			for (int idx = queries[i].first.first; idx <= queries[i].first.second; idx++) {
				if (arr[idx] < min_n) {
					should_break = true;
					break;
				}
			}
			if (should_break == true) break;
		}
		if (should_break == false) {
			for (int i = 0; i < n; i++) {printf ("%d ", arr[i]);}
			cout << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
}