#include<bits/stdc++.h>

using namespace std;

struct node* segtree;
int* employee_to_salary;
priority_queue<pair<int, int>, greater<pair<int, int>>> emps;

// for base nodes, store salary in max, min, sum = 1, num = employee number
struct node {
	int max, min, sum;
};

bool comp_node (const struct node& a, const struct node& b) {
	return a.max < b.max;
}

struct node merge (const struct node& a, const struct node& b) {
	return node {
		max: max(a.max, b.max),
		min: min(a.min, b.min),
		sum: a.sum + b.sum,
	};
}

void build (int l, int r, int pos) {
	if (l == r) {
		cin >> segtree[pos].max;
		segtree[pos].min = segtree[pos].max;
		segtree[pos].sum = 1;
		employee_to_salary[l] = segtree[pos].max;	
		return;
	}
	int mid = (l + r)/2;
	build(l, mid, pos*2);
	build(mid + 1, r, pos*2 + 1);
	segtree[pos] = merge(segtree[pos*2], segtree[pos*2 + 1]);
}

void update (int l, int r, int pos) {
	if (l == r) {
		return;
	}
	int mid = (l + r)/2;
	update(l, mid, pos*2);
	update(mid + 1, r, pos*2 + 1);
	segtree[pos] = merge(segtree[pos*2], segtree[pos*2 + 1]);
}

/*
maintain segtree
*/

int main () {
	int n; cin >> n;
	int size = 1;
	while (size < n) {size <<= 1;}
	segtree = (struct node*) malloc(size * sizeof(struct node));
	
	employee_to_salary = (int*) malloc(n * sizeof(int));
	for (int i = size/2; i < size; i++) {
		if (i < n) {
				
		} else {
			segtree[i].max = segtree[i].min = 0;
			segtree[i].sum = 0;
		}
	}
	sort (segtree + size/2, segtree + size);

	free(segtree);
	free(employee_to_salary);
}