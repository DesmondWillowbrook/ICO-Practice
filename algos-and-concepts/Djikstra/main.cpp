#include<bits/stdc++.h>

using namespace std;

/*
First two numbers: Number of nodes (N), number of edges (M)
Next 3*M numbers: Node A, Node B, Weight of edge
Last two numbers: Src node and Dest node
Print -1 if no path found
*/

size_t N, M;

#ifdef DEBUG
void print_dists (uint dist[]) {
    cout << "Nodes\t\tDistance\n";
    for (size_t i = 0; i < N; i++) {
        cout << i + 1 << "\t\t" << dist[i] << "\n";
    }
    cout << endl;
}
#endif

int main () {
    cin >> N >> M;
    vector<pair<uint, uint>> edges [N];

    for (size_t i = 0; i < M; i++) {
        uint a, b, w; cin >> a >> b >> w; a--; b--;
        edges[a].push_back ({w, b}); edges[b].push_back ({w, a});
    }
    uint src, dest; cin >> src >> dest; src--; dest--;

    uint dist[N]; fill_n (dist, N, UINT_MAX); dist[src] = 0;
    priority_queue<pair<uint, uint>> q; q.push ({0, src});

    while (!q.empty()) {
        pair<uint, uint> s = q.top(); q.pop();

        #ifdef DEBUG
        printf ("Evaluating distances from node %d\n", s.second + 1);
        #endif

        for (auto node: edges[s.second]) {
            if (dist[s.second] + node.first < dist[node.second]) {
                dist[node.second] = dist[s.second] + node.first;
                q.push ({dist[node.second], node.second});
            }
        }

        #ifdef DEBUG
        print_dists (dist);
        #endif
    }

    if (dist[dest] != UINT_MAX) cout << dist[dest] << endl;
    else cout << "-1" << endl;
}