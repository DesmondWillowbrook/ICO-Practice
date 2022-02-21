#include <bits/stdc++.h>

using namespace std;

int* segtree;
int* difference;

void build_tree (int l, int r, int pos) {
	if (l == r) {
		return;
	}

	int mid = (l + r)/2;
	build_tree(l, mid, pos*2);
	build_tree(mid + 1, r, pos*2 + 1);

	segtree[pos] = max(segtree[pos*2], segtree[pos*2 + 1]);
}

void update (int l, int r, int target_l, int target_r, int pos, int diff) {
	if (target_l > r || l > target_r) {
		return;
	}

	if (target_l <= l && r <= target_r) {
		difference[pos] += diff;
		return;
	}

	int mid = (l + r)/2;
	update(l, mid, target_l, target_r, pos*2, diff);
	update(mid + 1, r, target_l, target_r, pos*2 + 1, diff);
}

int query_max (int l, int r, int target_l, int target_r, int pos, int diff) {
	if (target_l > r || l > target_r) {
		return -1;
	}

	int mid = (l + r)/2;
	if (target_l <= l && r <= target_r) {
		if (l != r) {
			difference[pos*2] += difference[pos];
			difference[pos*2 + 1] += difference[pos];
			segtree[pos] += difference[pos];
			difference[pos] = 0;
		}
		return segtree[pos];
	} else {
		return max(query_max(l, mid, target_l, target_r, pos*2, diff),
			query_max(mid + 1, r, target_l, target_r, pos*2 + 1, diff));
	}
}

#ifdef DEBUG
void display_tree (int n) {
	for (int i = 0; i < 2*n; i++) {
		printf ("%02d ", segtree[i]);
	} cout << endl;
	for (int i = 0; i < 2*n; i++) {
		printf ("%02d ", difference[i]);
	} cout << endl << endl;
}
#endif

int main () {
	int n, q;
	cin >> n >> q;
	segtree = (int*) malloc (sizeof(int) * n * 2);
	difference = (int*)  malloc (sizeof(int) * n * 2);
	fill_n (difference, 2*n, 0);
	int arr[n];

	for (int i = n; i < 2*n; i++) {
		cin >> arr[i - n]; segtree[i] = arr[i - n];
		if (i > n) {segtree[i] += segtree[i - 1];}
	}
	build_tree(1, n, 1);

	for (int i = 0; i < q; i++) {
		int type; cin >> type;
		if (type == 1) {
			int k, u; cin >> k >> u;
			update(1, n, k, n, 1, u - arr[k]);
			arr[k] = u;
		} else if (type == 2) {
			int a, b; cin >> a >> b;
			cout << query_max(1, n, a, b, 1, 0) << endl;
		}
		#ifdef DEBUG
		display_tree (n);
		#endif
	}
	free(segtree);
	free(difference);
}