#include <bits/stdc++.h>

using namespace std;

uint pointsVisited = 0;
uint n;
uint ans = 0;
bool* arr;

uint get_index(uint x, uint y) {
    return n*y + x;
}

#ifdef DEBUG
void visualize_array (uint x, uint y) {
    printf("At (%d, %d), visited %d points\n", x, y, pointsVisited);
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
    //cout << "\n";
}
#endif

// Return number of explored adj. points in the x-axis
uint adj_unexplored_x (uint x, uint y) {
    uint ans = 0;
    if (x == 0 || arr[get_index(x + 1, y)]) {
        ans++;
    }
    if (x == n - 1 || arr[get_index(x - 1, y)]) {
        ans++;
    }
    return ans;
}

// Return number of explored adj. points in the y-axis
uint adj_unexplored_y (uint x, uint y) {
    uint ans = 0;
    if (y == 0 || arr[get_index(x, y - 1)]) {
        ans++;
    }
    if (y == n - 1 || arr[get_index(x, y + 1)]) {
        ans++;
    }
    return ans;
}

// Checks if path can no longer visit all squares
// i.e. if it is touching a wall and both sides are unexplored
// (when it can either turn right or left, it is dead)
bool check_if_dead (uint x, uint y) {
    #ifdef DEBUG 
    printf("Is dead: %d\n\n", ((adj_unexplored_y(x, y) == 2 && adj_unexplored_x(x, y) == 0)
        || (adj_unexplored_y(x, y) == 0 && adj_unexplored_x(x, y) == 2)));
    #endif
    return ((adj_unexplored_y(x, y) == 2 && adj_unexplored_x(x, y) == 0)
        || (adj_unexplored_y(x, y) == 0 && adj_unexplored_x(x, y) == 2));
}

void explore (uint x, uint y) {

    if ((x == y) && (x == n-1)) {
        if (pointsVisited + 1 == n*n) {
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
    #endif

    if (!check_if_dead(x, y)) {
        if (x < n - 1) {
            explore(x + 1, y);
        }
        
        if (0 < x) {
            explore(x - 1, y);
        }

        if (0 < y) {
            explore(x, y - 1);
        }

        if (y < n - 1) {
            explore(x, y + 1);
        }
    }

    pointsVisited--;
    arr[get_index(x, y)] = false;
}

int main () {
    cin >> n;
    arr = new bool[n*n] {false};

    pointsVisited++;
    arr[0] = true;

    explore(1, 0);
    cout << ans*2 << endl;
}