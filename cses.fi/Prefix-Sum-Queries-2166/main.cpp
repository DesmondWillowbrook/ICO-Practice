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

void update (int l, int r, int target_l, int target_r, int pos, int val) {
	if (target_l > r || l > target_r) {
		return;
	}

	if (l == r) {
		difference[pos] += val;
		return;
	}

	int mid = (l + r)/2;
	if (target_l <= l && r <= target_r) {
		difference[pos] += val;
	}
	update(l, mid, target_l, target_r, pos*2, val);
	update(mid + 1, r, target_l, target_r, pos*2, val);
}

int query_max (int l, int r, int target_l, int target_r, int pos) {
	if (target_l > r || l > target_r) {
		return -1;
	}

	if (l == r) {
		segtree[pos] += difference[pos];
		difference[pos] = 0;
		return segtree[pos];
	}

	int mid = (l + r)/2;
	if (target_l <= l && r <= target_r) {
		return max(segtree[pos*2], segtree[pos*2 + 1]) + difference[pos];
	} else {
		difference[pos*2] += difference[pos];
		difference[pos*2 + 2] += difference[pos];
		difference[pos] = 0;

		return max(query_max(l, mid, target_l, target_r, pos*2),
			query_max(mid + 1, r, target_l, target_r, pos*2 + 1)) + difference[pos];
	}
}

int main () {
	int n, q;
	cin >> n >> q;
	segtree = (int*) malloc (sizeof(int) * n * 2);
	difference = (int*)  malloc (sizeof(int) * n * 2);

	for (int i = n; i < 2*n; i++) {
		cin >> segtree[i];
		if (i > n) {segtree[i] += segtree[i - 1];}
	}

	for (int i = 0; i < q; i++) {

	}
	free(segtree);
}