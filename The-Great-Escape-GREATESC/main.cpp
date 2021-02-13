#include <bits/stdc++.h>

using namespace std;

int main () {
	size_t N, M; cin >> N >> M;
	vector<uint> edges[N];

	for (size_t i = 0; i < M; i++) {
		uint a, b; cin >> a >> b; a--; b--;
		edges[a].push_back(b); edges[b].push_back(a);
	}
	uint S, T; cin >> S >> T; S--; T--;

	queue<uint> to_visit; // for BFS
	to_visit.push (S);

	uint dist[N];
	fill_n (dist, N, UINT_MAX); dist[S] = 0;

	while (!to_visit.empty()) {
		uint src = to_visit.front(); to_visit.pop();
		#ifdef DEBUG
		printf ("Evaluating paths with node %d\n", src);
		#endif

		for (auto node: edges[src]) {
			if (dist[node] > dist[src] + 1) {
				#ifdef DEBUG
				printf ("Relaxing %d to %d with help of node %d\n", node, dist[src] + 1, src);
				#endif

				dist[node] = dist[src] + 1;
				to_visit.push(node);
			}
		}
	}

	if (dist[T] == UINT_MAX) cout << "0" << endl;
	else cout << dist[T] << endl;
}