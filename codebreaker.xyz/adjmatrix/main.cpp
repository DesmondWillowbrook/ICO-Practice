#include<bits/stdc++.h>

using namespace std;

int main () {
	int n, e; cin >> n >> e;
	int arr[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < e; i++) {
		int a, b; cin >> a >> b; a--; b--;
		arr[a][b] = 1; arr[b][a] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}