#include<bits/stdc++.h>

using namespace std;

int main () {
	int n; cin >> n;
	char cows[n];

	for (uint i = 0; i < n; i++) {
		cin >> cows[i];
	}

	long long int ans = 0;
	for (int i = 0; i < n; i++) {
		int left = 0, right = 0;
		for (int lind = i - 1; lind >= 0 && cows[lind] != cows[i]; lind--) {left++;}
		for (int rind = i + 1; rind < n && cows[rind] != cows[i]; rind++) {right++;}

		#ifdef DEBUG
		printf ("Window around %c (at %d) is (%d, %d)\n", cows[i], i, i - left, i + right);
		#endif

		ans += ((long long int) left)*((long long int) right) + max(0, right - 1) + max(0, left - 1);
	}

	cout << ans << endl;
}