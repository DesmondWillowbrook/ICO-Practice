#include<bits/stdc++.h>

using namespace std;

void bitset_impl(int n) {
    cout << "Bitset impl.: ";
    bitset<sizeof(int) * 8> b = n;
    for (int i = 0; i < log2(n) + 1; i++) {
        cout << b[i];
    }
    cout << endl;
}

void bin_impl(int n) {
    cout << "Bin impl.: ";
    for(int i = 0; i < log2(n) + 1; i++) {
        // here 1 is our mask.
        // to check ith bit of n, we make shift 1 i times and then &.
        // Eg. i = 1, n = 1011: 0010 & 1011 will be 0 if ith bit of n is 0.
        if( ((1<<i) & n) == 0) { // ((1<<i) & n) will yield 0 if ith bit in n is 0
            cout << "0";
        } else {
            cout << "1";
        }
    }
    cout << endl;
}

void arithmatic_impl(int n) {
    cout << "Arithmatic impl.: ";
    stack<bool> result;
    while (n > 0) {
        result.push(n % 2);
        n /= 2;
    }
    
    while(!result.empty()) {
        cout << result.top();
        result.pop();
    }
    cout << endl;
}

int main() {
    uint n;
    cin >> n;

    bitset_impl(n);
    bin_impl(n);
    arithmatic_impl(n);
}