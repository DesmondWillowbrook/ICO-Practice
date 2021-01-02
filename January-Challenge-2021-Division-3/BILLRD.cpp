#include<bits/stdc++.h>

using namespace std;

// direction: +1 if anti-clockwise, -1 if clockwise
void l_sim (uint& x, uint& y, uint n) {
    swap(x, y);
}

void r_sim (uint& x, uint& y, uint n) {
    uint tmp = n - y;
    y = n - x; 
    x = tmp;
}

bool normalised (uint& x, uint& y, uint n) {
    if (x == 0 || y == 0 || x == n || y == n) {
        return true;
    }
    return false;
}

// Find 1st collision point
int normalize (uint& x, uint& y, uint n) {
    if (!normalised(x, y, n)){
        if (x > y) {
        y = n - y; //steps required for x to get to n
        x = n;
        return 1;
        } else {
            x = n - x;
            y = n;
            return -1;
        }
    }
    
}

int main() {
    uint t, n, k, x, y;
    cin >> t;
    while (t--) {
        cin >> n >> k >> x >> y;

        // case of ball in a corner
        if (x == y) {
            printf("%d %d\n", n, n);
            continue;
        }

        // k modulo 4 is the actual number we need to simulate,
        // as after 4th collision, ball loops to 1st point of collision.
        k %= 4;
        
        if (normalize(x, y, n) == 1) {

        }
    }
}