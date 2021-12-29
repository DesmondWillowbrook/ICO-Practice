#include <bits/stdc++.h>

using namespace std;

int main () {
	int t; cin >> t;
	while (t--) {
		int n, m, rr, rc, dr, dc; cin >> n >> m >> rr >> rc >> dr >>dc;
		int rbot_r = 1, rbot_c = 1;
		int time = 0;
		while (dr != rr && dc != rc) {
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
			time++;
		}
		cout << time << endl;
	}
}