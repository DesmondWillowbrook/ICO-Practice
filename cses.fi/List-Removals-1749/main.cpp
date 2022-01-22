#include<bits/stdc++.h>

using namespace std;

int n;
int* segtree;
int* arr;

void build (int l, int r, int pos) {
	#ifdef DEBUG
	printf ("build (%d, %d, %d)\n", l, r, pos);
	#endif

	if (l == r) {
		cin >> arr[l];
		segtree[pos] = 1;
		return;
	}
	int mid = (l + r)/2;
	build(l, mid, pos*2);
	build(mid + 1, r, pos*2 + 1);
	segtree[pos] = segtree[pos*2] + segtree[pos*2 + 1];
}

int upd_ind (int l, int r, int idx, int pos) {
	#ifdef DEBUG
	printf ("upd_ind (%d, %d, %d, %d)\n", l, r, idx, pos);
	#endif

	if (l == r) {
		segtree[pos] = 0;
		return l;
	}
	int mid = (l + r) / 2;
	int ans;
	if (idx <= segtree[pos*2]) {
		ans = upd_ind (l, mid, idx, pos*2);
	} else {
		ans = upd_ind (mid + 1, r, idx - segtree[pos*2], pos*2 + 1);
	}

	segtree[pos] = segtree[pos*2] + segtree[pos*2 + 1];
	return ans;
}

#ifdef DEBUG
void preview_segtree () {
	cout << endl;
	for (int i = 1; i < 4*n; i++) {
		printf ("%02d ", i);
	} cout << endl;
	for (int i = 1; i < 4*n; i++) {
		printf ("%02d ", segtree[i]);
	} cout << endl;
}
#endif

int main () {
	cin >> n;
	segtree = (int*) alloca (4 * n * sizeof(n));
	arr = (int*) alloca (n * sizeof(n) + 1);

	#ifdef DEBUG
	fill_n(segtree, 4*n, 0);
	#endif
	build(1, n, 1);
	#ifdef DEBUG
	preview_segtree ();
	#endif

	for (int i = 0; i < n; i++) {
		int idx; cin >> idx;
		#ifdef DEBUG
		cout << "Deleting number at index " << idx << "\n";
		#endif
		cout << arr[upd_ind(1, n, idx, 1)] << " ";
		#ifdef DEBUG
		preview_segtree ();
		#endif
	}
	cout << endl;
}