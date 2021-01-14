#include<bits/stdc++.h>

using namespace std;

size_t N;

#ifdef DEBUG
void print_arr (pair<uint, uint>* arr, pair<uint, uint> bounds) {
    printf ("bounds: (%d, %d)\n", bounds.first, bounds.second);
    for (size_t i = 0; i < N; i++) {
        printf ("(%d, %d)\n", arr[i].first, arr[i].second);
    }
}
#endif

uint calc_size (uint x_start, uint x_end, uint y) {
    return (x_end - x_start) * y;
}

int find_end (pair<uint, uint>* arr, size_t ind) {
    size_t ans = ind;
    
    // add answer until y of answer is less than of y of point.
    // since that is the point we cannot continue a rectangle anymore
    for (; ans < N*2 + 1 && arr[ans].second >= arr[ind].second; ans++);
   
    #ifdef DEBUG
    printf ("Found end of (%d, %d) to be: (%d, %d) (ans: %ld)\n", arr[ind].first, arr[ind].second, arr[ans].first, arr[ans].second, ans);
    #endif
    
    return ans;
}

int find_start (pair<uint, uint>* arr, int ind) {
    int ans = ind;
    
    // add answer until y of answer is less than of y of point.
    // since that is the point we cannot continue a rectangle anymore
    for (; ans > 0 && arr[ans].second >= arr[ind].second; ans--);
    
    #ifdef DEBUG
    printf ("Found start of (%d, %d) to be: (%d, %d) (ans: %d)\n", arr[ind].first, arr[ind].second, arr[ans].first, arr[ans].second, ans);
    #endif
    
    return ans;
}

int main () {
    cin >> N;

    pair<uint, uint> a[N*2 + 2];
    for (size_t i = 1; i < 2*N; i += 2) {cin >> a[i].first >> a[i].second; a[i + 1] = {a[i].first, 500};}
    a[0] = {0, 500};
    a[N*2 + 1] = {100000, 500};
    sort (a + 1, a + N*2 + 1);

    // (1, 3), (1, 5), (2, 1), ...
    uint ans = 0;

    for (size_t i = 0; i < N*2 + 2; i++) {
        uint start = a[find_start(a, i)].first;
        uint end = a[find_end(a, i)].first;
        ans = max(ans, calc_size(start, end, a[i].second));
    }

    cout << ans << endl;
}