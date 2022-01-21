#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, m; cin >> n >> m;
	int s[m];
	
	for (int i = 0; i < m; i++) {
		cin >> s[i];
	}
	sort(s, s + m);
	int ans = 0;
	for (int i = 0; i < m && n >= 0; i++) {
		n -= s[i];
		ans++;
	}
	if (n < 0) {ans--;}
	cout << ans << endl;
}