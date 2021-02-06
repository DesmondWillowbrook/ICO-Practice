#include<bits/stdc++.h>

using namespace std;

uint dist[230][230];

#ifdef DEBUG
int via[230][230];

void print_path (uint i, uint j) {
    if (i == j) return;

    if (via[i][j] == -1) { // i.e. if they are neighbours
        printf ("%d -> %d, ", i + 1, j + 1);
    } else {
        print_path (i, via[i][j]);
        print_path (via[i][j], j);
    }
}
#endif

int main () {
    size_t cities, edges;
    cin >> cities >> edges;

    for (size_t i = 0; i < cities; i++)
        for (size_t j = 0; j < cities; j++)
            if (i != j) dist[i][j] = UINT_MAX;
            else dist[i][j] = 0;

    for (size_t i = 0; i < edges; i++) {
        uint a, b, weight;
        cin >> a >> b >> weight; a--; b--; // move to zero-based indexing

        dist[a][b] = weight; dist[b][a] = weight;
        #ifdef DEBUG
        via[a][b] = -1; via[b][a] = -1;
        #endif
    }

    // use Floyd-Warshall
    for (size_t i = 0; i < cities; i++)
        for (size_t j = 0; j < cities; j++) {
            for (size_t k = 0; k < cities; k++) {
                if (dist[i][k] == UINT_MAX || dist[k][j] == UINT_MAX) continue;
                dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);

                #ifdef DEBUG
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    via[i][j] = k; via[j][i] = k;
                }
                #endif
            }
        }

    #ifdef DEBUG
    pair<uint, uint> final_path;
    #endif

    uint ans = 0;
    for (size_t i = 0; i < cities; i++)
        for (size_t j = 0; j < cities; j++) {
            if (ans < dist[i][j]) {
                ans = dist[i][j];
                #ifdef DEBUG
                final_path.first = i; final_path.second = j;
                #endif
            }
        }

    #ifdef DEBUG
    print_path (final_path.first, final_path.second);
    cout << "\n";
    #endif

    cout << ans << endl;
}