#include<bits/stdc++.h>

using namespace std;

#ifdef DEBUG
void preview_array (int** arr, int a, int b) {
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			printf ("%d ", arr[i][j]);
		}
		cout << endl;
	}
}
#endif

int main () {
	int r, c; cin >> r >> c;
	
	int time = 1;
	int arr[510][r][c];

	for (int i = 0; i <= r; i++) {
		#ifdef DEBUG
		printf ("Assigning %d %d as %d\n", i, 0, 0);
		#endif
		arr[1][i][0] = 0;
	}
	for (int i = 0; i <= c; i++) {
		#ifdef DEBUG
		printf ("Assigning %d %d as %d\n", 0, i, 0);
		#endif
		arr[1][0][i] = 0;
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			int a, b;
			cin >> a >> b;
			arr[1][a][b] = time;
			#ifdef DEBUG
			printf ("Assigning %d %d as %d\n", a, b, time);
			#endif
			time++;
		}
	}

	int ans[510]; fill_n(ans, 509, INT_MAX); ans[1] = 1;

	for (int l = 2; l < min(l, r) + 1; l++) {
		for (int i = l; i <= r; i++) {
			for (int j = l;	j <= c; j++) {
				arr[l][i][j] = max(arr[l - 1][i - 1][j], max(arr[l - 1][i][j - 1], arr[1][i][j]));
				ans[l] = min(ans[l], arr[l][i][j]);
			}
		}
	}

	#ifdef DEBUG
	for (int l = 1; l < min(l, r) + 1; l++) {
		for (int i = l; i <= r; i++) {
			for (int j = l; j <= r; j++) {
				printf ("%d ", arr[l][i][j]);
			}
			cout << endl;
		}
		cout << endl;
	}
	#endif

	for (int time = 1, l = 1; time <= r*c; time++) {
		while (time > ans[l] && ans[l] != INT_MAX) {
			l++;
		}
		if (time < ans[l] || ans[l] == INT_MAX) {l--;}
		printf ("%d\n", ans[l]);
	}
}