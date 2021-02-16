#include <bits/stdc++.h>

using namespace std;

int main () {
	size_t N; cin >> N;
	long int a[N], b[N];
	for (size_t i = 0; i < N; i++) cin >> a[i];
	for (size_t i = 0; i < N; i++) cin >> b[i];

	/*
	Observation: Question is split into three cases:
	Case 1: i < j: Then, SSum (i, j) = a[i] + (b_sum_till[j - 1] - b_sum_till[i]) + a[j]
	Case 2: i > j: SSum (i, j) = a[i] + ((b_sum_till[N] - b_sum_till[i]) + b_sum_till[j - 1]) + a[j]
	Case 3: i = j: SSum (i, j) = a[i]

	If we separate i, j dependant parts in Case 1, 2, then we come up with:
	Case 1: i < j: SSum (i, j) = (a[i] - b_sum_till[i]) + (b_sum_till[j - 1] + a[j])
	We can memoize best i upto given number, since best I for j + 1 = max (best_for_j, a[i] - b_sum_till[i])

	Similarly for case 2.
	Case 2: i > j: SSum (i, j) = a[i] - b_sum_till[i] + b_sum_till[N] + b_sum_till[j - 1] + a[j]

	We can use same DP array for both cases.
	Case 3 can be handled trivially.
	*/

	// set up B_Sum_Till arr
	long long int b_sum_till[N] = {b[0]}; // fill first element of b_sum_till with first element of b
	for (size_t i = 1; i < N; i++) b_sum_till[i] = b_sum_till[i - 1] + b[i];

	// set up best I till index, best I till index (in reverse, required for Case 2 (since i MUST be greater than j))
	long long int best_i_fw[N + 1], best_i_bw[N + 1], ans = 0;
	best_i_fw[0] = a[0] - b_sum_till[0]; best_i_bw[N - 1] = a[N - 1] + b_sum_till[N - 1];
	
	for (size_t i = 1; i < N; i++) best_i_fw[i] = max(best_i_fw[i - 1], a[i] - b_sum_till[i]);
	for (long int i = N - 2; i >= 0; i++) best_i_bw[i] = max (best_i_bw[i + 1], a[i] - b_sum_till[i]);

	for (size_t j = 1; j < N; j++) {
		// Case 1
		ans = max (ans, a[j] + b_sum_till[j - 1] + best_i_fw[j - 1]);

		#ifdef DEBUG
		printf ("j = %ld: Case 1: %ld (a[%ld]) + %lld (b_sum_till[%ld] + %lld (best_i_fw[%ld])\n",
			j, a[j], j, b_sum_till[j - 1], j - 1, best_i_fw[j - 1], j - 1);
		#endif

		// Case 2
		ans = max (ans, a[j] + b_sum_till[j - 1] + b_sum_till[N - 1] + best_i_bw[j -1]);

		#ifdef DEBUG
		printf ("j = %ld: Case 2: %ld (a[%ld]) + %lld (b_sum_till[%ld] + %lld (b_sum_till[%ld]) + %lld (best_i_fw[%ld])\n",
			j, a[j], j, b_sum_till[j - 1], j - 1, b_sum_till[N - 1], N - 1, best_i_fw[j - 1], j - 1);
		#endif

		// Case 3
		ans = max (ans, (long long int) a[j]);

		#ifdef DEBUG
		printf ("j = %ld: Case 3: %ld\n\n", j, a[j]);
		#endif
	}

	cout << ans << endl;
}