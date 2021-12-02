#include <bits/stdc++.h>

using namespace std;

int main () {
	int n; cin >> n;
	int candidates[n][5];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> candidates[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = i + 1; k < n; k++) {
				int strength = INT_MAX;
				for (int l = 0; l < 5; l++) {
					strength = min (strength, max(candidates[i][l], max(candidates[j][l], candidates[k][l])));
				}
				ans = max (ans, strength);
			}
		}
	}
	cout << ans << endl;
}