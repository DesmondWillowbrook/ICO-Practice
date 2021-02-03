#include<bits/stdc++.h>

using namespace std;

size_t R, C, d;

bool grid[300][300];

/* represents states:
   [x][y][len][dir]

   Paths at point x, y where path was len long in the direction dir
   0 -> right, 1 -> down
*/
int dp[300][300][300][2] = {0};

int paths (int r, int c, int len, int dir) {
    if (r < 0 || c < 0) return 0;
    if (dp[r][c][len][dir] != 0) return grid[r][c];

    uint ans = 0;
    if (len > 0) dp[r][c][len][dir] = paths(r, c, len - 1, dir);
    else dp[r][c][len][dir] = paths (r - 1, c, 0, 0) + paths (r, c - 1, 0, 1);
}

int main () {
    cin >> R >> C >> d;

    for (size_t i = 0; i < R; i++)
        for (size_t j = 0; j < C; j++) {
            int tmp; cin >> tmp;
            if (tmp == 0) grid[i][j] = false;
            else grid[i][j] = true;
        }
}