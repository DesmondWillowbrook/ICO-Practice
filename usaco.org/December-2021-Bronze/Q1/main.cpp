#include<bits/stdc++.h>

using namespace std;

int main () {
	uint n; cin >> n;
	uint g_count[n + 1] = {0}, h_count[n + 1] = {0};

	for (uint i = 1; i <= n; i++) {
		char temp; cin >> temp;

		g_count[i] = g_count[i - 1];
		h_count[i] = h_count[i - 1];
		if (temp == 'G') {
			g_count[i] += 1;
		} else if (temp == 'H') {
			h_count[i] += 1;
		}

		#ifdef DEBUG
		printf("%c: %d\t%d\n", temp, g_count[i], h_count[i]);
		#endif
	}

	uint ans = 0;
	for (int i = 3; i <= n; i++) {
		for (int j = 0; j <= i - 3; j++) {
			if (g_count[i] - g_count[j] == 1 || h_count[i] - h_count[j] == 1) {
				#ifdef DEBUG
				printf ("Lonely region: (%d, %d); %d Gs and %d Hs\n",
					j, i, g_count[i] - g_count[j], h_count[i] - h_count[j]);
				#endif
				// lonely cow
				ans++;
			}
		}
	}
	cout << ans << endl;
}