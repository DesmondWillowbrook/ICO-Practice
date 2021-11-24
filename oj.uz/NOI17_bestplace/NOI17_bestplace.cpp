#include <bits/stdc++.h>

using namespace std;

int main () {
	uint n; cin >> n;
	uint x[n], y[n];
	for (uint i = 0; i < n; i++) cin >> x[i] >> y[i];
	sort(x, x+n); sort(y, y+n);
	if (n % 2 != 0) printf("%d %d\n", x[n/2], y[n/2]);
	else printf ("%d %d\n", (x[(n/2)-1] + x[n/2])/2, (y[(n/2)-1] + y[n/2])/2);
}