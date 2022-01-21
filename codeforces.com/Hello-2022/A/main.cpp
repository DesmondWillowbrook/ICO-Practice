#include <bits/stdc++.h>

using namespace std;

int main () {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		bool b[n][n];
		for (int i = 0; i < n; i++) {fill_n (b[i], n, false);}

		int r = 0;
		for (int x = 0, y = 0; x < n && y < n && r < k;) {
			b[x][y] = true;
			x += 2;
			y += 2;
			r++;
		}

		if (r < k) {cout << "-1" << endl;}
		else {
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < n; y++) {
					if (b[x][y]) {cout << "R";}
					else {cout << ".";}
				}
				cout << endl;
			}
		}
	}
}