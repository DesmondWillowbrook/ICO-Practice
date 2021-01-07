#include <bits/stdc++.h>

using namespace std;

size_t N;
size_t M;
int grid[500][500];
int sol[500][500];
bool safe[500][500];
bool is_there_a_safe_path = false;

#ifdef DEBUG
void print_charms () {
    cout << endl;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            if (safe[i][j] == true) cout << "S ";
            else cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

void print_path (uint x, uint y) {
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            if (!safe[i][j]) {cout << " . "; continue;}
            if (grid[i][j] >= 0) cout << " ";
            if (i == x && j == y) cout << "\033[1m" << grid[i][j] << "\033[0m";
            else cout << grid[i][j];
            cout << " ";
        }
        cout << "\t";
        for (size_t j = 0; j < N; j++) {
            if (!safe[i][j] || sol[i][j] == -INT_MAX) {cout << " . "; continue;}
            if (sol[i][j] >= 0) cout << " ";
            if (i == x && j == y) cout << "\033[1m" << sol[i][j] << "\033[0m";
            else cout << sol[i][j];
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}
#endif

void mark_charm (uint x, uint y, int strength) {
    if (strength < 0) return;

    safe[x][y] = true;

    if (x > 0) mark_charm (x - 1, y, strength - 1);
    if (x < N - 1) mark_charm (x + 1, y, strength - 1);
    if (y > 0) mark_charm (x, y - 1, strength - 1);
    if (y < N - 1) mark_charm (x, y + 1, strength - 1);
}

int max_score (uint x, uint y) {
    if (!safe[x][y]) return -INT_MAX;

    if (x == 0 && y == 0) return grid[0][0];
    if (sol[x][y] != -INT_MAX) return sol[x][y];

    #ifdef DEBUG
    print_path (x, y);
    #endif

    int ans = -INT_MAX;
    if (x > 0 && x < N) {
        int tmp = max_score (x - 1, y);
        if (tmp != -INT_MAX) ans = max(ans, tmp + grid[x][y]);
    }
    if (y > 0 && y < N) {
        int tmp = max_score (x, y - 1);
        if (tmp != -INT_MAX) ans = max(ans, tmp + grid[x][y]);
    }

    sol[x][y] = ans;
    return sol[x][y];
}

int main () {
    cin >> N >> M;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            cin >> grid[i][j];
            sol[i][j] = -INT_MAX;
        }
    }

    uint charm_x, charm_y, charm_str;
    for (size_t i = 0; i < M; i++) {
        cin >> charm_x >> charm_y >> charm_str;
        // move from 1-based to 0-based indexing
        mark_charm (charm_x - 1, charm_y - 1, charm_str);
        #ifdef DEBUG
        print_charms ();
        #endif
    }

    int ans = max_score(N - 1, N - 1);
    if (ans == -INT_MAX) cout << "NO" << endl;
    else {
        cout << "YES" << endl << ans << endl;
    }
}