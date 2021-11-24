#include<bits/stdc++.h>

using namespace std;

bool solve (long int N, long int K, long long int flip_num) {
	if (K < 0 || flip_num >= N) return;
	if (K - flip_num == 0) {cout << "YES" << endl; return;}

	solve(N, K + flip_num, flip_num*2);
	solve(N, K - flip_num, flip_num*2);
}

int main () {
	long int t; cin >> t;
	while (t--) {
		long int N, K; cin >> N >> K;
		if (K == 0) {cout << "YES" << endl; continue;}
		solve(N, K, 1);
	}
}