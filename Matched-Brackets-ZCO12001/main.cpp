#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
void visualise_brackets (int* brackets, size_t n) {
    for (uint i = 0; i < n; i++) {
        if (brackets[i] == 1) cout << "( ";
        else cout << ") ";
    }
    cout << endl;
}
#endif

int main () {
    uint n;
    cin >> n;

    uint nesting_depth = 0,
    max_nesting_depth_start = 0,
    max_nesting_depth = 0,
    symbol_num = 0,
    symbol_num_start = 0,
    max_symbol_num = 0,
    max_symbol_num_start = 0;

    int in;
    uint count = 0;

    #ifndef DEBUG
    while (cin >> in) {
    #endif
    #ifdef DEBUG
    int brackets[n];
    for (uint i = 0; i < n; i++) {
        cin >> brackets[i];
        in = brackets[i];
        visualise_brackets(brackets, i);
    #endif
        symbol_num++;
        count++;

        if (in == 1) {
            if (nesting_depth == 0) {
                symbol_num_start = count;
            }

            // update nesting depth
            nesting_depth++;
            if (nesting_depth > max_nesting_depth) {
                #ifdef DEBUG
                printf ("Updating max nesting depth to: %d, encountered at %d\n", nesting_depth, count);
                #endif
                max_nesting_depth = nesting_depth;
                max_nesting_depth_start = count;
            }
        } else {
            nesting_depth--;
            if (nesting_depth == 0) {
                if (symbol_num > max_symbol_num) {
                    #ifdef DEBUG
                    printf("Updating max symbol num to %d, encountered at %d\n", symbol_num, count);
                    #endif
                    max_symbol_num = symbol_num;
                    max_symbol_num_start = symbol_num_start;
                }
                symbol_num = 0;
            }
        }
    }
    printf ("%d %d %d %d\n", max_nesting_depth, max_nesting_depth_start, max_symbol_num, max_symbol_num_start);
}