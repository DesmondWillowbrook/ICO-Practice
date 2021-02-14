#include <bits/stdc++.h>

using namespace std;

int main () {
	size_t N; cin >> N;

	bool sieve[N + 1] = {false};

	sieve[1] = false;
	for (size_t i = 2; i < sqrt(N) + 1; i++) {
		for (size_t j = i * i; j <= N; j += i) {
			sieve[j] = true;
		}
	}

	for (size_t i = 1; i <= N; i++) {
		if (sieve[i] == false) printf ("%ld\n", i);
	}
}