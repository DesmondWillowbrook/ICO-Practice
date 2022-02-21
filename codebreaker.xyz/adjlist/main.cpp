#include<bits/stdc++.h>

using namespace std;

int main () {
	int n, e; cin >> n >> e;
	vector<int> adj_list[n];
	for (int i = 0; i < e; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		for (auto e: adj_list[i]) {
			cout << e + 1 << " ";
		}
		cout << endl;
	}
}