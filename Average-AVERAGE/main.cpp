#include<bits/stdc++.h>

using namespace std;

size_t N;

int find_avgs_in_arr (uint* num, uint* start, uint* end) {
    // given a target average, form as many pairs
    // of elements that average to the given element.
    // return number

    uint *small = start, *big = end - 1;

    #ifdef DEBUG
    printf ("find_avgs_in_arr: %d (%ld)\n", *num, num - start);
    #endif

    while (big > small) {
        #ifdef DEBUG
        printf ("Small: %ld, Big: %ld\n", small - start, big - start);
        #endif
        
        if (*big + *small > 2 * (*num))
            big--;
        else if (*big + *small == 2 * (*num))
            return 1;
        else
            small++;
    }
    return 0;
    
}

int main () {
    cin >> N;

    uint arr[N], ans = 0;
    for (size_t i = 0; i < N; i++) cin >> arr[i];

    sort (arr, arr + N);

    for (auto i = arr; i != arr + N; i++) {
        ans += find_avgs_in_arr(i, arr, arr + N);
    }

    cout << ans << endl;
}