#include <bits/stdc++.h>

using namespace std;

const size_t MAX_N = 1e6;

vector<uint> edge[MAX_N];
bool visited[MAX_N];

long int size;
int max_n, min_n;

// if called on an already visited node, WILL OVERCOUNT
// I should probably add a statement at the starting to prevent that.
// if (visited[u]) {return 0;}
// Ooh, I wrote it, but I'm not going to paste it in.
// because of perceived probably-untrue untested notions on performance
long int level_sum (int u, int lvl) {
	long int ans = lvl;
	visited[u] = true;

	for (uint n: edge[u]) {
		if (!visited[n]) {ans += level_sum(n, lvl + 1);}
	}
	return ans;
}

void min_max_size (int curr) {
	size++;
	visited[curr] = true;
	min_n = min(curr, min_n);
	max_n = max(curr, max_n);

	for (uint n: edge[curr]) {
		if (!visited[n]) {
			min_max_size (n);
		}
	}

	#ifdef DEBUG
	printf ("Current node: %d, Min node: %d, Max node: %d, Size: %ld\n", curr, min_n, max_n, size);
	#endif
}

/*
we're given undirected edges (but manager-manegerial relations aren't two way)
one thing we're sure about is that a route from an employee below A to an employee above A must go through A.
=> Start with first employee not already visited, run a search through all edges and grofit.
*/

int main () {
	uint t; cin >> t;
	while (t--) {
		uint n, m; cin >> n >> m; 
		for (uint i = 1; i <= n; i++) {edge[i].clear();}

		for (uint i = 1; i <= m; i++) {
			uint u, v; cin >> u >> v;
			edge[u].push_back(v); edge[v].push_back(u);
		}

		vector<uint> even, odd;
		fill_n(visited, n + 1, false);
		
		for (uint i = 1; i <= n; i++) {
			if (!visited[i]) {
				min_n = i; max_n = i; size = 0;
				min_max_size(i);

				if (size % 2 == 0) {
					#ifdef DEBUG
					printf ("Even dept head is %d, size of dept is %ld\n", min_n, size);
					#endif

					even.push_back(min_n);
				} else {
					#ifdef DEBUG
					printf ("Odd dept head is %d, size of dept is %ld\n", max_n, size);
					#endif

					odd.push_back(max_n);
				}
			}
		}

		fill_n(visited, n + 1, false);
		int even_str = 0, odd_str = 0;
		for (auto n: even) {
			long int str = level_sum(n, 1);
			#ifdef DEBUG
			printf ("Dept strength of %d is %ld\n", n, str);
			#endif
			even_str += str;
		}
		for (auto n: odd) {
			long int str = level_sum(n, 1);
			#ifdef DEBUG
			printf ("Dept strength of %d is %ld\n", n, str);
			#endif
			odd_str += str;
		}

		printf ("%ld %ld\n", even_str, odd_str);
	}
}