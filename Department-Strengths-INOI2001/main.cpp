#include <bits/stdc++.h>

using namespace std;

const size_t MAX_N = 10e5;

vector<uint> emps [MAX_N]; //emps[i] contains all children of i

bool dept_head [MAX_N];
bool visited [MAX_N];

uint descendant_num (uint n) {
	uint ans = 0;

	for (uint child: emps[n]) {
		if (visited[child]) continue;

		visited[child] = true;
		ans++; // account for child being descendant as well
		ans += descendant_num(child);
	}

	return ans;
}

// marks all descendants of node as false
void mark_descendants (uint n) {
	visited[n] = true;

	for (uint child: emps[n]) {
		if (visited[child] == true) continue;

		dept_head[child] = false; visited[child] = true;
		mark_descendants (child);
	}
}

uint level_sum (uint n, int prev_lev) {
	int ans = prev_lev + 1;
	visited[n] = true;

	for (uint child: emps[n]) {
		if (visited[child] == true) continue;

		visited[child] = true;
		ans += level_sum (child, prev_lev + 1);
	}

	return ans;
}

uint max_id (uint n) {
	uint ans = n;
	for (uint child: emps[n]) {
		if (visited[child] == true) continue;

		visited[child] = true;
		ans = max (max_id(child), ans);
	}

	return ans;
}

uint min_id (uint n) {
	uint ans = n;
	for (uint child: emps[n]) {
		if (visited[child] == true) continue;

		visited[child] = true;
		ans = min (max_id(child), ans);
	}

	return ans;
}

int main () {
	long int T; cin >> T;

	while (T--) {
		size_t N, M; cin >> N >> M;

		for (size_t i = 0; i < N; i++) emps[i].clear();
		for (size_t i = 0; i < M; i++) {
			uint u, v; cin >> u >> v; u--; v--; emps[u].push_back(v); emps[v].push_back(u);
		}

		// figure out the managers
		fill_n (dept_head, N, true);
		for (size_t n = 0; n < N; n++) mark_descendants (n);
		fill_n (visited, N, false);
		// now nodes which are managers are the only ones marked true

		long int odd = 0, even = 0;
		for (size_t n = 0; n < N; n++)
			if (dept_head[n] == true) {
				uint desc_num = descendant_num(n);
				fill_n (visited, N, false);
				
				#ifdef DEBUG
				printf ("%ld identified as part of a new dept.\nnumber of descendants: %d\n", n + 1, desc_num);
				#endif

				if (desc_num % 2 == 0) {
					uint head = min_id(n);
					fill_n (visited, N, false);
					uint res = level_sum (head, 0);

					#ifdef DEBUG
					printf ("Strength of dept. is %d with head as: %d\n", res, head + 1);
					#endif

					even += res;
				} else {
					uint head = max_id(n);
					fill_n (visited, N, false);
					uint res = level_sum (head, 0);

					#ifdef DEBUG
					printf ("Strength of dept. is %d with head as: %d\n", res, head + 1);
					#endif

					odd += res;
				}

				fill_n (visited, N, false);
			}

		printf ("%ld %ld\n", even, odd);
	}
}