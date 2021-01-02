#include <bits/stdc++.h>

using namespace std;

uint pointsVisited = 0;
uint n;
uint ans = 0;
bool* arr;

#ifdef STEP
char next_step;
#endif

uint get_index(uint x, uint y) {
    return n*y + x;
}

#ifdef DEBUG
void visualize_array (uint x, uint y) {
    cout << "At " << x << ", " << y << " (visited: " << blocksVisited << ")" "\n";
    for (uint i = 0; i < n; i++) {
        for (uint j = 0; j < n; j++) {
            if (i == x && j == y) {
                cout << "X ";
            } else if (arr[get_index(i, j)]) {
                cout << ". ";
            } else {
                cout << "O ";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}
#endif

/*
// Checks if particular path can no longer visit all squares
// i.e. if it is touching a wall and both sides are unexplored
// (when it can either turn right or left, it is dead)
bool check_if_dead (uint x, uint y) {
    if (
        ((0 < x) && (x < n - 1)) && (y == n - 1 || y == 0) &&
        // check if both indexes are unexplored (i.e. false)
        (!arr[get_index(x - 1, y)] && !arr[get_index(x + 1, y)])
    ) {
        return true;
    }

    if (
        ((0 < y) && (y < n - 1)) && (x == n - 1 || x == 0) &&
        (!arr[get_index(x, y + 1)] && !arr[get_index(x, y - 1)])
    ) {
        return true;
    }

    return false;
}
*/
void explore (uint x, uint y) {

    if ((x == y) && (x == 0)) {
        if (pointsVisited == n*n) {
            ans++;
        }
        // Terminate if we reach end square too early
        else {
            return;
        }
    }

    // if current cell has already been visited
    if (arr[get_index(x, y)]) {
        return;
    }

    arr[get_index(x, y)] = true;
    pointsVisited++;

    #ifdef DEBUG
    visualize_array(x, y);
    #ifdef STEP
    cin >> next_step;
    #endif
    #endif

    //if (!check_if_dead(x, y)) {
        if (x < n - 2) {
            if (y < n - 1) {
                explore(x + 2, y + 1);
            }
            if (y > 0) {
                explore(x + 2, y - 1);
            }
        }
        
        if (x > 1) {
            if (y < n - 1) {
                explore(x - 2, y + 1);
            }
            if (y > 0) {
                explore(x - 2, y - 1);
            }
        }

        if (y < n - 2) {
            if (x < n - 1) {
                explore(x + 1, y + 2);
            }
            if (x > 0) {
                explore(x - 1, y + 2);
            }
        }

        if (y > 1) {
            if (x < n - 1) {
                explore(x + 1, y - 2);
            }
            if (x > 0) {
                explore(x - 1, y - 2);
            }
        }
    //}

    pointsVisited--;
    arr[get_index(x, y)] = false;
}

int main () {
    cin >> n;
    arr = new bool[n*n] {false};
    // So func immediately doesn't return
    // (since it returns if all blocks haven't been reached and is at 0, 0)

    if (n > 2) {
        explore(2, 1);
        explore(1, 2);
    }
    cout << ans << endl;
}