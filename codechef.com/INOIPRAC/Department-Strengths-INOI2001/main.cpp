#include <bits/stdc++.h>

using namespace std;

const size_t MAX_N = 1e5 + 100;

vector<uint> emps [MAX_N]; //emps[i] contains all children of i

bool visited [MAX_N], visited_calc_str[MAX_N];
uint min_e, max_e, num_e, strength;

void compute_strength (uint n, uint lvl) {
	visited_calc_str[n] = true;
	strength += lvl;

	for (uint child: emps[n])
		if (!visited_calc_str[child]) compute_strength (child, lvl + 1);
}

void dfs (uint n) {
	visited[n] = true;
	num_e++; min_e = min (n, min_e); max_e = max (n, max_e);

	for (uint child: emps[n])
		if (!visited[child]) dfs(child);
}

int main () {
	long int T; cin >> T;

	while (T--) {
		size_t N, M; scanf ("%ld %ld", &N, &M);

		for (size_t i = 0; i < N; i++) emps[i].clear();
		fill_n (visited, N, false); fill_n (visited_calc_str, N, false);

		for (size_t i = 0; i < M; i++) {
			uint u, v; scanf("%d %d", &u, &v); u--; v--; emps[u].push_back(v); emps[v].push_back(u);
		}

		long long odd = 0, even = 0;
		for (size_t n = 0; n < N; n++)
			if (!visited[n]) {
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

		printf ("%lld %lld\n", even, odd);
	}
}