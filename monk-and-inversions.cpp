/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

#include<bits/stdc++.h>

using namespace std;

// Write your code here
int main() {
    uint t;
    cin >> t;

    while (t--) {
        size_t n;
        cin >> n;
        uint grid[n][n];
        uint ans = 0;

        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                for (size_t k = i; k < n; k++) {
                    for (size_t l = j; l < n; l++) {
                        fprintf(stderr, "grid[%ld][%ld] > grid[%ld][%ld]?\n", i, j, k, l);
                        if (grid[i][j] > grid[k][l]) {
                            ans++;
                        }
                    }
                }
            }
        }

        cout << ans << endl;
    }
}