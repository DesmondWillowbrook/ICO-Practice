#include <bits/stdc++.h>

using namespace std;

int main () {
	size_t N, M; cin >> N >> M;
	vector<uint> adj_list[N];
	
	for (size_t i = 0; i < M; i++) {
		uint a, b; cin >> a >> b; a--; b--;
		adj_list[a].push_back(b); adj_list[b].push_back(a);
	}

	/* 
		iteratively go through all nodes to find critical ones
		critical can be defined as: without it,
		one will not be able to go from every node to every other node.

		Assertion: If there is reachability from node 0 to every other node
		(in undirected graph), then from every node we can go to every other node.

		We can find that out through BFS
	*/

	queue<uint> s; bool visited[N]; vector<uint> crits;

	for (uint node = 0; node < N; node++) {
		fill_n (visited, N, false); visited[node] = true; // keeps forbidden node from being visited
		s.push(abs( (int) node - 1)); // meant to push ANY node other than the forbidden one

		#ifdef DEBUG
		printf ("Testing reachability starting from node %d, when node %d is forbidden\n", s.front() + 1, node + 1);
		#endif

		while (!s.empty()) {
			uint src = s.front(); s.pop(); visited[src] = true;
			for (auto neighbour: adj_list[src]) {
				if (visited[neighbour]) continue;

				#ifdef DEBUG
				printf ("Adding neighbour node %d from src %d\n", neighbour + 1, src + 1);
				#endif

				s.push(neighbour);
				visited[neighbour] = true;
			}

			#ifdef DEBUG
			printf ("Visited node %d\n", src + 1);
			#endif
		}

		uint nodes_visited = 0; for (size_t i = 0; i < N; i++) if (visited[i]) nodes_visited++;
		#ifdef DEBUG
		printf ("Total nodes visited when node %d was forbidden: %d\n", node + 1, nodes_visited);
		#endif

		if (nodes_visited != N) crits.push_back (node);
	}

	cout << crits.size() << endl;
	for (size_t i = 0; i < crits.size(); i++) cout << crits[i] + 1 << endl;
}