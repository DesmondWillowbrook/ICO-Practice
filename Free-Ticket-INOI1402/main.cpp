#include<bits/stdc++.h>

using namespace std;

int main () {
    size_t cities, edges;
    cin >> cities >> edges;

    vector<pair<uint, uint>> adj_list[cities];
    for (size_t i = 0; i < edges; i++) {
        uint a, b, weight;
        cin >> a >> b >> weight;
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
    for (size_t i = 0; i < cities; i++) {
        unvisited.push({0, i});
        fill_n(distance, cities, INT_MAX);
        distance[i] = 0;
        //fill_n (visited, cities, false);

        while (!unvisited.empty()) {
            int node = unvisited.top().second; unvisited.pop(); //visited[node] = true;

            for (size_t j = 0; j < adj_list[i].size(); j++) {
                if (distance[node] + adj_list[node][j].first < distance[j]) {
                    distance[j] = distance[node] + adj_list[node][j].first;

                    ans = max (distance[j], ans);
                    unvisited.push({distance[j], adj_list[i][j].second});
                }
            }
        }
    }

    cout << ans << endl;
}