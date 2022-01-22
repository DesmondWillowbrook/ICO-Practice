#include<bits/stdc++.h>

using namespace std;

int n;
int* segtree;
int* arr;

void build (int l, int r, int pos) {
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

int main () {
	cin >> n;
	segtree = (int*) alloca (4 * n * sizeof(n));
	arr = (int*) alloca (n * sizeof(n) + 1);

	build(1, n, 1);

	for (int i = 0; i < n; i++) {
		int idx; cin >> idx;
		cout << arr[upd_ind(1, n, idx, 1)] << " ";
	}
	cout << endl;
}