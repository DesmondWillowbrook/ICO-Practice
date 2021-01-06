#include <bits/stdc++.h>

using namespace std;

int main () {
    size_t n;
    cin >> n;
    
    // index 0 repr. subseq. with lowest ending element of length 1
    // and so on...
    uint las[n] = {1}; //set first element 1, since that's the max. length of a subseq. ending at the 0th element
    uint m[n] = {UINT_MAX}; // smallest ending element per 
    int arr[n];

    for (size_t i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (size_t i = 1; i < n; i++) {

        uint max_las_len = 0;
        for (size_t j = 0; j < i; j++) {
            if (arr[j] <= arr[i]) {
                max_las_len = max(max_las_len, las[j]);
            }
        }
        las[i] = 1 + max_las_len;
    }

    cout << las[n - 1] << endl;
}