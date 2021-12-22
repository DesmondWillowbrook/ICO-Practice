#include<bits/stdc++.h>

using namespace std;

int main () {
	uint n, q; cin >> n >> q;
	uint prefix_sums[n + 1][n + 1];

	for (uint i = 0; i <= n; i++) {prefix_sums[i][0] = 0;}
	for (uint j = 0; j <= n; j++) {prefix_sums[0][j] = 0;}

	for (uint i = 1; i <= n; i++) {
		for (uint j = 1; j <= n; j++) {
			char temp;
			cin >> temp;
			if (temp == '*') {prefix_sums[i][j] = 1;}
			else {prefix_sums[i][j] = 0;}
			
			prefix_sums[i][j] += prefix_sums[i - 1][j];
			prefix_sums[i][j] += prefix_sums[i][j - 1];
			prefix_sums[i][j] -= prefix_sums[i - 1][j - 1];
		}
	}

	#ifdef DEBUG
	printf ("    ");
	for (uint i = 0; i <= n; i++) {printf("%d  ", i);}
	cout << endl;
	printf ("    ");
	for (uint i = 0; i <= n; i++) {printf("_  ");}
	cout << endl;
	for (uint i = 0; i <= n; i++) {
		printf ("%d | ", i);
		for (uint j = 0; j <= n; j++) {
			printf ("%d  ", prefix_sums[i][j]);
		}
		cout << endl;
	}
	#endif

	for (uint i = 0; i < q; i++) {
		uint s_y, s_x, e_y, e_x; cin >> s_y >> s_x >> e_y >> e_x;

		#ifdef DEBUG
		printf ("(%d, %d) -> (%d, %d) = %d + %d - %d - %d\n",
			s_x, s_y, e_x, e_y, prefix_sums[e_x][e_y],
			prefix_sums[s_x - 1][s_y - 1],
			prefix_sums[e_x][s_y - 1], prefix_sums[s_x - 1][e_y]);
		#endif

		cout << prefix_sums[e_y][e_x]
			+ prefix_sums[s_y - 1][s_x - 1]
			- prefix_sums[s_y - 1][e_x]
			- prefix_sums[e_y][s_x - 1]
		<< endl;
	}
}