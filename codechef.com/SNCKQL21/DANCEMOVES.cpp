#include <bits/stdc++.h>

using namespace std;

int main () {
	long int t; cin >> t;
	int X, Y;
	int min_step;

	while (t--) {
		cin >> X >> Y;
		min_step = 0;

		while (X != Y) {
			if (X < Y) 	X += 2;
			else if (X > Y) X -= 1;
			min_step++;
		}

		cout << min_step << endl;
	}
}