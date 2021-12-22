#include<bits/stdc++.h>

using namespace std;

int main () {
	uint n, q; cin >> n >> q;
	uint arr[n]; for (uint i = 0; i < n; i++) {cin >> arr[i];}
	uint max_two_pow = (uint) log2(n) + 1; 

	uint sparse_table[max_two_pow + 1][n + 1]; //(i, j)th ele holds min of ranges [j, j+2^i]

	for (uint j = 0; j < n; j++) {
		sparse_table[0][j] = arr[j];
	}
	for (uint i = 1; i <= max_two_pow; i++) {
		for (uint j = 0; j + pow(2, i) - 1 < n; j++) {
			sparse_table[i][j] =
				min (
					sparse_table[i - 1][j], // [j, j + pow(2, i - 1) - 1]
					sparse_table[i - 1][j + (uint) pow(2, i - 1)] // [j + pow(2, i - 1), j + pow(2, i)]
				);
		}
	}
	#ifdef DEBUG
	for (uint i = 0; i <= n; i++) {printf(" %d           ", i);}
	cout << endl;
	for (uint i = 0; i <= max_two_pow; i++) {
		for (uint j = 0; j + pow(2, i) - 1 < n; j++) {
			printf ("(%d, %d): %d    ", j, j + (uint) pow(2, i) - 1, sparse_table[i][j]);
		}
		cout << endl;
	}
	#endif

	for (uint i = 0; i < q; i++) {
		uint start, end; cin >> start >> end; start--; end--; //0-based indexing
		uint k = 1;
		while (end - start + 1 > pow(2, k)) {k++;} k--;

		#ifdef DEBUG
		printf ("Two ranges to min from: [%d, %d], [%d, %d]\n",
			start, start + (uint) pow(2, k) - 1, end - (uint) pow(2, k) + 1, end);
		#endif

		cout << min (sparse_table[k][start], sparse_table[k][end - (uint) pow(2, k) + 1]) << endl;
	}
}