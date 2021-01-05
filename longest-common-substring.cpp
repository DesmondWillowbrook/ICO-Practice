#include<bits/stdc++.h>

// time complexity: n * m; where n, m are length of strings
// space complexity: O(1)

using namespace std;

#ifdef DEBUG
void visualise_op(string& a, uint a_i, string& b, uint b_i) {
    cout << a << "\t" << b << endl;
    for (int i = 0; i < a.length(); i++) {
        if (i == a_i) {
            cout << "^";
        } else {
            cout << " ";
        }
    }
    cout << "\t";
    for (int i = 0; i < b.length(); i++) {
        if (i == b_i) {
            cout << "^";
        } else {
            cout << " ";
        }
    }
    cout << endl;
}
#endif

int main() {
    string a;
    string b;

    cin >> a >> b;
    // start of a_i, end of a_i and start of b_i and end of b_i
    pair<pair<uint, uint>, pair<uint, uint>> ans {{0, 0}, {0, 0}};

    int len = 0;
    for (uint a_i = 0; a_i < a.length(); a_i++) {
        for (uint b_i = 0; b_i < b.length(); b_i++) {
            #ifdef DEBUG
            visualise_op(a, a_i, b, b_i);
            #endif
            while (a.at(a_i + len) == b.at(b_i + len)) {
                #ifdef DEBUG
                cout << "Match!" << endl;
                #endif
                len++;
                if (a_i + len >= a.length() || b_i + len >= b.length()) {
                    break;
                }
            }
            // skip comparisons we carry out in while block.
            b_i += len;

            // find length of substring currently stored in ans
            if (ans.first.second - ans.first.first < len) {
                #ifdef DEBUG
                printf("Found longest substring so far! Length is %d\n", len + 1);
                printf ("Saving: a_start = %d\na_end = %d\nb_start = %d\nb_end = %d\n", a_i, a_i + len, b_i, b_i + len);
                #endif
                ans.first.first = a_i;
                ans.first.second = a_i + len;
                ans.second.first = b_i;
                ans.second.second = b_i + len;
            }
            len = 0;
        }
    }

    for (size_t i = ans.first.first; i < ans.first.second; i++) {
        cout << a.at(i);
    }
    cout << endl;
}