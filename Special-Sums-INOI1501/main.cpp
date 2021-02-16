#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main () {
	size_t N; cin >> N;
	ll a[N + 1], b[N + 1]; // one-based indexing

	for (size_t i = 1; i <= N; i++) cin >> a[i];
	for (size_t i = 1; i <= N; i++) cin >> b[i];

	ll b_sum_till[N + 1] = {0};
	for (size_t i = 1; i <= N; i++) b_sum_till[i] = b_sum_till[i - 1] + b[i];

	ll max_i_sum_fw[N + 1]; ll max_i_sum_bw[N + 2];
	max_i_sum_fw[0] = -90000000000000000 /*Not too close to the limit, protect from overflow*/;
	max_i_sum_bw[N + 1] = max_i_sum_bw[N] = a[N] - b_sum_till[N];

	for (size_t i = 1; i <= N; i++) max_i_sum_fw[i] = max (max_i_sum_fw[i - 1], a[i] - b_sum_till[i]);
	for (ll i = N - 1; i >= 0; i--) max_i_sum_bw[i] = max (max_i_sum_bw[i + 1], a[i] - b_sum_till[i]);

	#ifdef DEBUG
	for (size_t i = 1; i <= N; i++) cout << i << "\t";
	cout << endl;
	for (size_t i = 1; i <= N; i++) cout << b_sum_till[i] << "\t";
	cout << endl; 
	for (size_t i = 1; i <= N; i++) cout << max_i_sum_fw[i] << "\t";
	cout << endl; 
	for (size_t i = 1; i <= N; i++) cout << max_i_sum_bw[i] << "\t";
	cout << endl; 
	#endif

	ll ans = LONG_LONG_MIN;
	for (size_t j = 1; j <= N; j++) {
		#ifdef DEBUG
		printf ("j: %ld\n", j);
		#endif

		// Case 1
		ans = max (ans, a[j] + b_sum_till[j - 1] + max_i_sum_fw[j - 1]);

		#ifdef DEBUG
		printf ("Case 1: a[j] (%lld) + b_sum_till[j - 1] (%lld) + max_i_sum_fw[j - 1] (%lld) = %lld\n",
			a[j], b_sum_till[j - 1], max_i_sum_fw[j - 1], a[j] + b_sum_till[j - 1] + max_i_sum_fw[j - 1]);
		#endif

		// Case 2
		if (j < N) ans = max (ans, a[j] + b_sum_till[N] + b_sum_till[j - 1] + max_i_sum_bw[j + 1]);

		#ifdef DEBUG
		if (j < N) printf ("Case 2: a[j] (%lld) + b_sum_till[N] (%lld) + b_sum_till[j - 1] (%lld) + max_i_sum_bw[j + 1] (%lld) = %lld\n",
			a[j], b_sum_till[N], b_sum_till[j - 1], max_i_sum_bw[j + 1], a[j] + b_sum_till[N] + b_sum_till[j - 1] + max_i_sum_bw[j + 1]);
		#endif

		// Case 3
		ans = max (ans, a[j]);
		#ifdef DEBUG
		printf ("Case 3: %lld\n", a[j]);
		#endif
	}

	cout << ans << endl;
}