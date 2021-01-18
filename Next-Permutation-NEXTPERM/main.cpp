#include<bits/stdc++.h>

using namespace std;

int main () {
    size_t N, K;
    cin >> N >> K;

    uint nums [N];
    while (K--) {
        for (size_t i = 0; i < N; i++) cin >> nums[i];
        next_permutation(nums, nums + N);
        for (size_t i = 0; i < N; i++) cout << nums[i] << " ";
        cout << endl;
    }
}