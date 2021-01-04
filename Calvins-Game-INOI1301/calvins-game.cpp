/// https://www.codechef.com/INOIPRAC/problems/INOI1301

#include<bits/stdc++.h>

using namespace std;
#define forn(name, start, end) for (size_t name = start; i < end; i++)

#ifdef DEBUG
void visualise_arr (int* arr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
#endif

int A[(size_t) 10e6 + 1];
int FW[(size_t) 10e6 + 1];
int BW[(size_t) 10e6 + 1];

uint N, K;

// computes highest score path from K to n
int Forward (int n) {
    if (n < K)
        return -INT_MAX;

    if (n == K)
        return FW[n] = 0; // base case
    
    if (FW[n] != -INT_MAX)
        return FW[n];
    
    FW[n] = A[n] + max(Forward(n - 1), Forward(n - 2));
    return FW[n];
}

int Backward (int n) {
    if (n < 1)
        return -INT_MAX;

    if (n == 1)
        return BW[1] = A[1]; // base case
    
    if (BW[n] != -INT_MAX)
        return BW[n];
    
    BW[n] = A[n] + max(Backward(n - 1), Backward(n - 2));
    return BW[n];
}

int main() {
    cin >> N >> K;
    K--;

    fill_n(FW, N, -INT_MAX);
    fill_n(BW, N, -INT_MAX);

    forn(i, 0, N) {
        cin >> A[i];
    }

    Forward(N - 1);
    Backward(N - 1);

    // find with path with highest end value
    int highest = -INT_MAX;
    forn(i, K, N) {
        highest = max(highest, FW[i] - A[i] + BW[i]);
    }

    cout << highest << endl;
}