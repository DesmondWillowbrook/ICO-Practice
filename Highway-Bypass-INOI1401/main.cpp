#include<bits/stdc++.h>

using namespace std;

size_t R, C, d;

int grid[300][300];

// straight > 0 => down direction
// straight < 0 => right direction

int paths (size_t r, size_t c, int straight) {
    if (grid[r][c] != -1) return grid[r][c];

    uint ans = 0;
    if (abs(straight) < d) {
        if (straight > 0) ans += paths (r, c - 1, straight + 1);
        if (straight < 0) ans += paths (r - 1, c, straight - 1);
    }
}

int main () {
    cin >> R >> C >> d;

    for (size_t i = 0; i < R; i++)
        for (size_t j = 0; j < C; j++) {
            int tmp; cin >> tmp;
            if (tmp == 0) grid[i][j] = 0;
            else grid[i][j] = -1;
        }
}