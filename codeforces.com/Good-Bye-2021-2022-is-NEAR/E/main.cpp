#include <bits/stdc++.h>

using namespace std;

enum comp_result {
	LESSER,
	EQUAL,
	GREATER,
};

enum comp_result comp (char* a, int n, char* b, int m) {
	for (int i = 0; i < min(n, m); i++) {
		if (a[i] > b[i]) {return GREATER;}
		else if (a[i] < b[i]) {return LESSER;}
	}

	if (n < m) {return LESSER;} //a is prefix
	if (n > m) {return GREATER;} //b is prefix
	return EQUAL;
}

#ifdef DEBUG
void print_string (char* s, int n) {
	for (int i = 0; i < n; i++) {printf ("%c", s[i]);}
	cout << endl;
}
#endif

int main () {
	int q; cin >> q;
	while (q--) {
		int n; cin >> n; char s[n], t[n];
		for (int i = 0; i < n; i++) {cin >> s[i];}
		for (int i = 0; i < n; i++) {cin >> t[i];}

		int operations = 0;

		if (comp(s, n, t, n) == LESSER) {
			goto end;
		}

		for (int j = 0; j <= n; j++) {
			for (int i = 0; i < n - 1; i++) {
				if (s[i] < t[i]) {continue;}
				if (comp(s + i, n - i, t + i, n - i) == LESSER) {break;}

				if (s[i] > s[i + 1]) {
					char temp = s[i]; 
					s[i] = s[i + 1];
					s[i + 1] = temp;

					#ifdef DEBUG
					printf ("Swapped %c (%d) with %c (%d)\nString now is: ", s[i], i, s[i + 1], i + 1);
					print_string(s, n);
					#endif

					operations++;
					break;
				}
			}
		}

		end:

		if (comp(s, n, t, n) == LESSER) {
			cout << operations << endl;
		} else {
			cout << -1 << endl;
		}
	}
}