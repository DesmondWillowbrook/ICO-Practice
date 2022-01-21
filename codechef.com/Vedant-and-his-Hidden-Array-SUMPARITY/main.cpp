#include <bits/stdc++.h>

using namespace std;

int main () {
	int t; cin >> t;
	while (t--) {
		int n, a; cin >> n >> a;
		//handle special case of one element
		if (n == 1) {cout << ((a & 1) ? "Odd" : "Even") << endl;}

		// Bitwise & of N bits = 1
		// 		=> if N even => sum is even (1*N % 2 == 0)
		//		=> if N odd => sum is odd (1*N % 2 == 1)
		// Bitwise & of N bits = 0
		// impossible in cases where N >= 2
		// as there could be any number of ones, even or odd
		else if ((a & 1) == 1) {
			if (n % 2 == 0) {
				cout << "Even" << endl;
			} else {
				cout << "Odd" << endl;
			}
		} else {
			cout << "Impossible" << endl;
		}
	}
}