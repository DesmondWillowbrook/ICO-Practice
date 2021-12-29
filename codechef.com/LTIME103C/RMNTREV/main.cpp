#include <bits/stdc++.h>

using namespace std;

int position (int i, int k) {
	if (i > k) {return i;}
	return k - i;
}

void solve () {
	int n, k; cin >> n >> k; k--;
	string s; cin >> s;

	for (int i = 0; i < s.length(); i++) {
		int pos = 0;
		if (i >= k) {
			cout << s[i];
			continue;
		}
		if (k % 2 == 0) { //k - (k - 1) + (k - 2) - odd + - ... 0 +- i
			pos += (((k/2) + 1)*(0 + k))/2;
			#ifdef DEBUG
			printf ("Added even numbers (from 0 till %d): %d\n", k, (((k/2) + 1)*(0 + k))/2);
			#endif
			pos -= ((((k-1)/2) + 1)*(1 + (k-1)))/2;
			#ifdef DEBUG
			printf ("Subtracted odd numbers (from 1 till %d): %d\n", k - 1, ((((k-1)/2) + 1)*(1 + (k-1)))/2);
			#endif
			pos -= i;
		} else {
			pos -= ((((k-1)/2) + 1)*(0 + (k-1)))/2;
			pos += (((k/2) + 1)*(1 + k))/2;
			pos += i;
		}
		cout << s[pos];
		#ifdef DEBUG
		cout << endl;
		#endif
	}
	cout << endl;
}

int main () {
	uint t; cin >> t;
	while (t--) {
		solve();
	}
}