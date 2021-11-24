#include<bits/stdc++.h>

using namespace std;

int main () {
	int n, x; cin >> n >> x;

	long int ans = 0;
	map<long int, long int> m = {
		{0, 1}
	};
	long long int pref = 0; int a;
	for (long int i = 0; i < n; i++) {
		cin >> a; pref += a;
		ans += m[pref - x];
		m[pref]++;
	}

	cout << ans << endl;
} 