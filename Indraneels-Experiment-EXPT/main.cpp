/*
* Problem is to find successive differences
* Then find common substring and print the numbers asssociated with them.
* => 2(N^2) memory usage (as difference changes based on which numbers are selected)
* O(N^2) for calculating successive differences
* O(N^2) for finding longest common subsequence
* (There is algorithm for finding it in O N log N time, but DP sol should suffice)
*/

#include<bits/stdc++.h>

using namespace std;

size_t N;

#ifdef DEBUG
const uint space_len = 4;

template <typename T>
T uniform_spacing_print (T n) {
    for (int len = space_len - to_string(n).length(); len > 0; len--) cout << " ";
    return n;
}
#endif

int main () {
    cin >> N;
    int seq_a[N], seq_b[N];
    for (size_t i = 0; i < N; i++) cin >> seq_a[i];
    for (size_t i = 0; i < N; i++) cin >> seq_b[i];

    // difference when previous element is index i and curr. element is j
    // we can optimize memory usage based on the fact that we are only concerned with cases
    // where i < j, i.e. for the last element there is no further element for which
    // successive difference will have to be calculated.
    // however, that is left as an exercise to the reader.

    int diff_a[N][N], diff_b[N][N];
    for (size_t i = 0; i < N; i++) {
        for (size_t j = i + 1; j < N; j++) {
            diff_a[i][j] = abs(seq_a[j] - seq_a[i]);
            diff_b[i][j] = abs(seq_a[j] - seq_a[i]);
        }
    }

    // we now have both arrays from which we have to find longest common subsequence
    size_t lcsubseq[N + 1][N + 1]; // store longest common subsequence starting from diff_a[i], and diff_b[j]

    //https://youtu.be/xdA41xLxwuM?t=1333

    // building inductive structure

    for (size_t i = 0; i <= N; i++) lcsubseq[i][N] = 0;
    for (size_t i = 0; i <= N; i++) lcsubseq[N][i] = 0;

    for (long int i = N - 1; i >= 0; i--) {
        for (long int j = N - 1; j >= 0; j--) {
            if (diff_a[i][j] == diff_b[i][j])
            {
                #ifdef DEBUG
                printf ("%d (%ld) - %d (%ld) == %d (%ld) - %d (%ld)\n", seq_a[j], j, seq_a[i], i, seq_b[j], j, seq_b[i], i);
                #endif
                lcsubseq[i][j] = 1 + lcsubseq[i + 1][j + 1];
            }
        }
    }

    #ifdef DEBUG
    cout << "      ";
    for (size_t i = 0; i < N; i++) cout << uniform_spacing_print(seq_b[i]);
    cout << endl;

    for (size_t i = 0; i < N; i++) {
        printf ("%d |", uniform_spacing_print(seq_a[i]));
        for (size_t j = 0; j <= N; j++) {
            cout << uniform_spacing_print(lcsubseq[i][j]);
        }
        cout << endl;
    }

    cout << "     |";
    for (size_t j = 0; j <= N; j++) cout << uniform_spacing_print(lcsubseq[N][j]);
    cout << endl;
    #endif

    // length of longest common subseq
    cout << lcsubseq[0][0] << endl;
    int sub_a[lcsubseq[0][0]], sub_b[lcsubseq[0][0]];

    // to find the numbers
    size_t x = 0, y = 0, ind = 0;
    while (x <= N && y <= N) {
        if (lcsubseq[x][y] - 1 == lcsubseq[x + 1][y + 1]) {
            sub_a[ind] = seq_a[x]; sub_b[ind] = seq_b[y];
            x++; y++; ind++;
        } else {
           if (lcsubseq[x][y + 1] > lcsubseq[x + 1][y]) y++;
           else x++;
        }
    }

    for (size_t i = 0; i < lcsubseq[0][0]; i++) cout << sub_a[i] << " ";
    cout << endl;
    for (size_t i = 0; i < lcsubseq[0][0]; i++) cout << sub_b[i] << " ";
}