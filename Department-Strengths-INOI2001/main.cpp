#include <bits/stdc++.h>

using namespace std;

const size_t MAX_N = 10e6;

vector<uint> emps [MAX_N]; //emps[i] contains all children of i

bool visited [MAX_N], visited2[MAX_N];
uint min_e, max_e, num_e, strength;

void compute_strength (uint n, uint lvl) {
	visited2[n] = true;
	strength += lvl;

	for (uint child: emps[n])
		if (visited2[child] != true) compute_strength (child, lvl + 1);
}

void dfs (uint n) {
	visited[n] = true;
	num_e++; min_e = min (n, min_e); max_e = max (n, max_e);

	for (uint child: emps[n])
		if (visited[child] != true)	dfs(child);
}

int main () {
	long int T; cin >> T;

	while (T--) {
		size_t N, M; cin >> N >> M;

		for (size_t i = 0; i < N; i++) emps[i].clear();
		for (size_t i = 0; i < M; i++) {
			uint u, v; cin >> u >> v; u--; v--; emps[u].push_back(v); emps[v].push_back(u);
		}

		fill_n (visited, N, false); fill_n (visited2, N, false);

		long int odd = 0, even = 0;
		for (size_t n = 0; n < N; n++)
			if (visited[n] != true) {
				max_e = n; min_e = n; num_e = 0; strength = 0;
				dfs(n);

				if (num_e % 2 == 0) {
					compute_strength (min_e, 1);
					
					#ifdef DEBUG
					printf ("%d is head of dept. of %d people with strength %d\n", min_e + 1, num_e, strength);
					#endif
					
					even += strength;
				}
				else {
					compute_strength (max_e, 1);
										
					#ifdef DEBUG
					printf ("%d is head of dept. of %d people with strength %d\n", max_e + 1, num_e, strength);
					#endif
					
					odd += strength;
				}
			}

		printf ("%ld %ld\n", even, odd);
	}
}