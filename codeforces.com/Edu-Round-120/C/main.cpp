#include<bits/stdc++.h>

using namespace std;

#define rep(i, st, end) for (int i = st; i < end; i++)

int main () {
	int t; cin >> t;
	while (t--) {
		int n; long long int k; cin >> n >> k;
		int arr[n], prefix[n + 1];

		long long int total_sum = 0, curr_sum;
		cin >> arr[0]; prefix[0] = arr[0];
		rep (i, 1, n) {
			cin >> arr[i];
			prefix[i] = arr[i] + prefix[i - 1];
		}

		int steps = 0, set_steps = 0;
		curr_sum = total_sum;
		while (curr_sum > k) {
			curr_sum = total_sum - set_steps * arr[0] - steps;

			set_steps++;
			steps++; arr[0]--;
		}
		cout << set_steps + steps << endl;
	}
}