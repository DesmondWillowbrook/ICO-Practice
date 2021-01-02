#include <bits/stdc++.h>

using namespace std;

void print_vec (vector<int>& arr) {
    for (auto t = --arr.end();
         t != --arr.begin();
         cout << *(t--));
    cout << "\n";
}

bool add (vector<int>& arr, int base) {
    arr[0]++;
    for (uint i = 0; i < arr.size() - 1; i++) {
        if (arr[i] > base) {
            arr[i] = 0;
            arr[i + 1]++;
        }
    }

    if (*(--arr.end()) > base) {return false;}

    print_vec(arr);

    return true;
}

/// Program to find total number of permutations of 3 numbers,
/// each of which belong to {0, 1, 2}
int main() {
    int number = 0;
    vector<int> arr {0, 0, 0};

    while (add(arr, 2)) {number++;}
} 