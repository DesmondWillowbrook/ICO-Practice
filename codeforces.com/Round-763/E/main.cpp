#include <bits/stdc++.h>

using namespace std;

struct node {
	char c;
	bool doubled;
	int left;
	int right;
};

void in_order (string& curr, struct node* tree, int i) {
	if (tree[i].left != -1) {
		in_order (curr, tree, tree[i].left);
	}
	curr.push_back(tree[i].c);
	if (tree[i].doubled) {
		curr.push_back(tree[i].c);
	}
	if (tree[i].right != -1) {
		in_order (curr, tree, tree[i].right);
	}
}

void flat_map (vector<int>& curr,  struct node* tree, int index) {
	if (tree[index].left != -1) {
		flat_map(curr, tree, tree[index].left);
	}
	curr.push_back(index);
	if (tree[index].right != -1) {
		flat_map(curr, tree, tree[index].right);
	}
}

int count_index (int target, int count, int index, struct node* tree) {
	if (target == count) {
		return index;
	}
	if (tree[index].left != -1) {
		count_index (target, count + 1, tree[index].left, tree);
	}
	if (tree[index].right != -1) {
		count_index (target, count + 1, tree[index].right, tree);
	}
	return count;
}

int set_double (int target, int index) {
	
}

int main () {
	int n, k; cin >> n >> k;
	struct node tree[n];
	for (int i = 0; i < n; i++) {
		cin >> tree[i].c;
	}

	for (int i = 0; i < n; i++) {
		cin >> tree[i].left >> tree[i].right;
		tree[i].left--; tree[i].right--;
	}
	string original("");
	string modified("");
	in_order(original, tree, 0);
	in_order(modified, tree, 0);

	vector<int> flat_rep; flat_map(flat_rep, tree, 0);
	string ans;

	stack<int> st; st.push(0);
	while (original >= modified && !st.empty()) {
		ans = modified;
		for (int i = 0; i < original.length(); i++) {
			if (original[i] <= modified[i]) {
				tree[flat_rep[i]].doubled = true;
				modified = "";
				in_order(modified, tree, 1);
				break;
			}
		}
	}
	cout << ans << endl;
}