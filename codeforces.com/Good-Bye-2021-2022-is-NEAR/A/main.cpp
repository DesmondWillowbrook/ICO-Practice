#include <bits/stdc++.h>

using namespace std;

int main () {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int arr[n]; 
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		set<int> s;

		for (int i = 0; i < n; i++) {
			if (s.find(arr[i]) != s.end()) {
				s.insert(-arr[i]);
			} else {
				s.insert(arr[i]);
			}
		}
		cout << s.size() << endl;
	}
}