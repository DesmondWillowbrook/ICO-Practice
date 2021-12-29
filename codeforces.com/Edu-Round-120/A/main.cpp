#include<bits/stdc++.h>

using namespace std;

int main () {
	int t; cin >> t;
	while (t--) {
		int sticks[3];
		cin >> sticks[0] >> sticks[1] >> sticks[2];
		int a[3] = {0, 1, 2};

		bool broken = false;
		for (int i = 0; i < 3; i++) {
			if (sticks[a[0]] == sticks[a[1]] + sticks[a[2]] || (sticks[a[0]] % 2 == 0 && sticks[a[1]] == sticks[a[2]])) {
				#ifdef DEBUG
				printf ("Sticks are: %d, %d, %d\n", sticks[a[0]], sticks[a[1]], sticks[a[2]]);
				#endif
				cout << "YES" << endl;
				broken = true;
				break;
			}

			int last = a[2];
			for (int j = 1; j >= 0; j--) {a[j + 1] = a[j];}
			a[0] = last;
			#ifdef DEBUG
			printf ("Array after rotation: \n");
			for (int j = 0; j < 3; j++) {
				printf("%d: %d \n", a[j], sticks[a[j]]);
			}
			#endif
		}

		if (!broken) {
			cout << "NO" << endl;
		}
	}
}