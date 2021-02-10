#include <bits/stdc++.h>

using namespace std;

int main () {
    // DP: f(N) = f(N - 1) + f(N - 2)
    // base case: f(1) = 1, f(2) = 2
    // i.e. Fibonacci series!!! :) :o

    size_t N, curr = 1, prev = 0; cin >> N;
    
    for (size_t i = 0; i < N; i++) {
        #ifdef DEBUG
        cout << prev << " ";
        #endif
        size_t tmp_curr = curr;
        curr = (curr % 15746) + (prev % 15746);
        prev = tmp_curr;
    }
    #ifdef DEBUG
    cout << endl;
    #endif

    cout << (curr % 15746) << endl;
}