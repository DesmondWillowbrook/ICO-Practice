#include<bits/stdc++.h>

using namespace std;

int main () {
	long int t, n; cin >> t;
	while (t--) {
		scanf("%ld", &n);
		if (n == 1) printf ("1\n");
		else if (n == 2) printf ("1\n");
		else if (n == 3) printf ("3\n");
		else printf("%ld\n", (1 + ((n-2)*(2*(n-1)))/2));
	}	
	fflush(stdin);
}