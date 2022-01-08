#include<bits/stdc++.h>

using namespace std;

int n;
int* segtree;
int* arr;

void build (int l, int r, int pos) {
	if (l == r) {
		segtree[pos] = 0;
		return;
	}

	int mid = (l + r) / 2;
	build (l, mid, pos * 2);
	build (mid + 1, r, pos * 2 + 1);
}

void update (int l, int r, int idx, int val, int pos) {
	if (l == r) {
		segtree[pos] = val;
		return;
	}

	int mid = (l + r)/2;
	if (idx <= mid) {
		update (l, mid, idx, val, pos * 2);
	} else {
		update (mid + 1, r, idx, val, pos * 2 + 1);
	}
	segtree[pos] = max(segtree[pos * 2], segtree[pos * 2 + 1]);
}

int query (int l, int r, int target_l, int target_r, int pos) {
	if (l > target_r || r < target_l) {return 0;}

	if (target_l <= l && r <= target_r) {
		return segtree[pos];
	}
	int mid = (l + r) / 2;
	return max (query (l, mid, target_l, target_r, pos * 2), 
		query (mid + 1, r, target_l, target_r, pos * 2 + 1));
}

bool comp (const pair<int, int>& a, const pair<int, int>& b) {
	return a.first < b.first || (a.first == b.first && a.second > b.second);
}

int main () {
	cin >> n;
	segtree = (int*) malloc(sizeof(int) * (4*n + 1));
	build (1, n, 1);

	pair<int, int> arr[n + 1];

	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort (arr + 1, arr + n + 1/*for strict LIS: , comp*/);

	int ans = 1;
	for (int i = 1; i <= n; i++) {
		int new_len = query(1, n, 1, arr[i].second, 1) + 1;
		#ifdef DEBUG
		printf ("%d %d - %d\n", arr[i].first, arr[i].second, new_len);
		#endif
		update(1, n, arr[i].second, new_len, 1);
		ans = max(ans, new_len);
	}
	cout << ans << endl;
}