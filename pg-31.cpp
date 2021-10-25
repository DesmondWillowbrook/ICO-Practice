#include <bits/stdc++.h>

using namespace std;

int main () {
	int ans = 0, curr = 0, n; cin >> n;
	
	int a[] = {-1, 2, 4, -3, 5, 2, -5, 2};
	for (int i = 0; i < n; i++) {cin >> a[i];}
	
	int temp_start = 0;
	pair<int, int> fin;

	for (int i = 0; i < n; i++) {
		if (curr < 0) {curr = 0; temp_start = i;}

		curr += a[i];
		if (ans < curr) {fin = {temp_start, i}; ans = curr;}
	}

	cout << fin.first << " " << fin.second << "\nMax:" << ans << endl;
}