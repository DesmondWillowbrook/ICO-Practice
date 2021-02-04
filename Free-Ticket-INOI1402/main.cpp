#include<bits/stdc++.h>

using namespace std;

int main () {
    size_t cities, edges;
    cin >> cities >> edges;

    vector<pair<uint, uint>> adj_list[cities];
    for (size_t i = 0; i < edges; i++) {
        uint a, b, weight;
        cin >> a >> b >> weight; a--; b--; // move to zero-based indexing
        adj_list[a].push_back({weight, b});
        adj_list[b].push_back({weight, a});
    }

    uint ans = 0;
    uint distance[cities]; //bool visited[cities];
    priority_queue<pair<uint, uint>> unvisited;

    /* run Djikstra on every node to find cheapest
       max. dist. from all node pairs
       We could've used Floyd-Warshall as well.
    */
    for (size_t src = 0; src < cities; src++) {
        unvisited.push({0, src});
        fill_n(distance, cities, INT_MAX);
        distance[src] = 0;
        //fill_n (visited, cities, false);

        while (!unvisited.empty()) {
            int node = unvisited.top().second; unvisited.pop(); //visited[node] = true;
            int dist = distance[node];

            for (auto ele: adj_list[node]) {
                if (distance[ele.second] > dist + ele.first) {
                    distance[ele.second] = dist + ele.first;
                    unvisited.push({distance[ele.second], ele.second});
                }
            }
        }

        for (auto ele: distance) ans = max(ans, ele);
    }

    cout << ans << endl;
}