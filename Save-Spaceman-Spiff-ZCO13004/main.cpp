#include <bits/stdc++.h>

using namespace std;

int N, M, K;

// really didn't want to do this, but C++ has problems accessing **int pointers as two-dimensional arrays
int ind (int x, int y) {
    return N*x + y;
}

#ifdef DEBUG
// blaster co-ords, spiff co-ords
void blaster_visualisation (int* grid, int x, int y) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == x && j == y) cout << "B ";
            else if (grid[ind(i, j)] == -1) cout << ". ";
            else cout << "O ";
        }
        cout << endl;
    }
    cout << endl;
}
#endif

#ifdef DEBUG
void spiff_visualisation (int* grid, int x, int y) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == x && j == y) cout << "S ";
            else if (grid[ind(i, j)] == -INT_MAX) cout << "? ";
            else if (grid[ind(i, j)] == -1) cout << ". ";
            else cout << "O ";
        }
        cout << endl;
    }
    cout << endl;
}
#endif

int get_manhatten_distance (int x, int y) {
    return x + y; //account for the turn
}

// computes if it is possible to reach this point.
// -1 => False, unreachable
// -INT_MAX => Not computed 
// 1 => Reachable
bool possible (int* grid, int x, int y) {
    if (x == 0 && y == 0) return true;
    else if (x < 0 || y < 0) return false;

    // check if already computed
    if (grid[ind(x, y)] != -INT_MAX) return grid[ind(x, y)];

    if (possible (grid, x - 1, y) && grid[ind(x, y)] != -1) grid[ind(x, y)] = 1;
    else if (possible (grid, x, y - 1) && grid[ind(x, y)] != -1)  grid[ind(x, y)] = 1;
    
    #ifdef DEBUG
    spiff_visualisation(grid, x, y);
    #endif

    // if none of the above were true, then this cell is unreachable
    if (grid[ind(x, y)] == -INT_MAX) grid[ind(x, y)] = -1;

    if (grid[ind(x, y)] == 1) return false;
    else return false;
}

int main () {
    cin >> N >> M >> K;
    
    int grid[N * M];
    fill_n (grid, N * M, -INT_MAX);

    // for blaster input
    int x, y, t, f;
    for (int i = 0; i < K; i++) {
        cin >> x >> y >> t >> f;
        x--; y--; // adjust for zero-based indexing
        grid[ind(x, y)] = -1;
        // check both axes for collision with spiff
        for (int j = 0; j < N; j++) {
            // check if start time + offset coincides with time spiff is there
            // or if the difference b/w start time and Spiff's arrival time is a multiple of the firing frequency
            #ifdef DEBUG
            printf ("Spiff time: %d for coords (%d, %d), blaster start: %d, blaster freq.: %d\n", get_manhatten_distance (x, j), x, j, t, f);
            printf ("Spiff time: %d for coords (%d, %d), blaster start: %d, blaster freq.: %d\n", get_manhatten_distance (j, y), j, y, t, f);
            #endif
            if ((get_manhatten_distance (x, j) - max(t - j, 0) % f == 0) ||
                (get_manhatten_distance (x, j) - min(t + j, N - 1) % f == 0)) grid[ind(x, j)] = -1;
            else grid[ind(x, j)] = 1;
            if ((get_manhatten_distance (j, y) - max(t - j, 0)) % f == 0 ||
                (get_manhatten_distance (j, y) - min(t + j, N - 1) % f == 0)) grid[ind(j, y)] = -1;
            else grid[ind(j, y)] = 1;
            #ifdef DEBUG
            blaster_visualisation (grid, x, y);
            #endif
        }
    }

    #ifdef DEBUG
    grid[0] = true; // for clarity of debug prints, this should be known
    #endif

    if (possible(grid, N - 1, M - 1)) cout << "YES\n" << get_manhatten_distance (N, M) << endl;
    else cout << "NO\n";
}