#include <bits/stdc++.h>

using namespace std;

int main () {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; s.reserve(n);
		cin >> s;
		int mir_pos = 0;
		for (; mir_pos < (s.size() - 1) && s[0] > s[mir_pos + 1]; mir_pos++);
		for (int i = 0; i <= mir_pos; i++) {
			cout << s[i];
		}
		for (int i = mir_pos; i >= 0; i--) {
			cout << s[i];
		}
		cout << endl;
	}
}