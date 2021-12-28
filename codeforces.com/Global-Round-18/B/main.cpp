#include<bits/stdc++.h>
 
using namespace std;
int one_occurence[200050][18];

int main () {
	int t; cin >> t;
 
	for (int i = 0; i < 18; i++) {one_occurence[0][i] = 0;}
	for (int i = 1; i <= 200000; i++) {
		for (int idx = 0; idx < 18; idx++) {
			one_occurence[i][idx] = one_occurence[i-1][idx];
			if ((i >> idx) & 1) {
				one_occurence[i][idx]++;
			}
		}
	}
 
	while (t--) {
		int l, r, ans = 0; cin >> l >> r;
		for (int idx = 0; idx < 18; idx++) {
			#ifdef DEBUG
			printf ("Number of 1's at index %d: %d\n", idx, one_occurence[r][idx] - one_occurence[l - 1][idx]);
			#endif
			ans = max(ans, one_occurence[r][idx] - one_occurence[l - 1][idx]);
		}
		#ifdef DEBUG
		printf ("Max 1 bits are %d, Total bits in range are %d, therefore answer is %d\n", ans, (r - l + 1), (r - l + 1) - ans);
		#endif
		cout << ((r - l + 1) - ans) << endl;
	}
}