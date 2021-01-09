#include <bits/stdc++.h>

using namespace std;

size_t N;

#ifdef DEBUG
void vis_arr (int arr[], int* i1, int* i2) {
    for (size_t i = 0; i < N; i++) {
        if (arr + i == i1 || arr + i == i2) cout << "\033[1m" << arr[i] << "\033[0m ";
        else cout << arr[i] << " ";
    }
    cout << endl;
}
#endif

int find_palin_len (int arr[], int i) {
    pair <int*, int*> ans (arr + i, arr + i);
    while (ans.first >= arr && ans.second < arr + N) {
        if (*ans.first != *ans.second) break;
        #ifdef DEBUG
        vis_arr (arr, ans.first, ans.second);
        #endif
        ans.first--; ans.second++;
    }
    return ans.second - ans.first;
}

void search_palin (int arr[], int i) {

}

int main () {
    cin >> N;
    int arr[N];
    for (size_t i = 0; i < N; i++) cin >> arr[i];

    uint ans = 0;
    uint palin_len = 0;
    
    int sol[N];

    for (size_t i = 0; i < N;) {
        palin_len = find_palin_len(arr, i);
        i += palin_len/2 + 1;
        ans += 1;
    }

    cout << ans << endl;
}