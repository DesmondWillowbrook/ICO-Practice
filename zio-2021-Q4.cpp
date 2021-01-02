#include <bits/stdc++.h>

using namespace std;

uint steps = 0;
uint k;
uint x;

uint calc_next(uint y) {
    steps += (y % k) + 1; // (Number of times we subtract 1) + 1 division by k
    return ((y + (y % k)) / k);
}

void stepsTo (uint y) {
    cout << "stepsTo(" << y << ")\n";
    
    y = calc_next(y);
    if (y <= x) { // If next multiple of k < x, subtract to get y & abort.
        steps += x - y;
        return;
    }
    else {
        cout << steps << "\n";
        return stepsTo(y);
    }
}

int main() {
    uint y;
    cin >> x >> y >> k;
    stepsTo(y);
    cout << steps << endl;
}

/*
Implementing this has made me realize how this can be solved in linear time:
We want to find out total number of steps =
    Steps required to get y below x by dividing by k

Each time we nudge y to closest multiple of k until y is less than x...
Is there a better formula to find the closest multiple of k?

Q: (((y + y mod k) / k) + ((y + y mod k) / k) mod k) + ...
Looks like modulo arithmetic...Can we get a mod outside?
Q:
*/