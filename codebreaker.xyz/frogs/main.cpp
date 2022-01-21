#include <bits/stdc++.h>

using namespace std;

/*
here's an idea for if frog num was quite large
iterate through mosquito placements,
sort frog list (store indices in secondary element in pair)
find factors of mosquito position;
bin search for factors in frog intervals.
what would be the time complexity?
number of factors of N: combinatorial problem over
prime factors of N; number of prime factors of N
is unpredictable (since it means testing N with all prime numbers until sqrt(N))
ah, this would be a FUN problem
*/

int main () {
	int n, m, k; cin >> n >> m >> k;
	int frog_len[m], mosquito_hill[k];
	for (int i = 0; i < m; i++) {
		cin >> frog_len[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> mosquito_hill[i];
	}
	int frog_kills[m]; fill(frog_kills, frog_kills + m, 0);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < m; j++) {
			if (mosquito_hill[i] % frog_len[j] == 0) {
				#ifdef DEBUG
				printf ("Frog with interval %d will kill mosquito on hill %d\n", frog_len[j], mosquito_hill[i]);
				#endif
				frog_kills[j] += 1;
			}
		}
	}
	#ifdef DEBUG
	for (int i = 0; i < m; i++) {
		printf("%d ", frog_len[i]);
	} cout << endl;
	for (int i = 0; i < k; i++) {
		printf("%d ", mosquito_hill[i]);
	} cout << endl;
	for (int i = 0; i < m; i++) {
		printf("%d ", frog_kills[i]);
	} cout << endl;
	#endif
	int min_frog_kills = INT_MAX;
	for (int i = 0; i < m; i++) {
		min_frog_kills = min(min_frog_kills, frog_kills[i]);
	}
	vector<int> frogs_with_least_kills;
	for (int i = 0; i < m; i++) {
		if (min_frog_kills == frog_kills[i]) {
			frogs_with_least_kills.push_back(i + 1);
		}
	}
	sort (frogs_with_least_kills.begin(), frogs_with_least_kills.end());
	cout << frogs_with_least_kills.size() << endl;
	for (unsigned long int i = 0; i < frogs_with_least_kills.size(); i++) {
		cout << frogs_with_least_kills[i] << " ";
	}
	cout << endl;

}