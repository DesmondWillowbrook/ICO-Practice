#include<bits/stdc++.h>

using namespace std;

int main () {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a[n]; map<int, vector<int>> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			m[a[i]].push_back(i);
		}

		int ans = -1;
		for (auto it = m.begin(); it != m.end(); it++) {
			auto arr = (*it).second;
			for (long unsigned int i = 1; i < arr.size(); i++) {
				ans = max (ans, n - (arr[i] - arr[i - 1]));
			}
		}
		cout << ans << endl;
	}
}