#include<bits/stdc++.h>

using namespace std;

uint dist[230][230];

int main () {
    size_t cities, edges;
    cin >> cities >> edges;

    for (size_t i = 0; i < cities; i++)
        for (size_t j = 0; j < cities; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INT_MAX;
        }

    for (size_t i = 0; i < edges; i++) {
        uint a, b, weight;
        cin >> a >> b >> weight; a--; b--; // move to zero-based indexing

        dist[a][b] = weight; dist[b][a] = weight;
    }

    // use Floyd-Warshall
    for (size_t k = 0; k < cities; k++)
        for (size_t i = 0; i < cities; i++) {
            for (size_t j = 0; j < cities; j++) {
                dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);
            }
        }

    uint ans = 0;
    for (size_t i = 0; i < cities; i++)
        for (size_t j = 0; j < cities; j++) {
            ans = max(ans, dist[i][j]);
        }

    cout << ans << endl;
}