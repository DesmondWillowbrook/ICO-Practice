#include<bits/stdc++.h>

using namespace std;

bool haybales[50][50];
int n, k;

long long int walk (int x, int y, int turns, bool prev) {
	if (turns > k || x >= n || y >= n || haybales[x][y]) return 0;
	if (x == n - 1 && y == n - 1) return 1;

	#ifdef DEBUG
	printf ("%d %d %d %d\n", x, y, turns, prev);
	#endif

	long long int ans = 0;

	//prev dir was x 
	if (prev) { 
		return walk(x + 1, y, turns, prev) + walk(x, y + 1, turns + 1, !prev);
	} else {
		return walk(x, y + 1, turns, prev) + walk(x + 1, y, turns + 1, !prev);
	}
}

int main () {
	uint t; cin >> t;
	while (t--) {
		cin >> n >> k;
		for (uint i = 0; i < n; i++) {
			for (uint j = 0; j < n; j++) {
				char temp; cin >> temp;
				if (temp == '.') {haybales[i][j] = false;}
				else if (temp == 'H') {haybales[i][j] = true;}
				else {printf ("Unknown character encountered: %d\n", temp);}
			}
		}

		cout << walk (1, 0, 0, true) + walk(0, 1, 0, false) << endl;
	}
}