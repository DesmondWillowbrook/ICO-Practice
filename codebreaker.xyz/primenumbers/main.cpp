#include<bits/stdc++.h>

using namespace std;

int main () {
	int n; cin >> n;
	if (n == 1 || n == 0) {cout << "Not Prime" << endl;}
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			cout << "Not Prime" << endl;
			return 0;
		}
	}
	cout << "Prime" << endl;
}