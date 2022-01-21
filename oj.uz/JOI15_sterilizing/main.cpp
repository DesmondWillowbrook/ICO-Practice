#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 16 * (100069);
int n, q, k;

long long int sumtree[MAX_N];
int arr[MAX_N];

void build (int l, int r, int pos) {
	if (l == r) {
		sumtree[pos] = arr[l];
		return;
	}
	int mid = (l + r)/2;
	build (l, mid, pos * 2);
	build (mid + 1, r, pos * 2 + 1);
	sumtree[pos] = sumtree[pos * 2] + sumtree[pos * 2 + 1];
}

void update (int l, int r, int pos, int index, long long int value) {
	if (l == r) {
		sumtree[pos] = value;
		return;
	}
	
	int mid = (l + r)/2;
	if (index <= mid) {
		update (l, mid, pos * 2, index, value);
	} else {
		update (mid + 1, r, pos * 2 + 1, index, value);
	}
	sumtree[pos] = sumtree[pos * 2] + sumtree[pos * 2 + 1];
}

void spray (int l, int r, int target_l, int target_r, int pos) {
	if (r < target_l || l > target_r || sumtree[pos] == 0) {return;}
	
	if (l == r) {
		sumtree[pos] = sumtree[pos] / k;
		return;
	}

	int mid = (l + r)/2;
	spray (l, mid, target_l, target_r, pos * 2);
	spray (mid + 1, r, target_l, target_r, pos * 2 + 1);

	sumtree[pos] = sumtree[pos * 2] + sumtree[pos * 2 + 1];
}

long long int query (int l, int r, int target_l, int target_r, int pos) {
	if (r < target_l || l > target_r) {return 0;}
	if (target_l <= l && r <= target_r) {return sumtree[pos];}

	int mid = (l + r)/2;
	return query(l, mid, target_l, target_r, pos*2) + 
		query(mid + 1, r, target_l, target_r, pos*2 + 1);
}

int main () {
	cin >> n >> q >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	build (1, n, 1);

	for (int i = 0; i < q; i++) {
		int op_type; cin >> op_type;
		if (op_type == 1) {
			int ind; long long int val; cin >> ind >> val;
			update (1, n, 1, ind, val);
		} else if (op_type == 2 && k > 1) {
			int l, r; cin >> l >> r;
			spray (1, n, l, r, 1);
		} else if (op_type == 3) {
			int l, r; cin >> l >> r;
			cout << query(1, n, l, r, 1) << endl;
		}
	}
}