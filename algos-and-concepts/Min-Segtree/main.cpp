#include<bits/stdc++.h>

using namespace std;

void build (int l, int r, int pos, int* segtree, int* arr, int n) {
	#ifdef DEBUG
	printf ("range: (%d %d); pos: %d\n", l, r, pos);
	#endif
	if (l == r) {
		segtree[pos] = arr[l];
		return;
	}
	int mid = (l + r)/2;
	build(l, mid, pos*2, segtree, arr, n);
	build(mid + 1, r, pos*2 + 1, segtree, arr, n);
	segtree[pos] = segtree[pos*2] + segtree[pos*2 + 1];
}

void update (int l, int r, int* segtree, int pos, int* arr, int ind, int val, int n) {
	if (l <= ind && ind <= r) {
		segtree[pos] -= arr[ind]; //remove previous value
		segtree[pos] += val; //add new value

		if (l != r) {
			int mid = (l + r)/2;
			update (l, mid, segtree, pos*2, arr, ind, val, n);
			update (mid + 1, r, segtree, pos*2 + 1, arr, ind, val, n);
		}
	}
}

int query (int l, int r, int target_l, int target_r, int* segtree, int pos) {
	if (target_l <= l && r <= target_r) { //total intersection
		return segtree[pos];
	}
	else if ((l <= target_r && target_r <= r) || (l <= target_l && target_l <= r)) { //partial intersection
		int mid = (l + r)/2;
		return query (l, mid, target_l, target_r, segtree, pos*2)
			+ query(mid + 1, r, target_l, target_r, segtree, pos*2 + 1);
	} else {
		return 0;
	}
}

#ifdef DEBUG
void print_segtree (int* segtree, int n) {
	for (int i = 0; i < (4 * n) + 1; i++) {
		printf ("%02d ", i);
	} cout << endl;
	for (int i = 0; i < (4 * n) + 1; i++) {
		printf ("%02d ", segtree[i]);
	} cout << endl;
}
#endif

int main () {
	int n, q; cin >> n >> q;
	int arr[n], segtree[(4 * n) + 1];

	#ifdef DEBUG
	//we aren't going to be accessing 
	// extra elements normally, so we don't need to zero it out
	// but when we want to view the whole array, having zero
	// as a filler helps.
	fill_n(segtree, (4 * n) + 1, 0);
	#endif

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	build(1, n, 1, segtree, arr, n);

	#ifdef DEBUG
	print_segtree (segtree, n);
	#endif

	for (int i = 0; i < q; i++) {
		char type; cin >> type;
		if (type == 'U') {
			int ind, val; cin >> ind >> val;
			update(1, n, segtree, 1, arr, ind, val, n);	

			#ifdef DEBUG
			print_segtree (segtree, n);
			#endif
		} else if (type == 'Q') {
			int l, r; cin >> l >> r;
			cout << query (1, n, l, r, segtree, 1) << endl;
		} else {
			printf ("Unrecognised query type \'%c (%d)\'\n", type, type);
			return 0;
		}
	}
}