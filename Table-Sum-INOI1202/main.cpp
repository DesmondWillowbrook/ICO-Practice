#include<bits/stdc++.h>

using namespace std;

size_t N;

int main () {
    cin >> N;
    uint a[N];

    for (size_t i = 0; i < N; i++) {
        cin >> a[i];
    }

    uint max_ind = N - 1; // tracks INDEX of max. number

    // find initial max. number
    for (long int j = max_ind; j >= 0; j--) {
        if (a[j] + ((j + 0) % N) + 1 > a[max_ind] + ((max_ind + 0) % N) + 1) max_ind = j;
    }

    for (size_t i = 0; i < N; i++) {
        if (((max_ind + i) % N) + 1 == 1) { // max num. ONLY shifts when +N falls to +1

            #ifdef DEBUG
            for (size_t k = 0; k < N; k++) cout << a[k] << "\t";
            cout << endl;
            for (size_t k = 0; k < N; k++) cout << ((k + i) % N) + 1 << "\t";
            cout << endl;
            #endif

            for (long int j = max_ind; j >= 0; j--) {
                if (a[j] + ((j + i) % N) + 1 > a[max_ind] + ((max_ind + i) % N) + 1) max_ind = j;
            }

            #ifdef DEBUG
            for (size_t k = 0; k < max_ind; k++) cout << "\t";
            cout << "|\n\n";
            #endif
        }

        cout << a[max_ind] + ((max_ind + i) % N) + 1 << endl;
    }
}