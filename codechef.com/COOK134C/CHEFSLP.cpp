#include<bits/stdc++.h>

using namespace std;

int main () {
	int t, N, L, X; cin >> t;
	while (t--) {
		cin >> N >> L >> X;
		cout << min(N-L, L)*X << endl;
	}
}