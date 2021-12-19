#include <bits/stdc++.h>

using namespace std;

size_t N, M;
int grid[500][500];
int sol[500][500];
bool safe[500][500];

#ifdef DEBUG
int max_digit_score = 0;

void uniform_print_num (int num, int max_digit_num, bool highlight) {
    if (num != -INT_MAX) {
        for (int i = log10(abs(num)); i < max_digit_num; i++) cout << " ";
        if (num > 0) cout << " "; // add space to substitute for '-' sign

        if (highlight) cout << "\033[1m";
        cout << num;
        if (highlight) cout << "\033[0m";
    }
    else {
        for (int i = 0; i < max_digit_num; i++) cout << " ";
        cout << " .";
    }
    cout << " ";
}
void print_charm (uint x, uint y) {
    cout << endl;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            if (i == x && j == y) cout << "C ";
            else if (safe[i][j] == true) cout << "S ";
            else cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

void print_path (uint x, uint y) {
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            if (safe[i][j]) uniform_print_num(grid[i][j], 1, (i == x && j == y));
            else uniform_print_num(-INT_MAX, 1, false);
        }
        cout << "\t";
        for (size_t j = 0; j < N; j++) {
            uniform_print_num(sol[i][j], max_digit_score, false);
        }
        cout << endl;
    }
    cout << endl;
}
#endif

void mark_charm (int x, int y, int k) {
/*  Takes too long:

    if (k < 0) return;

    safe[x][y] = true;

    if (x > 0) if (!safe[x - 1][y]) mark_charm (x - 1, y, k - 1);
    if (x < N - 1) mark_charm (x + 1, y, k - 1);
    if (y > 0) mark_charm (x, y - 1, k - 1);
    if (y < N - 1) mark_charm (x, y + 1, k - 1);
*/

    for (int i = max (0, x - k); i <= min (N - 1, (size_t) x + k); i++) {
        for (int j = max (0, y - k); j <= min (N - 1, (size_t) y + k); j++) {
            if (abs(x - i) + abs(y - j) <= k) {
                safe[i][j] = true;
            }
        }
    }
}

int max_score (uint x, uint y) {
    if (!safe[x][y]) return -INT_MAX;

    // base case
    if (x == 0 && y == 0) return grid[0][0];
    if (sol[x][y] != -INT_MAX) return sol[x][y];

    int ans = -INT_MAX;
    if (x > 0) {
        int tmp = max_score (x - 1, y);
        if (tmp != -INT_MAX) ans = max(ans, tmp + grid[x][y]);
    }
    if (y > 0) {
        int tmp = max_score (x, y - 1);
        if (tmp != -INT_MAX) ans = max(ans, tmp + grid[x][y]);
    }

    sol[x][y] = ans;

    #ifdef DEBUG
    if (ans != -INT_MAX) max_digit_score = max (log10(max_digit_score), log10(abs(ans)));
    print_path (x, y);
    #endif
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
        print_charm (charm_x - 1, charm_y - 1);
        #endif
    }

    #ifdef DEBUG //so sol displays as such in debug grid
    sol[0][0] = grid[0][0];
    #endif
    int ans = max_score(N - 1, N - 1);
    if (ans == -INT_MAX) cout << "NO" << endl;
    else {
        cout << "YES" << endl << ans << endl;
    }
}