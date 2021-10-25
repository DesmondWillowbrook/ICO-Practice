#include<bits/stdc++.h>

using namespace std;

int main () {
	long int t; cin >> t;
	long long int N, K, matches_won;

	while (t--) {
		cin >> N >> K;
		matches_won = (N - K); // all teams below rank K score 0, thus N-K matches won
		matches_won += (K-1)/2; // half of all matches with teams above rank K are won
		                          // if odd number, then lose more than win.
		cout << 2*matches_won << endl;
	}
}