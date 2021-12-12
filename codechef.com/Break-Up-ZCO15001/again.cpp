#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int is_palin[300][300] = {0};
bool dp_is_palindrome (int* arr, int start, int end) {
	if (is_palin[start][end] != 0) {
		return is_palin[start][end] == 2 ? true : false;
	}

	if (start + 1 < end - 1) {
		is_palin[start][end] = (arr[start] == arr[end] && dp_is_palindrome(arr, start + 1, end - 1)) ? 2 : 1;
	} else {
		is_palin[start][end] = (arr[start] == arr[end]) ? 2 : 1;
	}
	return is_palin[start][end] == 2 ? true : false;
}

int main () {
	int n; cin >> n;
	int arr[n + 1], min_vals[n + 1] = {0};

	min_vals[0] = 0; // zeroeth index of min_vals => no elements
	for (int i = 1; i <= n; i++) {cin >> arr[i]; min_vals[i] = i;}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			// (i, j) range is inclusive and idx starts at 1
			if (dp_is_palindrome(arr, j, i)) {
				#ifdef DEBUG
				printf ("Palindrome discovered at (%d, %d)\n", j, i);

				if (min_vals[i] > 1 + min_vals[j - 1]) {
					printf ("Min sections formed before %d are: %d\n", j, min_vals[j - 1]);
					printf ("Current min section at %d is %d. New min section (1 + min_val[%d]) = %d\n", i, min_vals[i], j - 1, 1 +min_vals[j - 1]);
				}
				#endif

				min_vals[i] = min(min_vals[i], 1 + min_vals[j - 1]);
			}
		}
	}
	cout << min_vals[n] << endl;
}