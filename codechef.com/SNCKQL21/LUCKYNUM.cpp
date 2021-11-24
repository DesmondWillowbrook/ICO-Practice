#include <bits/stdc++.h>

using namespace std;

uint num[3];
void run () {
	for (uint i = 0; i < 3; i++) {
        	cin >> num[i];
	}
	for (uint i = 0; i < 3; i++) {
        	if (num[i] == 7) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main() {
	int t; cin >> t;
	while (t--) run();
	cout << endl;
}
