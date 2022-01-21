#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, k; cin >> n >> k;
	int tree_cost[n];
	for (int i = 0; i < n; i++) {
		cin >> tree_cost[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j >= 0 && i - j < k; j--) {
			#ifdef DEBUG
			printf ("Checking %d to %d\n", j, i);
			#endif
			sum += tree_cost[j];
			ans = max(ans, sum);
		}
	}
	cout << ans << endl;
}

/*
on later reading, the problem only has POSITIVE integers
i.e. this is slight modification of maximum array segment sum 
*/