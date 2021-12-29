#include<bits/stdc++.h>

using namespace std;

int main () {
	int t; cin >> t;
	while (t--) {
		int n; long int k; cin >> n >> k;
		int arr[n];

		long int curr_sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			curr_sum += arr[i];
		}

		if (curr_sum <= k) {
			cout << 0 << endl;
			continue;
		}
		sort(arr, arr + n);

		#ifdef DEBUG
		int debug_array[n];
		memcpy(debug_array, arr, sizeof(int) * n);
		#endif

		bool broken = false;
		int ind = n - 1;

		int steps = 0;
		while (curr_sum > k) {
			if ((ind == 0 || arr[ind] == arr[0]) || curr_sum - max(1, n + ind - 1) < curr_sum - arr[ind] - arr[0]) {
				curr_sum -= max(1, n + ind - 1); // amount of elements affected if we decrement arr[0] by 1
				#ifdef DEBUG
				for (int i = n - 1; i >= ind; i--) {
					debug_array[i]--;
				}
				printf ("Excercised collective to lower to %ld\n", curr_sum);
				#endif
			} else {
				curr_sum -= arr[ind] - arr[0];
				#ifdef DEBUG
				arr[ind] = arr[0];
				#endif
				printf ("Extended collective -= to %d; sum now %ld\n", n - ind, curr_sum);	
				ind--;
			}

			#ifdef DEBUG
			for (int i = 0; i < n; i++) {cout << debug_array[i] << " ";}
			cout << endl;
			#endif

			steps++;
		}
		cout << steps << endl;
	}
}