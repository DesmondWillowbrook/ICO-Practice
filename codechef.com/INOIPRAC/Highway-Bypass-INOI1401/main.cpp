/*
Solution using graph cutting
*/

#include<bits/stdc++.h>

using namespace std;

size_t R, C, d;
const size_t MAX_L = 301;
const uint MOD = 20011;

int grid [MAX_L][MAX_L];

uint path_num (int r, int c) {
    if (r < 0 || c < 0) return 0;
    if (grid[r][c] != INT_MAX) return grid[r][c];

    return grid[r][c] = (path_num (r - 1, c) + path_num (r, c - 1) - path_num (r - d - 1, c) - path_num (r, c - d - 1) + 5*MOD) % MOD;
}

int main () {
    cin >> R >> C >> d;

    for (size_t r = 0; r < R; r++) 
        for (size_t c = 0; c < C; c++) {
            uint in; cin >> in;
            if (in == 0) grid[r][c] = 0;
            else grid[r][c] = INT_MAX;
        }

    grid[0][0] = 1;
    cout << path_num (R - 1, C - 1) << endl;
}