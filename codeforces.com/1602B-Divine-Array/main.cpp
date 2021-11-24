#include<bits/stdc++.h>

using namespace std;

uint number_occurence[2001];
uint initial_array[2001];
uint idx_tracking[2001];
pair<uint, uint> queries[100001]; //iter, idx

void run (uint n, uint q) {
	memset(number_occurence, 0, n);

	for (uint i = 0; i < n; i++) {
		cin >> initial_array[i];
		number_occurence[initial_array[i]]++;
	}

	for (uint i = 0; i < n; i++) {
		if (number_occurence[i] > 0) {
			idx_tracking[i] = number_occurence[i];
		}
	}
	for (uint i = 0; i < q; i++) {
		cin >> queries[i].second >> queries[i].first;		
	}
	sort(queries, queries+q);

	uint* old_arr = number_occurence, *new_arr = initial_array;

	for (uint iter = 0, qidx = 0; qidx < q; iter++) {
		memset(new_arr, 0, n);

		for (uint i = 0; i < n; i++) {
			new_arr[old_arr[i]]++;
		}

		for (uint i = 0; i < n; i++) {
			idx_tracking[i] = new_arr[idx_tracking[i]];
		}

		while (queries[qidx].first == iter) {
			cout << idx_tracking[queries[qidx].second] << " is the answer." << endl;
			qidx++;
		}
		swap(new_arr, old_arr);
	}
}

int main () {
	int t; cin >> t;
	while (t--) {
		uint n, q; cin >> n >> q;
		run(n, q);
	}
}