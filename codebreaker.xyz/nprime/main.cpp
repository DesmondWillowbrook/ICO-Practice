#include<bits/stdc++.h>

using namespace std;

int main () {
	long unsigned int n; cin >> n;
	vector<int> primes; primes.reserve(n);
	primes.push_back(2);

	int curr = 3;
	while (primes.size() < n) {
		bool prime = true;
		for (long unsigned int i = 0;
			i < primes.size() && primes[i] <= sqrt(curr);
			i++)
		{
			if (curr % primes[i] == 0) {
				prime = false;
				break;
			}
		}

		if (prime) {primes.push_back(curr);}
		curr++;
	}
	cout << primes.back() << endl;
}