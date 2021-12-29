#include <bits/stdc++.h>

using namespace std;
const long int MOD = 1e9 + 7;

int main () {
	int t; cin >> t;
	while (t--) {
		int n, m, rr, rc, dr, dc, p; cin >> n >> m >> rr >> rc >> dr >> dc >> p;
		int rbot_r = 1, rbot_c = 1;
		int time = 0;
		
		int tries = 0;
		do {
			rr += rbot_r;
			rc += rbot_c;

			if (rr > n || rr < 0) {
				rbot_r = -rbot_r;
				if (rr > n) {rr = n - 1;}
				else {rr = 0;}
			}
			if (rc > m || rc < 0) {
				rbot_c = -rbot_c;
				if (rc > m) {rc = m - 1;}
				else {rc = 0;}
			}
			if (dr == rr || dc == rc) {
				tries++;
			}
			time += 1; time %= MOD;
		} while ((tries * p)/100 < 1);
		// we've found cycle time
		cout << time % MOD << endl;
	}
}