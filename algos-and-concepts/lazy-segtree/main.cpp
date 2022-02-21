#include<bits/stdc++.h>

using namespace std;

int *segtree, *diff;
int n, two_pow = 1;

#ifdef DEBUG
void print_tree () {
	for (int i = 0; i < two_pow; i++) {
		printf ("%d ", segtree[i]);
	}
	cout << endl;
	for (int i = 0; i < two_pow; i++) {
		printf ("%d ", diff[i]);
	}
	cout << endl;
}
#endif

// Propagates diffs within l, r range
// so nodes within l, r range are up-to-date and query-able
void propagate (int curr_l, int curr_r, int l, int r, int pos) {
	if (curr_r < l || r < curr_l) {
		return;
	}

	if (curr_l == curr_r) {
		segtree[pos] += diff[pos];
		diff[pos] = 0;
		return;
	}
	
	diff[pos*2] += diff[pos];
	diff[pos*2 + 1] += diff[pos];
	diff[pos] = 0;

	#ifdef DEBUG
	print_tree ();
	#endif

	int mid = (curr_l + curr_r) / 2;
	propagate (curr_l, mid, l, r, pos*2);
	propagate (mid + 1, curr_r, l, r, pos*2 + 1);
	segtree[pos] = segtree[pos * 2] + segtree[pos * 2 + 1];
}

// Before querying, propogate differences to ensure
// nodes are up-to-date.
int query (int curr_l, int curr_r, int l, int r, int pos) {
	if (l <= curr_l && curr_r <= r) {
		return segtree[pos];
	}

	if (curr_r < l || r < curr_l || l == r) {
		return 0;
	}
	
	int mid = (curr_l + curr_r) / 2;
	return query(curr_l, mid, l, r, pos*2) +
		query(mid + 1, curr_r, l, r, pos*2 + 1);
}

void update (int curr_l, int curr_r, int l, int r, int val, int pos) {
	if (l <= curr_l && curr_r <= r) {
		diff[pos] += val;
		return;
	}
	if (curr_r < l || r < curr_l || curr_l == curr_r) {
		return;
	}
	int mid = (curr_l + curr_r) / 2;
	update (curr_l, mid, l, r, val, pos*2);
	update (mid + 1, curr_r, l, r, val, pos*2 + 1);
}

void build (int l, int r, int pos) {
	diff[pos] = 0;
	if (l == r) {
		cin >> segtree[pos];
		return;
	}

	int mid = (l + r) / 2;
	build(l, mid, pos*2);
	build(mid + 1, r, pos*2 + 1);
	segtree[pos] = segtree[pos*2] + segtree[pos*2 + 1];
}

int main () {
	int q; cin >> n >> q;

	while (two_pow < n) {two_pow *= 2;}
	two_pow *= 2;

	segtree = (int*) malloc (two_pow * sizeof(int));
	diff = (int*) malloc (two_pow * sizeof(int));

	build(1, n, 1);

	char t;
	for (int i = 0; i < q; i++) {
		cin >> t;

		#ifdef DEBUG
		print_tree ();
		#endif

		if (t == 'u') {
			int l, r, val; cin >> l >> r >> val;
			update(1, n, l, r, val, 1);
		} else if (t == 'q') {
			int l, r; cin >> l >> r;
			propagate(1, n, l, r, 1);
			cout << query(1, n, l, r, 1) << endl;
		}
	}

	free(segtree);
	free(diff);
}